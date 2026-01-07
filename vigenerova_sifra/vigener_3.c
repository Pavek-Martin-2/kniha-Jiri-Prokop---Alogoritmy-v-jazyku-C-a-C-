#include <stdio.h>

// vigenerova sifra + moje upravy

#define DELKA 27 // 27
char text[DELKA] = "dnes je sobota je hezky den"; // delka 27 misto mezery udela zank ":"
//                  123456789012345678901234567                                   

#define DEL_KLICE 10 // upraveno mnou na 10
//char klic[10]="qwertyuiop"; // tjij3hy(gdrkxr3hy(vtpgc1wch - vysled sifrovani timto klicem
char klic[10]="kjdhfeiwfe"; // nwhz%nm6xslxwh%nm6mijtb'iiv - vysledek sifrovani timto klicem
//             1234567890


char sifra [DELKA];
char heslo [DELKA];
int i,j,w;

int main(){
	
// vypis co se bude sifrovat
printf("tento text budu sifrovat:\n");

for(i=0;i<DELKA;i++)
printf("%c",text[i]);
printf("\n");

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

printf("\nvysledek sifrovani klicem - ");
printf(klic);
printf(" : ");

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
printf("\nvysledek DEsifrovani:\n");
for(i=0;i<DELKA;i++)
printf("%c",sifra[i]);
printf("\n");

system("pause");
return 0;
}

