#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>
using namespace std;

ofstream out("out.txt");
/*
class String // gata
{
    char *sir;
    int size;
public:
    String()
    {
        sir=nullptr;
        size=0;
    }
    String(char v1[])
    {
        int n=0;
        for(int i=0; v1[i]!='\0'; i++)
            n++;
        if (n!=0)
        {
            sir = new char[n+1];
            for(int i=0; i<n; i++)
                sir[i]=v1[i];
            sir[n]=NULL;
            size=n+1;

        }
        else
        {
            size=0;
            sir=nullptr;
        }
    }
    ~String()
    {
        delete [] sir;
        sir=nullptr;
        size=0;
    }
    void clear()
    {
        if(sir != NULL && sir !=nullptr)
            delete [] sir;
    }
    String(const String &v1)
    {
        int n=0,i;
        for(i=0; v1.sir[i]!=NULL; i++)
            n++;
        sir = new char[n+1];
        for(i=0; v1.sir[i]!=NULL; i++)
            sir[i]=v1.sir[i];
        sir[n]=NULL;
        size=n+1;

    }
    void operator =(const String &v1)
    {
        if(sir!=nullptr)
            delete [] sir;
        int n=0,i;
        if (v1.sir==nullptr)
        {
            sir=nullptr;
            size=0;
            return;
        }

        for(i=0; v1.sir[i]!=NULL && v1.sir!=nullptr; i++)
            {
                n++;
            }


            sir = new char[n+1];
            for(i=0; v1.sir[i]!=NULL; i++)
                sir[i]=v1.sir[i];
            sir[n]=NULL;
            size=n+1;




    }
    bool operator ==(String &string1)
    {
        if(size!=string1.size)
            return 0;
        else
        {
            for(int i=0;i<=size;i++)
            {
                if(string1.sir[i]!=sir[i])
                    return 0;

            }
            return 1;
        }
    }
    friend ostream & operator <<(ostream &out,String &v1);
    void inserare(char a)
    {
        char *aux;
        int i;
        aux = new char[size+1];
        for(i=0; i<size-1; i++)
            aux[i]=sir[i];
        aux[i]=a;
        aux[i+1]=NULL;
        size=size+1;
        delete [] sir;
        sir=aux;
    }
    String operator + (const String &sir2)
    {
        String sir3;
        sir3.size=sir2.size+size-1;
        int i;
        sir3.sir=new char [sir3.size];
        for(i=0; i<size-1; i++)
        {
            sir3.sir[i]=sir[i];

        }
        int j=0;
        for(; i<sir3.size-1; i++)
        {
            sir3.sir[i]=sir2.sir[j];
            j++;

        }
        sir3.sir[i]=NULL;
        return sir3;

    }
    int length()
    {
        return size;
    }


};
ostream & operator <<(ostream &out,String &v1)
{   if (v1.sir!=nullptr)
    out<<v1.sir;
    else out<<"Sir gol";
    return out;
}
*/
class RatingInvalid: public exception
{

    string mesaj;
public:
    RatingInvalid(string mesaj)
    {
        this-> mesaj=mesaj;
    }
    RatingInvalid()
    {

    }
    string what()
    {
        return mesaj;
    }
};
class OutofMoney: public exception
{

    string mesaj;
public:
    OutofMoney(string mesaj)
    {
        this-> mesaj=mesaj;
    }
    OutofMoney()
    {
        mesaj="OutOfMoney";
    }
    string what()
    {
        return mesaj;
    }
};

