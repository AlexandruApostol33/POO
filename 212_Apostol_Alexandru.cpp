#include <iostream>
#include <bits/stdc++.h>
#include <stdlib.h>
//Apostol Alexandru Sergiu, grupa 212, proiectul nr 2, tema 10;
using namespace std;
class Complex
{
private:
    int re;
    int im;

public:
    Complex(int, int);
    Complex(Complex &);
    ~Complex();
    void set_real(int);
    void set_imaginar(int);
    int get_real() { return re; };
    int get_imag() { return im; };
    void afisare(ostream &out);
    void citire(istream &in);
    friend istream &operator>>(istream &in, Complex &z);
    friend ostream &operator<<(ostream &out, Complex &z);
    double modul();
    Complex &operator=(Complex &z);
    friend Complex &operator+(Complex &z1, Complex &z2);
    friend Complex &operator-(Complex &z1, Complex &z2);
    friend Complex &operator*(Complex &z1, Complex &z2);
    friend Complex &operator/(Complex &z1, Complex &z2);
};
Complex::Complex(int r = 0, int i = 0)
{
    this->re = r;
    this->im = i;
}
Complex::Complex(Complex &z)
{
    this->re = z.re;
    this->im = z.im;
}
Complex::~Complex()
{
    this->re = 0;
    this->im = 0;
}
void Complex::set_real(int x)
{
    this->re = x;
}
void Complex::set_imaginar(int y)
{
    this->im = y;
}
void Complex::citire(istream &in)
{
    cout << "Cititi partea reala: ";
    in >> re;
    cout << "Cititi partea imaginara: ";
    in >> im;
}
istream &operator>>(istream &in, Complex &z)
{
    z.citire(in);
    return in;
}
void Complex::afisare(ostream &out)
{
    if (im == 0)
    {
        out << re;
    }
    else
    {
        if (im < 0)
        {
            out << re << im << "*i";
        }
        else
        {
            out << re << "+" << im << "*i";
        }
    }
}
ostream &operator<<(ostream &out, Complex &z)
{
    z.afisare(out);
    return out;
}
double Complex::modul()
{
    return sqrt(re * re + im * im);
}
Complex &Complex::operator=(Complex &z)
{
    this->re = z.re;
    this->im = z.im;
    return *this;
}
inline Complex &operator+(Complex &z1, Complex &z2)
{
    Complex *z = new Complex;
    z->re = z1.re + z2.re;
    z->im = z1.im + z2.im;
    return *z;
}
inline Complex &operator-(Complex &z1, Complex &z2)
{
    Complex *z = new Complex;
    z->re = z1.re - z2.re;
    z->im = z1.im - z2.im;
    return *z;
}
inline Complex &operator*(Complex &z1, Complex &z2)
{
    Complex *z = new Complex;
    z->re = z1.re * z2.re - z1.im * z2.im;
    z->im = z1.re * z2.im + z2.re * z1.im;
    return *z;
}
Complex &operator/(Complex &z1, Complex &z2)
{
    Complex *z = new Complex;
    z->re = (z1.re * z2.re + z1.im * z2.im) / (z2.re * z2.re + z2.im * z2.im);
    z->im = (z2.re * z1.im - z1.re * z2.im) / (z2.re * z2.re + z2.im * z2.im);
    return *z;
}

class Matrice
{
protected:
    Complex **v;
    static int nrmat; // Variabila statica pt a retine cate matrici au fost create
public:
    Matrice()
    {
        nrmat++;
        v = NULL;
    };
    Matrice(Complex **v)
    {
        nrmat++;
        this->v = v;
    };
    Matrice(const Matrice &M)
    {
        this->v = M.v;
    };
    Matrice &operator=(const Matrice &M)
    {
        this->v = M.v;
        return *this;
    }
    virtual ~Matrice(){};
    virtual void afisare(ostream &out){};
    virtual void citire(istream &in){};
    friend istream &operator>>(istream &in, Matrice &M)
    {
        M.citire(in);
        return in;
    }
    friend ostream &operator<<(ostream &out, Matrice &M)
    {
        M.afisare(out);
        return out;
    }
    static void numarMatrici()
    {
        cout << nrmat;
    }
};
int Matrice ::nrmat;
class Matrice_oarecare : public Matrice
{
    int lin;
    int col;

public:
    Matrice_oarecare(Complex **, int, int);
    ~Matrice_oarecare(){};
    Matrice_oarecare &operator=(const Matrice_oarecare &MO)
    {
        Matrice::operator=(MO);
        this->lin = lin;
        this->col = col;
        return *this;
    }
    Matrice_oarecare(const Matrice_oarecare &MO) : Matrice(MO)
    {
        this->lin = lin;
        this->col = col;
    }
    void afisare(ostream &out)
    {
        Matrice::afisare(out);
        for (int i = 0; i < lin; i++)
        {
            for (int j = 0; j < col; j++)
            {
                cout << v[i][j] << " ";
            }
            cout << endl
                 << " Matricea aste Oarecare";
            cout << endl;
        }
    }

