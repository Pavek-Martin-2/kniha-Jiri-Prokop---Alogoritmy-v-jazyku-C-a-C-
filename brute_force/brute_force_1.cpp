#include <iostream>
#include <string.h> // kvuli funkci strlen()
using namespace std;

// brute force alogoritmus

void hledej(char *v, char *t)
{
int i=0, j=0, m=strlen(v), n=strlen(t);
while(i<n)
{	
while(j<m && i<n)
{
if(t[i]!=v[j])
{
i-=j;
j=-1;
}
i++; j++;
}
if(j==m)
cout<<"vysledek "<<i-m<<endl;
j=0;
}
}

int main()
{
char *text="abrakadabraka";
char *vzorek="rak";

hledej(vzorek, text);
	
system("pause");
return 0;
}

