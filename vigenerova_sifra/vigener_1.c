#include <stdio.h>

// vigenerova sifra, puvodni z knizky

#define DELKA 24
#define DEL_KLICE 6

char text[DELKA] = "tohlechcivsemlidemutajit";
//                  123456789012345678901234
char sifra [DELKA];
char klic[6]="vigenr";
char heslo [DELKA];
int i,j,w;

int main(){
// vkladani pismen do tabulky heslo
i=0;
for(j=0;j<DELKA;j++)
{
heslo[j]=klic[i]; i++; if (i==DEL_KLICE) i=0;
}
	
// sifrovani
w=0;
for(j=0;j<DELKA;j++)
{
sifra[w]=(text[j]-97>122-heslo[j])? // co znamena znak "?" !!!
text[j]-123+heslo[j]:text[j]-97+heslo[j];
w++;
}

printf("vysledek sifrovani:\n");
for(i=0;i<DELKA;i++)
printf("%c",sifra[i]);
printf("\n");

// presun sifrovaneho text do pole text
for(i=0;i<DELKA;i++)
text[i]=sifra[i];

// desifrovani
w=0;
for(j=0;j<DELKA;j++)
{
sifra[w]=(heslo[j]>text[j])?123+text[j]-heslo[j]:
text[j]+97-heslo[j];
w++;
}

// vypis vysledku desifrovani
printf("vysledek DEsifrovani:\n");
for(i=0;i<DELKA;i++)
printf("%c",sifra[i]);
printf("\n");

system("pause");
return 0;
}

