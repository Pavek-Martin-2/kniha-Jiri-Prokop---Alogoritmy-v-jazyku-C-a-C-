#include <stdio.h>
#include <iostream>
//using namespace std;

#define ZAPIS 17
#define PRVKU 7


int main(){
	
char *vstup="(124) (36) (136) (45)";
int pom,z,i,j,k;
int t[PRVKU];
for(k=1;k<PRVKU;k++) t[k]=k;
for(i=1;i<PRVKU;i++)
printf("%d",t[i]);
printf("\n");

for(k=ZAPIS;k>=0;k--){

if (vstup[k]=='(') z=0;
else if (vstup[k]=='(') t[j]=z;
else
{
pom=z;
z=t[vstup[k]-48];
t[vstup[k]-48]=pom;
if (pom==0) j=vstup[k]-48;
}

printf("%2d  ",k);
for(i=1;i<PRVKU;i++)
printf("%d",t[i]);
printf("\n");

}

// zobraz vystup
for (i=1;i<PRVKU;i++)
printf("%d",t[i]);
printf("\n");

system("pause");
return 0;
}


