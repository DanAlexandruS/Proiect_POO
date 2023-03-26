#include <iostream>
#include <fstream>
using namespace std;

ofstream out("out.txt");

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
class Data // gata
{
    int zi,luna,an;
public:
    Data(Data &d1)
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
    void operator = (Data &d1)
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

};


class Reduceri //gata
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
    Reduceri(Reduceri & reducere1)
    {
        procentaj = reducere1.procentaj;
        data_inceput=reducere1.data_inceput;
        data_final=reducere1.data_final;
    }
    void operator =(Reduceri &reducere1)
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


class MagazinOnline
{


};

class Produse //gata
{
    String nume_produs;
    int cantitate_produs;
    double pret;
    Reduceri reducere;

public:
    void operator = (Produse & produs)
    {
        nume_produs=produs.nume_produs;
        cantitate_produs=produs.cantitate_produs;
        pret=produs.pret;
        reducere=produs.reducere;
    }
    Produse()
    {
        String nume;
        nume_produs=nume;

        cantitate_produs=0;
        pret=0;
        Data d1,d2;
        Reduceri reducere1(0.0,d1,d2);
        reducere = reducere1;

    }
    Produse(String nume, int cantitate, double pret, Reduceri reducere1)
    {
        nume_produs=nume;
        cantitate_produs=cantitate;
        this->pret= pret;
        reducere = reducere1;
    }
    Produse(String nume, int cantitate, double pret)
    {
        nume_produs=nume;
        cantitate_produs=cantitate;
        this->pret=pret;
    }
    String get_nume()
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
    void set_nume(String nume)
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
   bool operator ==(Produse &produs)
    {

        if(produs.cantitate_produs!=cantitate_produs||produs.pret!=pret||(!(nume_produs==produs.nume_produs)))
            return 0;
        return 1;
   }

};
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
    {   if (n==0)
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
    {   if (i>=n)
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
        for(i=0;i<n;i++)
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

class Vanzator //Testat si functioneaza
{
    String nume_vanzator;
    Vector_Produse catalog_produse;
    double balanta_vanzator;
    String adresa_vanzator;
public:
    Vanzator()
    {   Vector_Produse v2;
        String vid;
        nume_vanzator=vid;
        adresa_vanzator=vid;
        balanta_vanzator=0;
        Vector_Produse v1 = v2;
    }
    Vanzator(String nume , Vector_Produse catalog ,double balanta , String adresa )
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
    void set_nume(String nume)
    {
        nume_vanzator=nume;
    }
    void set_vector(Vector_Produse v1)
    {
        catalog_produse=v1;
    }
    void set_balanta(double balanta)
    {
        balanta_vanzator=balanta;
    }
    void set_adresa(String adresa)
    {
        adresa_vanzator=adresa;
    }
    String get_nume()
    {
        return nume_vanzator;
    }
    Vector_Produse get_catalog()
    {
        return catalog_produse;
    }
    double get_balanta()
    {
        return balanta_vanzator;
    }
    String get_adresa()
    {
        return adresa_vanzator;
    }
    void adauga_produse(Produse produs)
    {
        catalog_produse.add_produs(produs);
    }
    void sterge_produs(int i)
    {
        catalog_produse.sterge_produs(i);
    }
    void afiseaza_vanzator()
    {
        cout<<"Numele vanzatorului este "<<nume_vanzator<<" ,Balanta este "<<balanta_vanzator<<" ,Adresa este "<<adresa_vanzator<<endl;
        cout<<"Produsele sale sunt:"<<endl;


    }
    void afisare_produse_vanzator()
    {
        catalog_produse.afisare_vector();
    }



};

class Cumparatori //practic gata
{
    String nume_cumparator;
    String adresa_cumparator;
    double balanta_cumparator;
public:
    Cumparatori()
    {
        String vid;
        nume_cumparator=vid;
        adresa_cumparator=vid;
        balanta_cumparator=0;
    }
    Cumparatori(String nume_cumparator, String adresa_cumparator, double balanta_cumparator)
    {
        this->nume_cumparator=nume_cumparator;
        this->adresa_cumparator=adresa_cumparator;
        this->balanta_cumparator=balanta_cumparator;
    }
    void set_nume_cumparator(String nume)
    {
        nume_cumparator=nume;
    }
    void set_adresa_cumparator(String adresa)
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
    String get_nume()
    {
        return nume_cumparator;
    }
    String get_adresa()
    {
        return adresa_cumparator;
    }
    double get_balanta()
    {

        return balanta_cumparator;
    }
    void afisare_cumparator()
    {
        cout<<"Numele cumparatorului este "<<nume_cumparator<<" ,adresa lui este "<<adresa_cumparator<<" iar balanta lui este "<<balanta_cumparator<<endl;
    }
};

class Comenzi
{
    Cumparatori cumparator;
    Vanzator vanzator;
    Vector_Produse cumparaturi;
    public:
    Comenzi()
    {
        Cumparatori c1;
        Vanzator v1;
        Vector_Produse vid;
        cumparator=c1;
        vanzator=v1;
        cumparaturi=vid;
    }
    Comenzi(const Comenzi &comanda)
    {
        cumparator=comanda.cumparator;
        vanzator=comanda.vanzator;
        cumparaturi=comanda.cumparaturi;
    }
    Comenzi(Cumparatori cumparator1,Vanzator vanzator1,Vector_Produse catalog)
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
    void set_cumparaturi(Vector_Produse catalog)
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
    Vector_Produse get_cumparaturi()
    {
        return cumparaturi;
    }
    void afisare_comanda()
    {
        cumparator.afisare_cumparator();
        vanzator.afiseaza_vanzator();
        cumparaturi.afisare_vector();
        cout<<"salut";
    }
    void plata()
    {
        int index;
        double cost=0;
        bool suficient=1;
        bool are=1;
        for(index=0;index<cumparaturi.get_size();index++)
        {
            cost+=cumparaturi.produse[index].get_pret()*(1-cumparaturi.produse[index].get_reducere().get_procentaj());
            if(cumparaturi.produse[index].get_cantitate()==0)
               {
                   suficient=0;

               }
            int i=0;
            for(i=0;i<vanzator.get_catalog().get_size();i++)
            {
                are=0;
                if(vanzator.get_catalog().produse[i]==cumparaturi.produse[index])
                {
                    are=1;
                    break;  // verific daca produsul cumparat e detinut de vanzator
                }
            }

        }

        if(cost > cumparator.get_balanta())
        {
            cout<<"Plata nu poate fi efectuata deoarece cumparatorul nu are suficienti bani"<<endl;
            return;
        }
        else
        {
            if(suficient==0)
                cout<<"Plata nu poate efectuata deoarece un produs nu mai este pe stoc"<<endl;
            else
            {
                cumparator.set_balanta_cumparator(cumparator.get_balanta()-cost);
                vanzator.set_balanta(vanzator.get_balanta()+cost);
                for(index=0;index<cumparaturi.get_size();index++)
                    cumparaturi.produse[index].set_cantitate(cumparaturi.produse[index].get_cantitate()-1);
                cout<<"Plata efectuata cu succes"<<endl;
            }
        }
    }

};





int main()
{   cout.rdbuf(out.rdbuf());

    String s1("are"),s2(" mere");
    String s3=s1+s2;
    String s4;
    s3=s4;
    //cout<<s4;
    //cout<<s3;
    Data d1(1,12,2023);
    //d1.afisare_date();
    Data d2(1,11,2023);
    Data d3 = d2;
    //d3.afisare_date();
    Reduceri reducere2(0.2,d1,d2);
    //reducere2.afisare_durata();
    Reduceri reducere3(reducere2);
    //reducere3.afisare_durata();
    Reduceri reducere4 = reducere3;
    //reducere4.afisare_durata();


    Produse p1("ardei",10,30.5,reducere2);
    Produse p3("balonase",200,0.3,reducere3);
    Produse p2;



    //p1.afisare_produs();
    //p2.afisare_produs();
    p2=p1;
    p2.set_nume("Castraveti");
    //p2.afisare_produs();
    //p3.afisare_produs();
    //cout<<"Testare vector:"<<endl;
    Produse a[]={p2,p1,p3};
    Vector_Produse v1(a,3);
    //v1.afisare_vector();
    Produse p4("Astronaut gonflabil",50,2000);
    v1.add_produs(p4);
    //cout<<"Test 2"<<endl<<endl;
    //v1.afisare_vector();
    //cout<<"Test 3"<<endl<<endl;
    v1.sterge_produs(2);
    v1.afisare_vector();

    //cout<<"Test vid"<<endl<<endl;
    Vector_Produse v2;
    //v2.afisare_vector();
    v2.add_produs(p2);
    //v2.afisare_vector();
    //v2.sterge_produs(0);
    //v2.afisare_vector();

    Vector_Produse v3;

    v3=v1;
    //v3.afisare_vector();
    Vector_Produse v4(v3);


    Produse produs5("Apa",32,32.5,reducere2);
    Vanzator vanzator1("Andrei",v3,32.5,"Strada Tatulesti nr. 5");
    //vanzator1.afiseaza_vanzator();
    vanzator1.adauga_produse(produs5);
    //vanzator1.afiseaza_vanzator();
    vanzator1.sterge_produs(0);
    //cout<<"Produse dupa ce a fost sters unul"<<endl;
    //vanzator1.afiseaza_vanzator();
    Comenzi comanda1;
    //v3.afisare_vector();
    v3=v2;
    //v3.afisare_vector();
    Cumparatori cumparator1("Andrei","Tatulesti",30.5);
    cout<<"Testare comenzi:"<<endl;
    Comenzi comanda2(cumparator1,vanzator1,v3);
    comanda2.get_cumparaturi().afisare_vector();
    cout<<endl;
    comanda2.afisare_comanda();
    comanda2.plata();
    comanda2.afisare_comanda();
    cout<<endl;
    v3.afisare_vector();
    String s7("salut1"),s8("salut1");
    cout<<(s7==s8);

    return 0;
}