    void citire(istream &in)
    {
        Matrice::citire(in);
        cout << "Introduceti numarul de linii:" << endl;
        in >> lin;
        cout << "Introduceti numarul de coloane:" << endl;
        in >> col;
        alocaMatrice();
        int x, y;
        cout << "introduceti, pe rand, partea reala si partea imaginara a fiecarui numar:" << endl;
        for (int i = 0; i < lin; i++)
            for (int j = 0; j < col; j++)
            {
                cout << "Partea reala:" << endl;
                in >> x;
                v[i][j].set_real(x);
                cout << "Partea imaginar:" << endl;
                in >> y;
                v[i][j].set_imaginar(y);
            }
    };
    friend istream &operator>>(istream &in, Matrice_oarecare &MO);
    friend ostream &operator<<(ostream &out, Matrice_oarecare &MO);
    void setlin(int l)
    {
        lin = l;
    }
    void setcol(int c)
    {
        col = c;
    }
    void alocaMatrice()
    {
        v = new Complex *[lin];
        for (int i = 0; i < col; i++)
        {
            v[i] = new Complex[col];
        }
    }
};
istream &operator>>(istream &in, Matrice_oarecare &MO)
{
    MO.citire(in);
    return in;
}
ostream &operator<<(ostream &out, Matrice_oarecare &MO)
{
    MO.afisare(out);
    return out;
}
Matrice_oarecare::Matrice_oarecare(Complex **v = NULL, int lin = 0, int col = 0) : Matrice(v)
{
    this->lin = lin;
    this->col = col;
    alocaMatrice();
    for (int i = 0; i < lin; i++)
        for (int j = 0; j < col; j++)
            this->v[i][j] = v[i][j];
}
class Matrice_patratica : public Matrice
{
    int dim;

public:
    Matrice_patratica(Complex **, int);
    ~Matrice_patratica(){};
    Matrice_patratica &operator=(const Matrice_patratica &MP)
    {
        Matrice::operator=(MP);
        this->dim = dim;
        return *this;
    }
    Matrice_patratica(const Matrice_patratica &MP) : Matrice(MP)
    {
        this->dim = dim;
    }
    void afisare(ostream &out)
    {
        Matrice::afisare(out);
        for (int i = 0; i < dim; i++)
        {
            for (int j = 0; j < dim; j++)
            {
                cout << v[i][j] << " ";
            }
            cout << endl
                 << " Matricea aste Patratica";
            cout << endl;
        }
    }

