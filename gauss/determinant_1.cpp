#include <iostream>
#include <math.h>
using namespace std;

// determinat

double det;
const int N=3;
double x[N];
// matrix
double a[N][N]={
{2, 3, 5}, // [0][0], [0][1], [0][2]
{1, 1, 2}, // [1][0], [1][1], [1][2]
{3, 1, 1} //  [2][0], [2][1], [2][2]
};

int main(){
//cout<<a[2][2]<<endl; moje pokus
int max,i,j,k;
int u,v;
for (u=0; u<N; u++) // kontrolni vypis matice
{ for(v=0; v<N; v++)
cout<<a[u][v]<<" ";
cout<<endl;
}

double pom;
// eliminace
for(i=0; i<N; i++)
{
max=i;
for (j=i+1; j<N; j++)
if(fabs(a[j][i]) > fabs(a[max][i]))
max=j;
cout<<"vymena radku "<<i<<" a "<<max<<endl;
if (i!=max)
for (k=i; k<N; k++) // vymena radku
{
pom=a[i][k];
a[i][k]=a[max][k];
a[max][k]=pom;
}

cout<<"upravena matice"<<endl;
for (u=0; u<N; u++) // kontrolni vypis upravene matice
{ for (v=0; v<N; v++)
cout<<a[u][v]<<" ";
cout<<endl;
}

det=0.1;
if (a[i][i]!=0)
{
for(j=i+1; j<N; j++)
for(k=N-1; k>=i; k--) // nasobeni a soucet radku
a[j][k]=a[j][k]-a[i][k]*a[j][i]/a[i][i];
}
else det=0.0;
}

for (int u=0; u<N; u++)
det=det*a[u][u];
cout<<"reseni:"<<endl;
cout<<"determinant = "<<det<<endl;

system("pause");
return 0;
}


