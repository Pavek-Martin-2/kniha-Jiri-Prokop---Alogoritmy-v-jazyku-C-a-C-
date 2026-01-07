#include <stdio.h>
#include <stdlib.h>

/* 
sudoku
kazdy sloupec, radek i ctverec o 3x3 polich musi
obsahovat veschny cislice 1-9
program cte vstup ze souboru "txt" (sudoku_2_vstup.exe)
potom zobrazi vstupni i vyslednou matici 9x9
pak zadejte nulu
*/

FILE *fr;
short m[9][9];
short i,j,k,dost,n;
short e,f;   // hodnoty urcuji zpusob prace funkce oznac
short r[81]; // zazanamy doplnenych cisel pro bactracking
short s[81]; // do pole r se zaznamenava i, do s j
short t[81]; // do pole t se zaznamenava k
short p[9][9][9]; //p[i][j][k] nenulove znamena, ze hodnota, k je nepristupna pro policko m[i][j]

// vstupni soubor definovany pomoci - sudoku_2_vstup.exe
char *jmeno="sudoku_2.txt";

int oznac(short u, short v, short x)
{
short i,j;
// radek
for (i=0;i<9;i++)
if (p[u][i][x]==e) p[u][i][x]=f;

// sloupec
for (i=0;i<9;i++)
if (p[i][v][x]==e) p[i][v][x]=f;

// ctverecek 3x3	
if (u<3) u=0;
else if (u<6) u=3; else u=6;

if (v<3) v=0;
else if (v<6) v=3; else v=6;

for (i=u;i<u+3;i++)
for (j=v;j<v+3;j++)
if (p[i][j][x]==e) p[i][j][x]=f;
return 0;	
}
                  
int main()
{
// cteni zadani
if ((fr=fopen(jmeno,"rt"))==NULL) 
{
printf("soubor nelze otevrit\n");
printf(jmeno);
printf("\n");
system("pause");
return 1;
}

for (i=0;i<9;i++)
for (j=0;j<9;j++)
fscanf(fr,"%d",&m[i][j]);
// vstupni zadani
printf("\nzadani\n");
for (i=0;i<i<9;i++)
{
for (j=0;j<9;j++)
printf("%d",m[i][j]);
printf("\n");
}
// hodnoty pole p
e=0; f=1;
for(i=0;i<9;i++)
for(j=0;j<9;j++)
if (m[i][j]>0) oznac(i,j,m[i][j]);
// v cyklu hledam policka k doplnovani
n=0; k=1;
i=0; j=0;
while(i<9)
{
if (m[i][j]==0)
{
dost=0;
while ((k<10) && (dost==0)) // AND podminka v C#
{
if (p[i][j][k]==0)
{
m[i][j]=k; e=0; dost=1;
r[n]=i; s[n]=j; t[n]=k; n++; f=n+1; oznac(i,j,k);
}
else k++;
}
if (dost==0) // navat zpet
{
do
{
n--;
if(n<0)
{
printf("neexistuje reseni\n");
scanf("%d,&e");
return 1;
}
else
{
i=r[n]; j=s[n]; k=t[n]; e=n+2; f=0;
oznac(i,j,k); m[i][j]=0; k++;
}
}
while (k>=10);
continue;
}
}
k=1; j++; if(j>=9) {i++; j=0;}
}

printf("\nvysledek\n");
for(i=0;i<9;i++)
{
for (j=0;j<9;j++)
printf("%d",m[i][j]);
printf("\n");
}

system("pause");
return 0;
}

