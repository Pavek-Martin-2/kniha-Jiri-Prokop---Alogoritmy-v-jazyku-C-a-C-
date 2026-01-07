#include <iostream>
#include <iomanip>
using namespace std;

// nasobeni matic, podle knizky Prokop

#define MNOHO 9999
long int m[20][20];
int s[20][20];
int p[20],i,j,n;

void tisk_vysl(int i, int j)
{
if (i==j)
cout<<" A"<<i;
else
{
cout<<"(";
tisk_vysl(i,s[i][j]);
tisk_vysl(s[i][j] + 1, j);
cout<<")";
}	
}

void nasobeni(void)
{
long int q;
int k;
cout<<"poradi vypoctu: "<<endl;
for(i=n; i>0; i--);
{
for (j=i; j<=n; j++)
if(i==j)
m[i][j]=0;
else
{
for(k=i; k<j; k++)
{
q=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
if(q < m[i][j])
{
m[i][j]=q;
cout<<i<<" "<<j<<" "<<q<<endl;
s[i][j]=k;	
}	
}	
}	
}
}

int main()
{
int k;
cout<<"zadej pocet matic: ";
cin>>n;

for(i=1; i<=n; i++)
for(j=i+1; j<=n; j++)
{
m[i][i]=0;
m[i][j]=MNOHO;
m[i][j]=0;	
}
cout<<endl<<"zadej rozmery matic: "<<endl;
for(k=0; k<=n; k++)
cin>>p[k];
nasobeni();
cout<<endl<<"vysledna matice M:"<<endl;
for(i=1; i<=n; i++)
{
for(j=i; j<=n; j++)
cout<<setw(4)<<m[i][j];	// setw(4) ???
cout<<endl;
}
for(i=1; i<=n; i++)
for(j=i; j<=n; j++)
cout<<"m["<<i<<"]["<<j<<"]:"<<m[i][j]<<endl;
cout<<endl<<"matice S pro hodnoty k:"<<endl;
for(i=1; i<=n; i++)
for(j=i; j<=n; j++)
cout<<"s["<<i<<"]["<<j<<"]:"<<s[i][j]<<endl;
cout<<endl<<"pocet nasobeni: "<<m[1][n]<<endl;
cout<<endl<<"matice S pro hodnoty k :"<<endl;
for(i=1; i<=n; i++)
{
for(j=i; j<=n; j++)
cout<<setw(4)<<s[i][j]; //setw(3) puvodne
cout<<endl;
}

i=1,j=n;
cout<<endl<<"poradi nasobeni: ";
tisk_vysl(i,j);
cout<<endl;

system("pause");
return 0;
}

