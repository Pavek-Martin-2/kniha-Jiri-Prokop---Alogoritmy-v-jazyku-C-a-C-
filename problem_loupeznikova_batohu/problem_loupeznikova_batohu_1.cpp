#include <iostream>
using namespace std;

// loupeznikuv batoh unese nejvyse n kg lupu
// loupeznik vybira z p cennych veci o hmotnosti m[i] a cene c[i]

int main(){

int n; // kolik kg smi obsahovat loupeznikuv batoh
int p; // pocet cennych veci
int i, j;
int m[50]; // hmotnosti predmetu
float c[50]; // ceny predmetu

float batoh [50][100];
// batoh [i][j] je cena obsahu batohu o kapacite "j"
// kdyz jsme vzali v uvahu prvnich "i" predmetu

cout<<"hmotnost loupeznikova batohu: ";
cin>>n;

cout<<endl<<"pocet predmetu: ";
cin>>p;

cout<<endl<<"hmotnosti a ceny predmetu: "<<endl;
for(i=1; i<=p; i++)
cin>>m[i]>>c[i]; // na kazdej radek jednu cifru

for(j=0; j<=n; j++)
batoh[0][j] = 0;

for(i=1; i<=p; i++)
/*
postupne pridavame i-ty predmet do batohu s (i-1) predmety
a kapacitou nizsi o hmotnost i-teho predmetu
predmet nepridame, pokud cena neni vyssi nez cena prvnich (i-1)
predmetu v batohu se stejnou kapacitou
*/
{
for(j=0; j<m[i]; j++)
batoh[i][j]=batoh[i-1][j];
for(j=m[i]; j<=n; j++)
if(batoh[i-1][j] > batoh[i-1][j-m[i]] + c[i])
batoh[i][j] =batoh[i-1][j];
else batoh[i][j] =batoh[i-1][j-m[i]] + c[i];
}

cout<<"cena: "<<batoh[p][n]<<endl<<"predmety:"<<endl;
// i-ty predmet byl pouzit, jestlize zvysil cenu lupu
// v batohu stejne nosnosti bez tohoto predmetu

j=n;
for(i=p; i>=0; i--)
if(batoh[i][j] > batoh[i-1][j])
{
cout<<" "<<i<<" "<<endl;
j=j-m[i];
}

// mezivysledky
for(i=0; i<=p; i++)
{
for(j=1; j<=n; j++)
cout<<batoh[i][j]<<" ";
cout<<endl;
}

//cin>>i; // puvodne bylo v knizce asi jako pause

system("pause");
return 0;
}

