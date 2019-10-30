#include <iostream>

using namespace std;

class Vector{
private:
    int n; //dimensiunea vectorului
    int *vec; //pointer catre zona de memorie alocata
public:
    Vector(); //constructor implicit
    Vector(int); //constructor parametrizat pentru atribuirea numarului de elemente si initializarea elementelor cu 0
    Vector(int,int); //constructor parametrizat pentru atribuirea a n elemente (n dat) cu un anumit numar
    Vector(const Vector&); //constructor de copiere
    ~Vector(); //destructor

    void citire();
    void afisare();
    void react_si_init(int n1,int x); //functie pentru reactualizarea nr. de componente si initializarea acestora cu un numar dat
    int suma_elem();
    void maxim();
    void sortare();

    friend ostream& operator << (ostream&, Vector&);
    friend istream& operator >> (istream&, Vector&);
    Vector& operator=(const Vector&);
    friend int operator *(Vector, Vector);
};

Vector::Vector(){ //constructor de initializare
    this->n=0;
    this->vec=0;
}

Vector::Vector(int n){ //constructor parametrizat
    this->n=n;
    this->vec=new int[n+1];
    for(int i=1;i<=n;i++)
        this->vec[i]=0;
}

Vector::Vector(int n,int x){ //constructor de init. cu un nr dat
    this->n=n;
    this->vec=new int[n+1];
    for(int i=1;i<=n;i++)
        this->vec[i]=x;
}

Vector::Vector(const Vector& v){ //constructor de copiere
    int i;
    this->n=v.n;
    this->vec=new int[n+1];
    for(i=1;i<=n;i++)
        this->vec[i]=v.vec[i];
    cout<<"CC"<<endl;
}

Vector::~Vector(){ //destructor
    n=0;
    if (vec!=0) delete[] vec;
    cout<<"D"<<endl;
}

void Vector::citire(){
    cout<<"Introduceti numarul elementelor vectorului:";
    cin>>n;
    this->vec=new int[n+1];
    cout<<"Introduceti elementele vectorului:"<<endl;
    int i;
    for(i=1;i<=n;i++)
        cin>>vec[i];
}

void Vector::afisare(){
    int i;
    for(i=1;i<=n;i++)
        cout<<vec[i]<<" ";
    cout<<endl;
}

void Vector::react_si_init(int n1,int x){
    n=n1;
    vec=new int[n1+1];
    for(int i=1;i<=n1;i++)
        vec[i]=x;
}

int Vector::suma_elem(){
    int s=0;
    for(int i=1;i<=n;i++)
        s=s+vec[i];
    return s;
}

void Vector::maxim(){
    int Maxim=vec[1];
    int poz=0;
    for(int i=2;i<=n;i++)
        if(vec[i]>Maxim)
        {
            Maxim=vec[i];
            poz=i;
        }
    cout<<"Maximul din vector este "<<Maxim<<", iar pozitia sa este "<<poz<<endl;
}

void Vector::sortare(){ //BubbleSort
    int aux,i,ord=0;
    do
    {
        ord=1;
        for(i=1;i<=n-1;i++)
            if(vec[i]>vec[i+1])
            {
                aux=vec[i];
                vec[i]=vec[i+1];
                vec[i+1]=aux;
                ord=0;
            }
    }
    while(ord==0);
}

ostream& operator << (ostream& out, Vector& ob){ //supraincarcarea op <<
    int i;
    for(i=1;i<=ob.n;i++)
        out<<ob.vec[i]<<" ";
    out<<endl;
    return out;
}

istream& operator >> (istream& in, Vector& ob){ //supraincarcarea op >>
    cout<<"Numarul elementelor vectorului este:";
    in>>ob.n;
    ob.vec=new int[ob.n+1];
    cout<<"Elementele din vector sunt:"<<endl;
    for(int i=1;i<=ob.n;i++)
        in>>ob.vec[i];
    return in;
}

int operator*(Vector v1, Vector v2){
    int s=0;
    int i;
    if(v1.n!=v2.n)
        return -1;
    else
    {
        for(i=1;i<=v1.n;i++)
            s+=v1.vec[i]*v2.vec[i];
        return s;
    }
}

Vector& Vector::operator=(const Vector& v)
{
    if(this!=&v)
    {
        n=v.n;
        vec=new int[n+1];
        for(int i=1;i<=n;i++)
            vec[i]=v.vec[i];
    }
    return *this;
}

class N_vectori{ //pentru citirea, memorarea si afisarea a n vectori
private:
    int nr_vec;
    Vector *v;
public:
    ~N_vectori(){
    nr_vec=0;
    if (v!=0) delete[] v;
    cout<<"DD"<<endl;
    };
    friend istream& operator >> (istream&, N_vectori&);
    friend ostream& operator << (ostream&, N_vectori&);
};

//supraincarcarea citirii pentru n vectori
istream& operator >> (istream& in, N_vectori& ob){
    cout<<"Numarul de vectori pe care vrei sa il introduci:";
    in>>ob.nr_vec;
    ob.v=new Vector[ob.nr_vec+1];
    for(int i=1;i<=ob.nr_vec;i++)
        in>>ob.v[i];
    return in;
}

//supraincarcarea afisarii pentru n vectori
ostream& operator << (ostream& out, N_vectori& ob){
    int i;
    for(i=1;i<=ob.nr_vec;i++)
        out<<ob.v[i]<<" ";
    out<<endl;
    return out;
}

int main()
{
    //apelare constructor parametrizat cu un anumit numar de componente
    /*Vector v(5);
    cout<<"Vectorul construit este:"<<endl;
    v.afisare();
    //cout<<v;*/

    //apelare constructor parametrizat pentru initializarea  cu  un  numar  dat  pe  toate  componentele
    /*Vector v(5,7);
    cout<<"Vectorul construit este:"<<endl;
    v.afisare();
    //cout<<v;*/

    //apelare functie de reinitializare si actualizare
    /*Vector v;
    v.react_si_init(10,5);
    cout<<"Vectorul construit este:"<<endl;
    v.afisare();
    //cout<<v;*/

    //apelare functie suma tuturor elementelor
    /*Vector v;
    v.citire();
    //cin>>v;
    cout<<"Suma elementelor este :"<<v.suma_elem()<<endl;*/

    //apelare functie maxim si afisarea pozitiei acestuia
    /*Vector v;
    v.citire();
    //cin>>v;
    v.maxim();*/

    //apelare functie sortare
    /*Vector v;
    v.citire();
    //cin>>v;
    v.sortare();
    cout<<"Vectorul sortat este:"<<endl;
    v.afisare();
    //cout<<v;*/

    //apelare pentru produs scalar
    /*Vector v1;
    Vector v2;
    v1.citire();
    //cin>>v1;
    v2.citire();
    //cin>>v2;
    int s=v1*v2;
    cout<<s<<endl;*/

    //pentru metoda-operator de atribuire
    /*Vector v1;
    Vector v2;
    v1.citire();
    //cin>>v1;
    v2.citire();
    //cin>>v2;
    v1=v2;
    cout<<"Vectorul modificat este:"<<endl;
    v1.afisare();
    //cout<<v1;*/

    //pentru citirea si afisarea a n obiecte
    /*N_vectori vect;
    cin>>vect;
    cout<<vect;*/
    return 0;
}
