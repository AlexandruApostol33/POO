#include <iostream>
#include <string.h>
#include <bits/stdc++.h>
using namespace std;
class carte{
    private:
    char* denumire;
    char* autor_p;
    char* autor_s;
    int nr_pag;
    float pret;
    float rating;
public:
    carte(char*, char* , char*, int, float, float);
    ~carte();
    void citire(istream &in);
    void afisare(ostream& out);
    friend istream& operator>>(istream& in,carte& c);
    friend ostream& operator<<(ostream& out, carte& c);
    carte& operator=(carte &c);
    carte(carte&);
    bool operator==( carte&c2);
    bool operator<( carte &c2);
    bool operator>( carte &c2);
    void set_pret(float pretul);
    void set_denumire(char* denum);
    void set_autor_p(char* autorp);
    void set_rating(float ratingul);
    void set_nr_pag(int nrpag);
    void set_autor_s(char* autors);
    char* get_Denumire();
    char* get_autor_p();
    float get_rating();
    int get_nr_pag();
    char* get_autor_s();
    float get_pret();
};
carte::carte(char* denum=NULL, char* autor1=NULL, char* autor2=NULL, int nrpagini=0, float pretul=0, float ratingul=0)
        {                                       // CONSTRUCTORUL
            if (denum != NULL)
        {this->denumire=new char[strlen(denum)];
        strcpy(denumire,denum);}
        else
            this->denumire=denum;
        if (autor1!= NULL)
            {this->autor_p=new char[strlen(autor1)];
        strcpy(autor_p,autor1);}
        else
            this->autor_p=autor1;
        if (autor2!= NULL)
            {this->autor_s=new char[strlen(autor2)];
        strcpy(autor_s,autor2);}
        else
            this->autor_s=autor2;
        this->nr_pag=nrpagini;
        this->pret=pretul;
        this->rating=ratingul;
        }