class Data // gata 2
{
    int zi,luna,an;
    static Data astazi;
public:
    Data(const Data &d1)
    {
        zi=d1.zi;
        luna=d1.luna;
        an=d1.an;
    }
    Data()
    {
        zi=0;
        luna=0;
        an=0;
    }
    Data(int zi,int luna, int an)
    {
        this-> zi = zi;
        this-> luna = luna;
        this-> an = an;
    }
    void operator = (const Data &d1)
    {

        this->zi=d1.zi;
        this->luna=d1.luna;
        this->an=d1.an;

    }
    int get_zi()
    {
        return zi;
    }
    int get_luna()
    {
        return luna;
    }
    int get_an()
    {
        return an;
    }
    void set_zi(int x)
    {
        zi = x;
    }
    void set_luna(int x)
    {
        luna=x;
    }
    void set_an(int x)
    {
        an=x;
    }
    void afisare_date()
    {
        cout<<"Ziua "<<zi<<" luna "<<luna<<" anul "<<an<<endl;
    }
    bool operator <(Data &data1)
    {
        bool ok=0;
        if(an<data1.an)
            ok=1;
        else if(an==data1.an)
        {
            if(luna<data1.luna)
                ok=1;
            else if(luna==data1.luna)
            {
                if(zi<data1.zi)
                    ok=1;

            }
        }
        return ok;
    }
    static Data return_astazi()
    {
        return astazi;
    }

};

time_t t=time(NULL);
tm* timePtr= localtime(&t);
Data azi(timePtr->tm_mday+1,timePtr->tm_mon+1,timePtr->tm_year+1900);
Data Data::astazi=azi;

class Review
{
    public:
    virtual void show_full_review() const =0;
    virtual void recomandat() const=0;
    virtual ~Review()
    {

    }
};

class ReviewPersonal:public Review
{
    string Nume,adresa,comentariu;
    double rating;
    ReviewPersonal()
    {
        rating=0;
    }
    ReviewPersonal(string comentariu,string Nume,string adresa,double rating)
    {
            this->comentariu=comentariu;
            this->adresa=adresa;
            this->rating=rating;
    }
    void show_full_review() const
    {    if (rating>5 && rating<0)
         {
                 try
                  { string mesaj="Rating invalid";
                    throw RatingInvalid(mesaj);
                  }
                  catch(RatingInvalid exc)
                  {
                      exc.what();
                      throw RatingInvalid();
                  }
        }
        cout<<"Numele persoanei este:"<<Nume<<" adresa este:"<<adresa<<" rating-ul acordat este:"<<rating<<endl;
        cout<<"Comentariu:"<<endl;
        cout<<comentariu;
    }
    void recomandat()const
    {   if (rating>5 && rating<0)
        {   try
              { string mesaj="Rating invalid";
                throw RatingInvalid(mesaj);
              }
              catch(RatingInvalid exc)
              {
                  exc.what();
              }
        }
        if(rating > 3)
            cout<<"Produs recomandat";
        else if(rating>2.5)
            cout<<"Produs sub medie dar ok";
        else
            cout<<"Produs de proasta calitate";
    }

};


class ReviewProfesionist:public Review
{
    string Nume,lista_publicatii,diplome,recenzie;
    double rating;
    ReviewProfesionist(string Nume,string lista_publicatii,string diplome, string recenzie,double rating)
    {
        this->Nume=Nume;
        this->lista_publicatii=lista_publicatii;
        this->diplome=diplome;
        this->recenzie=recenzie;
        this->rating=rating;
    }
    ReviewProfesionist()
    {
        rating=0;
    }
     void show_full_review() const
    {   if (rating>5 && rating<0)
        {   try
              { string mesaj="Rating invalid";
                throw RatingInvalid(mesaj);
              }
              catch(RatingInvalid exc)
              {
                  exc.what();
              }
        }

        cout<<"Numele persoanei este:"<<Nume<<" publicatiile sunt:"<<lista_publicatii<<" diplomele lui sunt:"<<diplome<<" rating-ul acordat este:"<<rating<<endl;
        cout<<"Recenzie:"<<endl;
        cout<<recenzie;
    }
    void recomandat() const
    {   if (rating>5 && rating<0)
        {   try
              { string mesaj="Rating invalid";
                throw RatingInvalid(mesaj);
              }
              catch(RatingInvalid exc)
              {
                  exc.what();
              }
        }
        if(rating>4)
            cout<<"Produs recomandat";
        else if(rating >3)
            cout<<"Produs bun dar nu de calitate mare";
        else if(rating>2.5)
            cout<<"Produs pur mediocru";
        else
            cout<<"Nerecomandabil , calitatea , pretul sau chiar ambele nu se potrivesc";
    }

};


class Cod_Personal
{   public:
    string cod;
    Cod_Personal()
    {
        cod="";
    }
    Cod_Personal(string cod)
    {
        this->cod=cod;
    }
};

