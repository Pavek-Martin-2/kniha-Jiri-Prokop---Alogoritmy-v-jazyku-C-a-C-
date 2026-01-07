#include <stdio.h>
/*
pruchod stavovym prostorem
na sachovnici o rozmeru m x n hledame nejkratsi cestu kone
ze zadaneho vychoziho pole do koncoveho zadaneho pole
vypiseme (odzadu) jednu z moznych nejkratsich cest
pouzita metoda: prohledavani do sirky (algoritmus vlny)
*/
#define DIM 256
int a[DIM]; // sachovnice o rozmerech m x n, ulozena po radcich
int p1[8]={1,2,2,1,-1,-2,-2,-1}; // konstanty pro generovani
int p2[8]={2,1,-1,-2,-2,-1,1,2}; // pripustnych tahu kone
int z1,z2; // vychozi pozice kone
int k1,k2; // cilova pozice kone
int i,j,k,d,s1,s2,r1,r2;
int m,n; // rozmery sacovnice
int fr1[DIM]; int fr2[DIM]; // fronta pro souradnice
int zac,kon,pocet; // pro frontu

int main()
{
L:
printf("zadej rozmery sachovnice\n");
scanf("%d",&m); scanf("%d",&n); // m-pocet radku, n-pocet sloupcu

printf("zadej pocatecni pozici kone\n");
scanf("%d%d",&z1,&z2); // index radku, index sloupce

printf("zadej cilovou pozici kone\n");
scanf("%d%d",&k1,&k2); // index radku, index sloupce

d=m*n; // pole je indexovano od nuly
if ((d>DIM) || (z1<0) || (z2<0) || (k1<0) || (k2<0) || (z1>=m) || (z2>=n) || (k1>=m) || (k2>=n))
{
printf("zadejte to rozumneji\n"); goto L; // jump na Label L: (a pak ze prej neumim anglicky !)	
}
for (i=0; i<d; i++) a[i]=0; // nulovani pozice
zac=kon=pocet=0; // inicializace fronty (moje pozn. hezka konstrukce toto, vydim poprve :)
a[z1*n+z2]=1; // oznaceni vychoziho pole

// vlastni algoritmus vlny
fr1[kon]=z1; fr2[kon]=z2; kon++; pocet++; j=1; // do fronty

while(pocet>0)
{
s1=fr1[zac]; s2=fr2[zac]; pocet--; zac++; // do fronty
j=a[s1*n+s2];
for(i=0; i<8; i++)
{
r1=s1+p1[i]; r2=s2+p2[i];
if((r1>=0) && (r1<m) && (r2>=0) && (r2<n) && (a[r1*n+r2]==0)) // jsem na sachovnici ?
{
a[r1*n+r2]=j+1;
fr1[kon]=r1; fr2[kon]=r2; pocet++; kon++; // do fronty
if((r1==k1) && (r2==k2)) goto L2;
}
}
}

L2:
printf("vysledek:\n");
for(i=0; i<m; i++)
{
for(j=0; j<n; j++)
printf("%2d ",a[i*n+j]);
printf("\n");	
}

if (a[k1*n+k2]!=0)
{
// zobrazeni jedne z moznych cest (pozpatku)
printf("cesta kone (pozpatku):\n");
printf("%d %d\n",k1,k2);
printf("%d %d\n",s1,s2);
j=a[k1*n+k2]-2;

while(a[s1*n+s2]!=1);
// opakuj cyklus dokavad nebude splnena podminka ze vyraz se nerovana 1
{
for(i=0; i<8; i++)
{
r1=s1+p1[i]; r2=s2+p2[i];
if((r1>=0) && (r1<m) && (r2>=0) && (r2<n) && (a[r1*n+r2]==j))
break;
}

s1=r1; s2=r2; j--;
printf("%d %d\n",s1,s2);
}
}
else
printf("uloha nama reseni");

system("pause");
return 0;
}

