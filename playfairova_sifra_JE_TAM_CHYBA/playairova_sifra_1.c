#include <stdio.h>
#include <string.h>

// playfairova sifra, puvodni z knizky - nekde je chyba desifruje to spatne !!

#define DELKA 24
char abc[25]="abcdefghijklmnoprstuvwxyz"; // q je vynechano

char text [DELKA] = "tohlechcivsemlidemutajit"; // puv0dni z knizky
//                   123456789012345678901234

char sifra[DELKA];
char heslo[20];
char tab [5][5];
int i,j,k,m,r,s,t,u,i40,i04,i1,w;

void sifruj()
{
w=0;
for (i=0;i<DELKA;i+=2) // cyklus pro pismena vychoziho textu
{
for (j=0;j<5;j++)
for (k=0;k<5;k++)
{
if(text[i]==tab[j][k])
{
r=j; s=k;
}
if(text[i+1]==tab[j][k])
{
t=j; u=k;
}
}
if(r==t) // stejny radek
{
if(s==i40) s=i40; else s=s+i1;
sifra[w]=tab[r][s]; w++;
if(u==i40) u=i04; else u=u+i1;
sifra[w]=tab[t][u]; w++;
}
else if(s==u) // stejny sloupec
{
if(r==i40) r=i04; else r=r+i1;
sifra[w]=tab[r][s]; w++;
if (t==i40) t=i04; else t=t+i1;
sifra[w]=tab[t][u]; w++;
}
else // ani stejny radek, ani sloupec
{
sifra[w]=tab[r][u]; w++;
sifra[w]=tab[t][s]; w++;
}
}
} // konec funkce sifruj


int main()
{
printf("zadej heslo (6-20 znaku)\n");
j=strlen(gets(heslo));
printf("delka zadaneho hesla = %d",j); // pridano mnou
printf("\n");

printf("\nsifrovat se bude text:\n");
printf("%s",text);
printf("\n\n");

/* toto by melo byt podle autora ale nesouhlasi to, takze je nekde chyba
heslo = playfair
playi
frbcd
eghjk
mnost
uvwxz
*/

// vkladani pismen hesla do tabulky
k=0; m=0;
for(i=0; i<j; i++)
if(abc[heslo[i]-97]!=' ')
{
tab[k][m]=heslo[i];
if(heslo[i] < 113) // kvuli vynechanemu pismenu q ascii "q" = 113
abc[heslo[i]-97]=' ';
else abc[heslo[i]-98]=' ';
m++; if(m>4) {k++; m=0;}
}
// ukladani ostatnich pismen abecedy
for(i=0;i<25;i++)
if(abc[i]!=' ')
{
tab[k][m]=abc[i];
m++; if(m>4) {k++; m=0;}
}

// vypis tabulky pro kontrolu
printf("vysledny ctverec 5x5\n");
for(k=0;k<5;k++)
{
for(m=0;m<5;m++)
printf("%c",tab[k][m]);
printf("\n");
}

// zasifrovani textu
i40=4; i04=0; i1=1;
sifruj();
printf("\nvysledek sifrovani:\n");
for(i=0;i<DELKA;i++)
printf("%c",sifra[i]);
printf("\n\n");

// desifrovani
i40=0; i04=4; i1=-1;
for(i=0;i<DELKA;i++)
text[i]=sifra[i];

sifruj();
// vypis vysledku - je v poly sifra
printf("\nvysledek desifrovani:\n");
for(i=0;i<DELKA;i++)
printf("%c",sifra[i]);
printf("\n\n");

system("pause");
return 0;
}

