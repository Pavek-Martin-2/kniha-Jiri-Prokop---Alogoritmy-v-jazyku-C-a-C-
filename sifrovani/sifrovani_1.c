#include <stdio.h>

/*
 jednoducha monoalfabeticka substitucni sifra, puvodni z knizky
 program zakoduje vstupni text pomoci sifrovaciho klice "sifr_klic.txt"
 ktery je libovolnou permutaci pismen anglicke abecedy
 na vystup "sifrov.txt" zapise zasifrovany text
*/

int main() {

FILE *text;
FILE *koder;
FILE *vystup;
char *jmeno = "holmes.txt";
char *kod = "sifr_klic.txt";
char *vyst = "sifrov.txt";
int abc[26]; // abeceda
int bac[26]; // permutace abecedy
int pocty[26]; // pocet vyskytu jednotlivich pismen
int i,j,z;
for (i=0;i<26;i++)
{
abc[i]=i+97;
pocty[i]=0;	
}

if ((koder=fopen(kod,"rb"))==NULL)
{
printf("nemohu otevrit soubor \"sifr_klic.txt\"\n");
system("pause");
return 1;
}

i=0;
while ((z=getc(koder))!=EOF)
{
bac[i]=z;
i++;	
}
fclose(koder);

if ((vystup=fopen(vyst,"wb"))==NULL)
{
printf("nemohu otevrit vystupni soubor \"sifrov.txt\"\n"); // zapis do oblasti ReadOnly apod.
system("pause");
return 1;
}

if((text=fopen(jmeno,"rb"))==NULL)
{
printf("nemohu otevrit vstupni soubor \"holmes.txt\"\n");
system("pause");
return 1;	
}

while((z=getc(text))!=EOF)
{
printf("%c ",z); // puvodni z knizky
//printf("%c",z); // moje uprava
j=1;
for(i=0;i<26;i++)
if ((z==abc[i]) || (z+32==abc[i]))
{
putc(bac[i],vystup);
j=0;
}

if (j==1) putc(z,vystup);
}
fclose(text);
fclose(vystup);
printf("\n\n");
printf("vystupem je soubor \"sifrov.txt\"\n");
system("pause");
return 0;
}

