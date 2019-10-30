
#include <iostream>

using namespace std;

class Graf
{
    int a[11][11], n, m;
public:
    Graf ();
    Graf (int m_ad[11][11]);
    Graf (const Graf&);
    ~Graf ();
    friend istream & operator >> (istream &, Graf&);
    friend ostream & operator << (ostream &, Graf&);
};

class NrObiecte
{
    int n;
    Graf *v;
public:
    friend istream& operator >> (istream&, NrObiecte&);
    friend ostream& operator << (ostream&, NrObiecte&);
};

istream& operator >> (istream& in, NrObiecte& n)
{
    in>>n;
    for (int i=0; i<n; i++)
        in>>v[i];
}

ostream& operator << (ostream& out, NrObiecte& n)
{
    for (int i=0; i<n; i++)
        out<<v[i]<<" ";
}

Graf :: Graf ()
{
    for (int i=1; i<=10; i++)
        for (int j=1; j<=10; j++)
            if (i==j)
                a[i][j]=0;
            else
                a[i][j]=10000000000;
}

Graf :: Graf (int m_ad[11][11])
{
    for (int i=1; i<=10; i++)
        for (int j=1; j<=10; j++)
            a[i][j]=m_ad[i][j];
}

Graf :: Graf (const Graf& g)
{
    for (int i=1; i<= 10; i++)
        for (int j=1; j<=10; j++)
            a[i][j]=g.a[i][j];
    n=g.n;
    m=g.m;
}

Graf :: ~Graf ()
{
    for (int i=1; i<= 10; i++)
        for (int j=1; j<=10; j++)
            delete a[i][j];
}

istream & operator >> (istream & in, Graf & g)
{
    int x, y;
    in>>n>>m;
    for (int i=1; i<=m; i++)
    {
        in>>x>>y>>g.a[x][y];
        g.a[y][x]=g.a[x][y];
    }
    return in;
}

ostream & operator << (ostream & out, Graf & g)
{
    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=n; j++)
            out<<g.a[i][j]<<" ";
        out<<endl;
    }
    return out;
}

void ParcurgereLatime (int n_start)
{
    int viz[10]= {0};
    comp++;
    viz[n_start]=1;
    cout<<"Componenta conexa : "<<comp<<" este formata din nodurile :";
    cout<<ns<<" ";
    prim=ultim=1;
    c[ultim]=n_start;
    while(prim<=ultim)
    {
        for(int i=1; i<=n; i++)
            if(a[c[prim]][i]==1)
                if(v[i]==0)
                {
                    ultim++;
                    c[ultim]=i;
                    cout<<i<<" ";
                    v[i]=1;
                }
        prim++;
    }
    cout<<endl;
}

void ParcurgereAdancime (int n_start)
{
    int viz[10]= {0};
    viz[n_start]=1;
    for(int i=1; i<=n; i++)
        if (a[n_start][i]==1 && viz[i]==0)
            ParcurgereAdancime(i);
}

void MatrPonderiMinime()
{
    for (int k=1; k<=n; k++)
        for (int i=1; 1<=n; i++)
            for (int j=1; j<=n; j++)
                if(a[i][j]>a[i][k]+a[k][j])
                    a[i][j]=a[i][k]+a[k][j];

}

void DescompunereDrum (int i, int j)
{
    int ok=0, k=1;
    while (k<=n&&ok!=0)
    {
        if (i!=k&&j!=k)

            if (a[i][j]==a[i][k]+a[k][j])
            {
                DescompunereDrum (i, k);
                DescompunereDrum(j, k);
                ok=1;
            }
        k++;
    }
    if(ok!=0)
        cout<<j;

}

void ScriereDrumPondereMin(int nod_init,int nod_fin)
    if(a[nod_init][nod_fin]<10000)
    {
        cout<<"Lantul de la "<<nod_init<<" la "<<nod_fin<<" are lungimea "<<a[nod_init][nod_fin]<<" .";

        cout<<endl<<"Drumul de pondere minima este: "<<endl;

        cout<<nod_init<<" ";

        descompun_drum(nod_init,nod_fin);
    }
    else
        cout<<"Nu exista drum de la "<<nod_init<<" la "<<nod_fin<<" .";
}

void VerificaGrafConex ()
{
    ParcurgereAdancime(1);
    for(int i=1; i<=n; i++)
        if (viz[i]==0)
            return 0;
    return 1;
}

int main()
{

    return 0;
}

