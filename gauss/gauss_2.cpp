#include <iostream>
#include <math.h>
// gauss

using namespace std;
const int n=4;
double x[n];

// matice
double a[n][n+1]={
{1,1,1,1,1},
{2,2,3,1,1},
{2,4,4,3,5},
{2,5,5,1,5}
};

int TiskMat()
// tisk matice typu n x (n+1) po radcich
{
int i,j;
for (i=0;i<n;i++)
{
for(j=0;j<=n;j++)
cout<<a[i][j]<<" ";
cout<<endl;	
}
}

int gauss(double a[n][n+1], double x[n])
{
int max,i,j,k;
int u,v;
cout<<"puvodni zadana matice"<<endl;
TiskMat(); // kontrolni vystup zadane matice

double pom;
for(i=0; i<n; i++) // eliminace
{
max=i;
for(j=i+1; j<n; j++)
if(fabs(a[j][i])>fabs(a[max][i]))
max=j;
cout<<"vymena radku "<<i<<" a "<<max<<endl;
if (max!=i) // nerovnost
for (k=i; k<n+1; k++) // vymena radku
{
pom=a[i][k];
a[i][k]=a[max][k];
a[max][k]=pom;
}

cout<<"upravena matice"<<endl;
TiskMat(); // kontrolni vypis upravene matice
if(a[i][i]==0)
return 0; // soustava je singularni
for(j=i+1; j<n; j++)
for (k=n; k>=i; k--) // nasobeni a soucet radku
a[j][k]=a[j][k]-a[i][k]*a[j][i]/a[i][i];
}

// zpetni chod
x[j]=0;
for(int j=n-1; j>=0; j--)
{
pom=0;
for(int k=j+1 ;k<n; k++)
pom=pom+a[j][k]*x[k];
x[j]=(x[j]+a[j][n]-pom)/a[j][j];
}
return 1; // OK
}

int main(){

if(!gauss(a,x))
cout<<"soustava (1) je singularni"<<endl;
else
{
cout<<"reseni:"<<endl;
for(int i=0; i<n; i++)
cout<<"x=["<<i<<"]="<<x[i]<<endl;

system("pause");
return 0;
}

}