class Reduceri //gata 2
{
    double procentaj;
    Data data_inceput;
    Data data_final;

public:
    Reduceri()
    {
        procentaj=0;
        Data d3(0,0,0);
        data_inceput=d3;
        data_final=d3;

    }
    Reduceri(double procentaj, Data date1, Data date2)
    {
        this-> procentaj = procentaj;
        data_inceput= date1;
        data_final=date2;
    }
    Reduceri(const Reduceri & reducere1)
    {
        procentaj = reducere1.procentaj;
        data_inceput=reducere1.data_inceput;
        data_final=reducere1.data_final;
    }
    void operator =(const Reduceri &reducere1)
    {
        procentaj = reducere1.procentaj;
        data_inceput=reducere1.data_inceput;
        data_final=reducere1.data_final;
    }
    double get_procentaj()
    {
        return procentaj;
    }
    void set_procentaj(double procentaj)
    {
        this-> procentaj = procentaj;
    }

    void set_durata(Data date1,Data date2)
    {
        data_inceput=date1;
        data_final=date2;
    }
    void set_data_inceput(Data date1)
    {
        data_inceput=date1;

    }
    void set_data_final(Data date2)
    {
        data_final = date2;
    }
    Data get_data_inceput()
    {
        return data_inceput;
    }
    Data get_data_final()
    {
        return data_final;
    }
    void afisare_durata()
    {
        cout<<"Reducere incepe in ";
        data_inceput.afisare_date();
        cout<<"Reducerea se termina in ";
        data_final.afisare_date();
    }
};


class MagazinOnline //urmeaza
{


};

class Produse:protected Cod_Personal //gata 2
{
protected:
    static int nr_produse;
    string nume_produs;
    int cantitate_produs;
    double pret;
    Reduceri reducere;

public:
    void operator = (const Produse & produs)
    {
        nume_produs=produs.nume_produs;
        cantitate_produs=produs.cantitate_produs;
        pret=produs.pret;
        reducere=produs.reducere;
    }
    string get_code()
    {
        return cod;
    }
    void set_code(string cod)
    {
        this->cod=cod;
    }
    Produse()
    {
        string nume;
        nume_produs=nume;

        cantitate_produs=0;
        pret=0;
        Data d1,d2;
        Reduceri reducere1(0.0,d1,d2);
        reducere = reducere1;
        nr_produse++;

    }
    Produse(string nume, int cantitate, double pret, Reduceri reducere1)
    {
        nume_produs=nume;
        cantitate_produs=cantitate;
        this->pret= pret;
        reducere = reducere1;
        nr_produse++;
    }
    Produse(string nume, int cantitate, double pret)
    {
        nume_produs=nume;
        cantitate_produs=cantitate;
        this->pret=pret;
        nr_produse++;
    }
    Produse(const Produse &produs)
    {
        nume_produs=produs.nume_produs;
        cantitate_produs=produs.cantitate_produs;
        pret=produs.pret;
        reducere=produs.reducere;
        nr_produse++;
    }
    string get_nume()
    {
        return nume_produs;
    }
    int get_cantitate()
    {
        return cantitate_produs;
    }
    double get_pret()
    {
        return pret;
    }
    Reduceri get_reducere()
    {
        return reducere;
    }
    void set_nume(string nume)
    {
        nume_produs=nume;
    }
    void set_cantitate(int cantitate)
    {
        cantitate_produs=cantitate;
    }
    void set_pret(double pret)
    {
        this->pret= pret;
    }
    void set_reducere(Reduceri reducere1)
    {
        reducere=reducere1;
    }
    void afisare_produs()
    {
        cout<<nume_produs<<" "<<cantitate_produs<<" "<<pret<<" "<<reducere.get_procentaj()<<endl;

    }
    bool operator ==(const Produse &produs)
    {

        if(produs.cantitate_produs!=cantitate_produs||produs.pret!=pret||(!(nume_produs==produs.nume_produs)))
            return 0;
        return 1;
    }
    static int get_nr_produse()
    {
        return nr_produse;
    }
    virtual ~Produse()
    {
        --nr_produse;
    }

};
int Produse::nr_produse =0;

