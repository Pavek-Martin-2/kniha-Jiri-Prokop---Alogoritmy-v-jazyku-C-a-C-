#include <stdio.h>

/*
program pro vytvoreni desifrovaciho klice
program cte anglicky text "holmes.txt" a zjisti frekvenci vyskytu pismen
(26 znaku) bez rozlisovani na mala a velka pismena
Abeceda se pak setridi vzestupne a toto poradi pismen je
vystupem "desifr_klic.txt" programu. pouzije se pak pro
rozsifrovani zasifrovaneho textu ( vstup pro program prolomeni )

moje: do souboru "desifr_klic.txt" pise ale nejak nesmysli (rozsypanej caj)
*/

void bubble (int p[], int q[], int n)
// trideni pole vymenou - bubblesort
{
int i,j;
int x;
for (i=1;i<n;i++)
{
for (j=n-1; j>=i; j--)
{
if (p[j-1] > p[j])
{
x=p[j-1];
p[j-1]=p[j];
p[j]=x;
q[j-1]=q[j];
q[j]=x;
}
}
}
}

int main()
{
FILE *text;
FILE *dekod;
char *jmeno="holmes.txt";
char *vystup="desifr_klic.txt";
int abc[26];
int pocty[26];
int i,z;

if ((text=fopen(jmeno,"rb"))==NULL)
{
printf("nemohu otevrit vstupni soubor \"holmes.txt\"\n");
system("pause");
return 1;
}

for(i=0;i<26;i++)
{
abc[i]=i+97;
pocty[i]=0;
}
while((z=getc(text)) != EOF)
{
if ((z>96)&&(z<123))
pocty[z-97]++;
if ((z>64)&&(z<91))
pocty[z-65]++;
}
fclose(text);

// setrideni abecedy podle poctu vyskytu jednotlivych pismen
bubble(pocty,abc,26);
if ((dekod=fopen(vystup,"wb"))==NULL)
{
printf("nemohu otevrit vystupni \"desifr_klic.txt\"\n");
system("pause");
return 1;
}

for (i=0;i<26;i++)
putc(abc[i],dekod); // zapisuje
fclose(dekod);
printf("vystupem je soubor \"desifr_klic.txt\"\n");

system("pause");
return 0;
}

