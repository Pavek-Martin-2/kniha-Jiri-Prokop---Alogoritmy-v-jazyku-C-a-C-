#include <stdio.h>

/*
 prolomeni sifry
 program cte zasifrovany text a dekoder. Pocty vyskytu pismen
 v tomto textu se ulozi do pole pocty. Precte se "desifr_klic.txt"
 a ulozi do pole bac, ktere spolu s polem abc po setrideni
 slouzi jako desifrovaci klic pro rozsifrovani textu. Ten se
 pak zapise do vystupniho souboru "rozsifr.txt"
*/

void bubble(int p[], int q[], int n)
// trideni pole vymenou - bubblesort
{
int i,j;
int x;
for (i=1;i<n;i++)
{
for (j=n-1;j>=i;j--)
{
if (p[j-1] > p[j])
{
x=p[j-1];
p[j-1]=p[j];
p[j]=x;
x=q[j-1];
q[j-1]=q[j];
q[j]=x;
}
}
}
}

int main()
{
FILE *sifr;
FILE *des;
FILE *rozsif;
char *sif="sifrov.txt";
char *desif="desifr_klic.txt";
char *vyst="rozsifr.txt";
int abc[26]; // abeceda
int bac[26]; // permutace abecedy
int pocty[26]; // pocty vyskytu jednotlivich pismen
int i,z,j;

for (i=0;i<26;i++)
{
abc[i]=i+97; // angl. abeceda - mala pismena
pocty[i]=0;
}

// precteme desifr_klic.txt
if ((des=fopen(desif,"rb")) == NULL)
{
printf("nemohu otevrit vstupni soubor \"desifr_klic.txt\"\n");
system("pause");
return 1;
}

i=0;
while((z=getc(des)) != EOF )
{
bac[i]=z; i++;	
}
fclose(des);

// cteme zasifrovany text a pocitame vyskyt pismen
if ((sifr=fopen(sif,"rb")) == NULL)
{
printf("nemohu otevrit vstupni soubor \"sifrov.txt\"\n");
system("pause");
return 1;
}

while ((z=getc(sifr)) != EOF)
{
if ((z>96) && (z<123))
pocty[z-97]++;
if ((z>64) && (z<91))
pocty[z-65]++;		
}
fclose(sifr);

// setrideni abecedy podle poctu vyskytu jednotlivych pismen
bubble (pocty,abc,26);
if ((rozsif=fopen(vyst,"wb")) == NULL)
{
printf("nemohu otevrit vystupni soubor \"rozsifr.txt\"\n");
system("pause");
return 1;
}

if ((sifr=fopen(sif,"rb")) == NULL)
{
printf("nemohu otevrit vstupni soubor \"sifrov.txt\"\n");
system("pause");
return 1;
}

while((z=getc(sifr)) != EOF)
{
j=1;
for(i=0;i<26;i++)
{
if ((z==abc[i]) || (z+32==abc[i]))
{ putc(bac[i],rozsif); j=0;}
}
if (j==1) putc(z,rozsif);
}

fclose(sifr);
fclose(rozsif);
printf("vystupem je soubor \"rozsif.txt\"\n");

system("pause");
return 0;
}