class ProdusePerisabile:public virtual Produse
{   protected:
    bool aproape_expirat;
    public:
    double get_pret()
    {
        if(aproape_expirat==1)
            return pret*0.5;
    }
    ProdusePerisabile():Produse()
        {
            aproape_expirat=0;
        }
    ProdusePerisabile(string nume, int cantitate, double pret, Reduceri reducere1,bool expirat):Produse(nume,cantitate,pret,reducere1)
    {
        this->aproape_expirat=expirat;
    }
    ProdusePerisabile(string nume, int cantitate, double pret,bool expirat):Produse(nume,cantitate,pret)
    {
        this->aproape_expirat=expirat;
    }
};

class ProduseLimitate:public virtual Produse
{   protected:
    Data limita;
    public:
    int get_cantitate()
    {
        if(!(Data::return_astazi() < limita))
            return 0;
        else return cantitate_produs;
    }
    ProduseLimitate():Produse()
        {
            limita=Data::return_astazi();
        }
    ProduseLimitate(string nume, int cantitate, double pret, Reduceri reducere1,Data d1):Produse(nume,cantitate,pret,reducere1)
    {
        limita=d1;
    }
    ProduseLimitate(string nume, int cantitate, double pret,Data d1):Produse(nume,cantitate,pret)
    {
        limita=d1;
    }
};

class ProduseLimitatePerisabile:public ProduseLimitate,public ProdusePerisabile
{
    ProduseLimitatePerisabile():Produse()
        {
            limita=Data::return_astazi();
            aproape_expirat=0;
        }
    ProduseLimitatePerisabile(string nume, int cantitate, double pret, Reduceri reducere1,Data d1,bool expirat):ProduseLimitate(nume,cantitate,pret,reducere1,d1)
    {
        aproape_expirat=expirat;
    }
    ProduseLimitatePerisabile(string nume, int cantitate, double pret,Data d1,bool expirat):ProduseLimitate(nume,cantitate,pret,d1)
    {
        limita=d1;
        aproape_expirat=expirat;
    }

};


/*
class Vector_Produse // gata
{
    Produse *produse;
    int n;
    friend class Comenzi;
public:
    void operator = (const Vector_Produse &v1)
    {
        delete [] produse;
        if(v1.produse==nullptr)
        {
            produse=nullptr;
            n=0;
            return;
        }
        int i;
        produse = new Produse[v1.n];
        for(i=0; i<v1.n; i++)
        {
            produse[i]=v1.produse[i];
        }
        n=v1.n;

    }
    Vector_Produse()
    {
        produse=nullptr;
        n=0;
    }
    Vector_Produse(Produse v[],int n)
    {
        if (n==0)
        {
            produse==nullptr;
            n=0;
            return;
        }
        produse = new Produse[n];
        int i=0;
        for(i=0; i<n; i++)
        {
            produse[i]=v[i];
        }
        this ->n = n;
    }
    Vector_Produse(const Vector_Produse &v1)
    {

        if(v1.produse==nullptr)
        {
            produse=nullptr;
            n=0;
            return;
        }

        int i;
        produse = new Produse[v1.n];
        for(i=0; i<v1.n; i++)
        {
            produse[i]=v1.produse[i];
        }
        n=v1.n;

    }
    void add_produs(Produse produs)
    {
        Produse *aux;
        int i=0;
        aux = new Produse[n+1];
        for(i=0; i<n; i++)
        {
            aux[i]=produse[i];
        }
        aux[i]=produs;
        delete [] produse;
        produse = aux;
        n=n+1;
    }
    void sterge_produs(int i)
    {
        if (i>=n)
        {
            cout<<"Nu exista element pe pozitia aia"<<endl;
            return;

        }
        Produse * aux;
        aux = new Produse[n-1];
        int j=0;
        for(; j<i; j++)
            aux[j]=produse[j];
        for(j=i+1; j<n; j++)
            aux[j-1]=produse[j];
        delete []produse;
        produse = aux;
        n=n-1;
    }
    void afisare_vector()
    {
        int i=0;
        for(i=0; i<n; i++)
            produse[i].afisare_produs();
        cout<<endl;
        if(n==0)
            cout<<"Vectorul nu are produse"<<endl;
    }
    int get_size()
    {
        return n;
    }
    ~Vector_Produse()
    {
        delete [] produse;
    }
};

*/