carte::~carte() // DESTRUCTOR
{
    strcpy(denumire,"");
    strcpy(autor_p,"");
    strcpy(autor_s,"");
    this->nr_pag=0;
    this->pret=0;
    this->rating=0;
}
void carte::citire(istream &in)
{   cout<<endl;
    cout<<"Inserati numele cartii: "<<endl;
    char *num;
    num = new char [256];
    in.getline(num,256);
    //in.get();
    //cout <<"citeste\n";
    this->denumire=new char [strlen(num)];
    strcpy(denumire,num);
    //cout<<denumire<<endl;
    cout<<"Inserati numele autorului principal: "<<endl;
    char *nump;
    nump = new char[256];
    in.getline(nump,256);
    this->autor_p=new char[strlen(nump)];
    strcpy(autor_p,nump);
    //cout<<autor_p<<endl;
    cout<<"Inserati numele autorului secundar: "<<endl;
    char *nums;
    nums = new char [256];
    in.getline(nums,256);
    this->autor_s=new char [strlen(nums)];
    strcpy(autor_s,nums);
    //cout<<autor_s;
    cout<<"Inserati numarul de pagini al cartii, numar intreg pozitiv: "<<endl;
    in>>this->nr_pag;
    cout<<"Inserati rating-ul cartii, numar real cuprins intre 0 si 10: "<<endl;
    in>>this->rating;
    cout<<"Inserati pretul cartii, numar real pozitiv: "<<endl;
    in>>this->pret;

}
istream& operator>>(istream& in,carte& c)
{
    c.citire(in);
    return in;
}
ostream& operator<<(ostream& out, carte& c){
    c.afisare(out);
    return out;
}
void carte::afisare(ostream& out)
{ cout<<"Cartea se numeste: ";
  out<<this->denumire<<endl;
  cout<<"Autorul principal este: ";
  out<<this->autor_p<<endl;
  cout<<"Autorul secundar este: ";
  out<<this->autor_s<<endl;
  cout<<"Numarul de pagini este: ";
  out<<this->nr_pag<<endl;
  cout<<"Pretul este: ";
  out<<this->pret<<endl;
  cout<<"Rating-ul cartii este: ";
  out<<this->rating<<endl;
  cout<<"\n";

}
carte& carte::operator=(carte &c)
{
    if(this !=&c)
    {
        denumire=new char[strlen(c.denumire)];
        strcpy(denumire, c.denumire);
        autor_p=new char[strlen(c.autor_p)];
        strcpy(autor_p,c.autor_p);
        autor_s=new char[strlen(c.autor_s)];
        strcpy(autor_s,c.autor_s);
        nr_pag=c.nr_pag;
        rating=c.rating;
        pret=c.pret;
    }
}
carte::carte(carte &c)
{
        denumire=new char[strlen(c.denumire)];
        strcpy(denumire, c.denumire);
        autor_p=new char[strlen(c.autor_p)];
        strcpy(autor_p,c.autor_p);
        autor_s=new char[strlen(c.autor_s)];
        strcpy(autor_s,c.autor_s);
        nr_pag=c.nr_pag;
        rating=c.rating;
        pret=c.pret;
}
void carte::set_pret(float pretul){
    pret=pretul;
}
void carte::set_denumire(char* denum){
    denumire=new char[strlen(denum)];
        strcpy(denumire, denum);
}
void carte::set_autor_p(char* autorp){
    autor_p=new char[strlen(autorp)];
        strcpy(autor_p, autorp);
}
void carte::set_rating(float ratingul){
    rating=ratingul;
}
void carte::set_nr_pag(int nrpag){
    nr_pag=nrpag;
}
void carte::set_autor_s(char* autors)
{
    autor_s=new char[strlen(autors)];
        strcpy(autor_s, autors);
}
float carte::get_rating()
{
    return this->rating;
}
char* carte::get_Denumire()
{
    return this->denumire;
}
char* carte::get_autor_p()
{
    return this->autor_p;
}
char* carte::get_autor_s()
{
    return this->autor_s;
}
float carte::get_pret()
{
    return this->pret;
}
int carte::get_nr_pag()
{
    return this->nr_pag;
}
bool carte::operator>(carte &c1)
{
    if(rating>c1.rating)
        return true;
        else
        return false;
}
bool carte::operator<(carte &c1)
{
    if(rating<c1.rating)
        return true;
        else
        return false;
}
bool carte::operator==(carte&c1)
{
    if(rating==c1.rating)
        return true;
        else
        return false;

}
void menu_output()
{
    cout<<"\n\t MENIU:";
    cout<<"\n===========================================\n";
    cout<<"\n";
    cout<<" Alegeti una dintre urmatoarele optiuni:"<<endl;
    cout<<"1. Afisam cartile."<<"\n";
    cout<<"2. Adaugam o carte noua."<<"\n";
    cout<<"3. Compara doua carti."<<"\n";
    cout<<"4. Schimba ordinea a doua carti."<<"\n";
    cout<<"5. Modifica informatiile unei carti."<<"\n";
    cout<<"0. Iesire."<<"\n";

}
void menu()
{
    int option,n,i;
    cout<<"Introduceti cate carti se vor citi:"<<endl;
    cin>>n;
    carte *v=new carte[n];
    for(i=0;i<n;i++)
    {
        cin.get();
        cin>>v[i];
    }
    cout<<"Avem cartile: "<<endl;
    for(i=0;i<n;i++)
    {   cout<<"Pozitia: "<<i<<endl;
        cout<<v[i];
        cout<<endl;
    }
    do{ menu_output();
    cin>>option;
    if(option==1)
    {
        cout<<"Afisam cele "<<n<<" carti:"<<endl;
        for(i=0;i<n;i++)
        {
            cout<<"Pozitia: "<<i<<endl;
            cout<<v[i];
            cout<<endl;
        }
    }
    if(option==2)
    {   cout<<"Adaugam o carte:"<<endl;
        cin.get();
        cin>>v[n];
        n=n+1;
    }
    if(option==3)
    {   int c1,c2;
        cout<<"Comparam doua carti. Alegeti care dintre cele "<<n-1<<" carti doriti sa le comparati."<<endl;
        cout<<"Prima carte: ";;
        cin>>c1;
        cout<<"\n";
        cout<<"A doua carte: ";
        cin>>c2;
        cout<<"\n";
        if(v[c1]>v[c2])
        {
            cout<<"Prima carte are ratingul mai mare: ";
            float c;
            c=v[c1].get_rating();
            cout<<c<<endl;
        }
        else
        {
            if(v[c1]<v[c2])
            {
            cout<<"A doua carte are ratingul mai mare: ";
            float c;
            c=v[c2].get_rating();
            cout<<c<<endl;
            }
            else
                if(v[c1]==v[c2])
                cout<<"Cartile au acelasi rating."<<endl;
        }

     }
    if(option==4)
    {   int k,m;
        cout<<"Alege doua carti cu indici intre 0 si "<<n-1<<" pentru a schimba ordinea acestora."<<endl;
        cout<<"Prima:";
        cin>>k;
        cout<<endl;
        cout<<"A doua:";
        cin>>m;
        cout<<endl;
        carte aux;
        aux=v[k];
        v[k]=v[m];
        v[m]=aux;
        cout<<"Noua ordine este:"<<endl;
        for(i=0;i<n;i++)
            cout<<v[i]<<endl;
    }
    if(option==5)
    {
        int c1, pagini;
        float nr;
        cout<<endl;
        cout<<"Avem cartile: "<<endl;
        for(int i=0;i<n;i++)
        {   cout<<"Pozitia: "<<i<<endl;
        cout<<v[i];
        cout<<endl;
        }
        cout<<"Alege un numar al cartii intre 0 si "<<n-1<<"."<<endl<<endl;
        cout<<"Vrem sa modificam informatii din cartea : ";
        cin>>c1;
        char *da = "da", *rasp, *nume;
        cin.get();
        cout<<"Vrei sa modifici numele cartii? (da sau nu): ";
        cin.getline(rasp, 256);
        if (strcmp(da, rasp) == 0)
                {
                    cout<<"Noul nume al cartii este: ";
                    cin.getline(nume, 256);
                    v[c1].set_denumire(nume);
                }
                cout<<endl;
                cout<<"Vrei sa modifici numele primului autor? (da sau nu): ";
                cin.getline(rasp, 256);
                if (strcmp(da, rasp) == 0)
                {
                    cout<<"Noul nume al primului autor al cartii este: ";
                    cin.getline(nume, 256);
                    v[c1].set_autor_p(nume);
                }
                cout<<endl;
                cout<<"Vrei sa modifici numele autorului secund? (da sau nu): ";
                cin.getline(rasp, 256);
                if(strcmp(da, rasp) == 0)
                {
                    cout<<"Noul nume al autorului secund este: ";
                    cin.getline(nume, 256);
                    v[c1].set_autor_s(nume);
                }
                cout<<endl;
                cout<<"Vrei sa modifici numarul de pagini al cartii? (da sau nu): ";
                cin.getline(rasp, 256);

                if(strcmp(da, rasp) == 0)
                {
                    cout<<"Noul numar de pagini al cartii este: ";
                    cin>>pagini;
                    v[c1].set_nr_pag(pagini);
                    cin.get();
                }
                cout<<endl;
                cout<<"Vrei sa modifici pretul cartii? da sau nu): ";
                cin.getline(rasp, 256);
                if (strcmp(da, rasp) == 0)
                {
                    cout<<"Noul pret al cartii este: ";
                    cin>>nr;
                    v[c1].set_pret(nr);
                    cin.get();
                }
                cout<<endl;
                cout<<"Vrei sa modifici nota cartii? (da sau nu): ";
                cin.getline(rasp, 256);
                if(strcmp(da,rasp) == 0)
                {
                    cout<<"Noua nota a cartii este: ";
                    cin>>nr;
                    v[c1].set_rating(nr);
                }
            }
            system("cls");
    }while(option!=0);

}

int main()
{
    menu();
    return 0;
}