    void citire(istream &in)
    {
        Matrice::citire(in);
        cout << "Introduceti dimensiunea matricei" << endl;
        in >> dim;
        alocaMatricea();
        int x, y;
        cout << "introduceti, pe rand, partea reala si partea imaginara a fiecarui numar:" << endl;
        for (int i = 0; i < dim; i++)
            for (int j = 0; j < dim; j++)
            {
                cout << "Partea reala:" << endl;
                in >> x;
                v[i][j].set_real(x);
                cout << "Partea imaginar:" << endl;
                in >> y;
                v[i][j].set_imaginar(y);
            }
    };
    friend istream &operator>>(istream &in, Matrice_patratica &MP);
    friend ostream &operator<<(ostream &out, Matrice_patratica &MP);
    void setdim(int d)
    {
        dim = d;
    }
    void alocaMatricea()
    {
        v = new Complex *[dim];
        for (int i = 0; i < dim; i++)
        {
            v[i] = new Complex[dim];
        }
    }
    bool verificarediag()
    {
        int ok = 1;
        for (int i = 0; i < dim; i++)
            for (int j = 0; j < dim; j++)
            {
                if (i != j && v[i][j].get_real() != 0 && v[i][j].get_imag() != 0)
                    ok = 0;
            }
        if (ok == 0)
            return false;
        else
            return true;
    }
    bool trisup()
    {
        int ok = 1;
        for (int i = 0; i < dim; i++)
            for (int j = 0; j < dim; j++)
            {
                if (i > j && (v[i][j].get_real() != 0 || v[i][j].get_imag() != 0))
                    ok = 0;
            }
        if (ok == 0)
            return false;
        else
            return true;
    }
    bool triinf()
    {
        int ok = 1;
        for (int i = 0; i < dim; i++)
            for (int j = 0; j < dim; j++)
            {
                if (i < j && (v[i][j].get_real() != 0 || v[i][j].get_imag() != 0))
                    ok = 0;
            }
        if (ok == 0)
            return false;
        else
            return true;
    }
};
istream &operator>>(istream &in, Matrice_patratica &MP)
{
    MP.citire(in);
    return in;
}
ostream &operator<<(ostream &out, Matrice_patratica &MP)
{
    MP.afisare(out);
    return out;
}
Matrice_patratica::Matrice_patratica(Complex **v = NULL, int dim = 0) : Matrice(v)
{
    this->dim = dim;
    alocaMatricea();
    for (int i = 0; i < dim; i++)
        for (int j = 0; j < dim; j++)
            this->v[i][j] = v[i][j];
}
void menu_output()
{
    cout << "\n\t MENIU:";
    cout << "\n===========================================\n";
    cout << "\n";
    cout << " Alegeti una dintre urmatoarele optiuni:" << endl;
    cout << "1. Citim  matricile."
         << "\n";
    cout << "2. Afisam matricile."
         << "\n";
    cout << "3. Cate matrici au fost create?."
         << "\n";
    cout << "4. Downcast."
         << "\n";
    cout << "5. Verificare matrice diagonala?" << endl;
    cout << "0. Iesire."
         << "\n";
}
void tip(Matrice *&M, int &i)
{
    string s;
    cout << "\n";
    cout << "Introduceti tipul matricei, oarecare sau patratica, cu numarul  " << i + 1 << ": ";
    cin >> s;
    try
    {
        if (s == "oarecare")
        {
            M = new Matrice_oarecare;
            cin >> *M;
            i++;
        }
        else if (s == "patratica")
        {
            M = new Matrice_patratica;
            cin >> *M;
            i++;
        }
        else
            throw 100;
    }
    catch (bad_alloc var)
    {
        cout << "Eroare de alocare\n";
        exit(EXIT_FAILURE);
    }
    catch (int j)
    {
        cout << "Gresit. Incercati oarecare sau patratica.\n ";
    }
}
int main()
{
    system("CLS");
    int option;
    int n;
    bool iesire = false;
    Matrice **H;
    Matrice_patratica *a = (Matrice_patratica *)new Matrice;
    Matrice_patratica N;
    do
    {
        menu_output();
        cin >> option;
        switch (option)
        {
        case 0:
            cout << endl;
            cout << "\tExit" << endl;
            iesire = true;
            return 0;

        case 1:
            cout << "Introduceti numarul de matrici: ";
            cin >> n;
            try
            {
                H = new Matrice *[n];
                for (int i = 0; i < n;)
                    tip(H[i], i);
            }
            catch (bad_alloc var)
            {
                cout << "Eroare de alocare\n";
                exit(EXIT_FAILURE);
            }
            break;
        case 2:
            cout << "\nAfisam matricile citite anterior:\n";
            for (int i = 0; i < n; i++)
            {
                cout << "\n"
                     << *H[i];
                cout << "--------------------------\n";
            }
            break;
        case 3:
            cout << "Numarul de matrici create: ";
            Matrice::numarMatrici();

            break;
        case 4:
            cout << "downcast";
            cin >> *a;
            cout << "--?----------------\n";
            cout<< " Nu se citeste nimic. In loc sa citeasca o matrice patratica, incearca sa citeasca un obiect din clasa matrice, dar clasa matrice\n"
            cout<<" nu are nimic in functia de citire si in supraincarcare, de aici si cauza erorii"<<endl;
            cout << *a;
            break;
        case 5:
            cout << " Introduceti matricea pentru testare: ( trebuie sa fie patratica) " << endl;
            cin >> N;
            if (N.trisup() == true || N.triinf() == true)
                cout << "Matricea este triunghiulara" << endl;
            else
                cout << "Matricea nu este triunghiulara" << endl;
            if (N.verificarediag() == true)
                cout << "Matricea este diagonala" << endl;
            else
                cout << "Matricea nu este diagonala" << endl;
            break;
        default:
            cout << "Optiune invalida";
            break;
        }
        cout << "\nApasa ENTER pentru a continua...";
        cin.get();
        cin.get();
        if (iesire)
            break;
        system("CLS");

    } while (true);
    return 0;
}