class Vanzator //Testat si functioneaza
{
    string nume_vanzator;
    vector<Produse> catalog_produse;
    double balanta_vanzator;
    string adresa_vanzator;
public:
    Vanzator()
    {

        string vid;
        nume_vanzator=vid;
        adresa_vanzator=vid;
        balanta_vanzator=0;

    }
    Vanzator(string nume, vector <Produse> catalog,double balanta, string adresa )
    {
        nume_vanzator=nume;
        catalog_produse=catalog;
        balanta_vanzator=balanta;
        adresa_vanzator=adresa;
    }
    Vanzator(const Vanzator & v1)
    {
        nume_vanzator=v1.nume_vanzator;
        catalog_produse=v1.catalog_produse;
        balanta_vanzator=v1.balanta_vanzator;
        adresa_vanzator=v1.adresa_vanzator;
    }
    void set_nume(string nume)
    {
        nume_vanzator=nume;
    }
    void set_vector(vector<Produse> v1)
    {
        catalog_produse=v1;
    }
    void set_balanta(double balanta)
    {
        balanta_vanzator=balanta;
    }
    void set_adresa(string adresa)
    {
        adresa_vanzator=adresa;
    }
    string get_nume()
    {
        return nume_vanzator;
    }
    vector<Produse> get_catalog()
    {
        return catalog_produse;
    }
    double get_balanta()
    {
        return balanta_vanzator;
    }
    string get_adresa()
    {
        return adresa_vanzator;
    }
    void adauga_produse(Produse produs)
    {
        catalog_produse.push_back(produs);
    }
    void sterge_produs(int i)
    {
        catalog_produse.erase(catalog_produse.begin()+i);
    }
    void afiseaza_vanzator()
    {
        cout<<"Numele vanzatorului este "<<nume_vanzator<<" ,Balanta este "<<balanta_vanzator<<" ,Adresa este "<<adresa_vanzator<<endl;

    }
    void afisare_produse_vanzator()
    {
        for(int i=0;i<catalog_produse.size();i++)
        {
            catalog_produse[i].afisare_produs();
        }
    }



};

class Cumparatori //practic gata 2
{
    string nume_cumparator;
    string adresa_cumparator;
    double balanta_cumparator;
public:
    Cumparatori()
    {
        string vid;
        nume_cumparator=vid;
        adresa_cumparator=vid;
        balanta_cumparator=0;
    }
    Cumparatori(string nume_cumparator, string adresa_cumparator, double balanta_cumparator)
    {
        this->nume_cumparator=nume_cumparator;
        this->adresa_cumparator=adresa_cumparator;
        this->balanta_cumparator=balanta_cumparator;
    }
    void set_nume_cumparator(string nume)
    {
        nume_cumparator=nume;
    }
    void set_adresa_cumparator(string adresa)
    {
        adresa_cumparator=adresa;
    }
    void set_balanta_cumparator(double balanta)
    {
        balanta_cumparator=balanta;
    }
    void add_money(double d)
    {
        balanta_cumparator+=d;
    }
    string get_nume()
    {
        return nume_cumparator;
    }
    string get_adresa()
    {
        return adresa_cumparator;
    }
    virtual double get_balanta()
    {
        return balanta_cumparator;
    }

    void afisare_cumparator()
    {
        cout<<"Numele cumparatorului este "<<nume_cumparator<<" ,adresa lui este "<<adresa_cumparator<<" iar balanta lui este "<<balanta_cumparator<<endl;
    }

};

class CumparatoriAdministrator
{
    double get_balanta()
    {
        return 100000000;
    }
};

class Comenzi
{
    Cumparatori cumparator;
    Vanzator vanzator;
    vector <Produse> cumparaturi;
public:
    Comenzi()
    {
        Cumparatori c1;
        Vanzator v1;
        cumparator=c1;
        vanzator=v1;

    }
    Comenzi(const Comenzi &comanda)
    {
        cumparator=comanda.cumparator;
        vanzator=comanda.vanzator;
        cumparaturi=comanda.cumparaturi;
    }
    Comenzi(Cumparatori cumparator1,Vanzator vanzator1,vector<Produse> catalog)
    {
        cumparator=cumparator1;
        vanzator=vanzator1;
        cumparaturi=catalog;
    }
    void set_cumparator(Cumparatori cumparator1)
    {
        cumparator=cumparator1;
    }
    void set_vanzator(Vanzator vanzator1)
    {
        vanzator=vanzator1;
    }
    void set_cumparaturi(vector<Produse> catalog)
    {
        cumparaturi=catalog;
    }
    Cumparatori get_cumparator()
    {
        return cumparator;
    }
    Vanzator get_vanzator()
    {
        return vanzator;
    }
    vector<Produse> get_cumparaturi()
    {
        return cumparaturi;
    }
    void afisare_comanda()
    {
        cumparator.afisare_cumparator();
        vanzator.afiseaza_vanzator();
        for(int i=0;i<cumparaturi.size();i++)
        {
            cumparaturi[i].afisare_produs();
        }
    }
    void plata()
    {
        int index;
        double cost=0;
        bool suficient=1;
        bool exista;
        for(int i=0;i<cumparaturi.size();i++)
        {   exista=0;
            for(int j=0;j<vanzator.get_catalog().size();j++)
            {
                if(cumparaturi[i]==vanzator.get_catalog()[j])
                   exista=1;
            }
            if(exista==0)
                {cout<<"Un produs nu exista in catalogul cumparatorului";
                    return;
                }
            else
            {
                cost+=cumparaturi[i].get_pret()*(1-cumparaturi[i].get_reducere().get_procentaj());
            }

        }
        if(cost>cumparator.get_balanta())
        {   try
            {
                throw OutofMoney();
            }

            catch(OutofMoney money)
            {
                cout<<"Cumparatorul nu are suficienti bani";
            }
            return;
        }
        else
        {
            cumparator.set_balanta_cumparator(cumparator.get_balanta()-cost);
            vanzator.set_balanta(vanzator.get_balanta()-cost);
            cout<<"Comanda efectuata cu succes"<<endl;

        }

    }
};

class Advertisement
{   protected:
    string text;
    public:
    virtual void afisare_pe_ecran() const = 0;
};
class AdvertisementMic:public Advertisement
{   public:
   void afisare_pe_ecran()const
    {
        cout<<"Aceasta reclama apare ca o fereastra in partea din stanga jos a browseru-lui"<<endl;
        cout<<text;
    }
};

class AdvertisementMare:public Advertisement
{   public:
    void afisare_pe_ecran()const
    {
        cout<<"Aceasta reclama apare mare sub barea de stare a browseru-lui si ocupa 20% din fereastra"<<endl;
        cout<<text;
    }
};
int main()
{


    vector <Produse> catalog;
    Produse produs1("andrei",123,30.5);
    Produse produs2("aladin",123,30.5);
    Produse produs3("antonescu",123,30.5);
    produs1.afisare_produs();
    catalog.push_back(produs1);
    catalog.push_back(produs2);
    catalog.push_back(produs3);

    vector <Produse> cumparat;
    cumparat.push_back(produs2);
    cumparat.push_back(produs3);
    for(int i=0;i<catalog.size();i++)
    {
        catalog[i].afisare_produs();
    }
    cout<<endl<<endl<<endl;
    Cumparatori cumparator1("Andrei","Strada Giurgiu nr 5",120);
    Vanzator vanzator1("Alin",catalog,150,"Strada mea");
    vanzator1.afisare_produse_vanzator();
    cout<<cumparator1.get_balanta();
    Comenzi comanda1(cumparator1,vanzator1,cumparat);
    cout<<comanda1.get_cumparator().get_balanta();

    comanda1.plata();
    cout<<comanda1.get_cumparator().get_balanta();
    cout<<endl;
    Produse bonus_produs;
    cout<<Produse::get_nr_produse();

    Data d1;
    d1 = Data::return_astazi();
    d1.afisare_date();


    return 0;
}
