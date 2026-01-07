#include <stdio.h>

// kalendar_1

int y,m,d;
int DenRoku(int y, int m, int d);
long PocDni(int y1, int m1, int d1, int y2, int m2, int d2);
int DenTydne(int y, int m, int d);

int DenRoku(int y, int m, int d)
{
int i,k;
int p[12]={31,28,31,30,31,30,31,31,30,31,30,31};
k=d;
for(i=0; i<m-1; i++) k=k+p[i];
printf("k=%d ",k);
// pocet dnu, ktere maji dohromady mesice 1 az m-1 plus den
if (m>2)
{
if ((y%4==0) && (y%100!=0) || (y%400==0)) k++;
}
return k;
}

long PocDni(int y1, int m1, int d1, int y2, int m2, int d2)
{
long k;
k=365*(y2-y1); // hruby pocet dnu
k=k+DenRoku(y2,m2,d2)-DenRoku(y1,m1,d1);
// zpresneni pomoci poradovich cisel
y2--; y1--;
k=k+y2/4-y2/100+y2/400-y1/4+y1/100-y1/400;
// zpresneni z ohledem na prestupne roky
// tady je nekde chyba nepozna prestupnej rok
return k;
}

int DenTydne(int y, int m, int d)
{
//return PocDni(1599,12,26,y,m,d)%7; // puvodni
return PocDni(1599,12,26,y,m,d)%7;
}

int main(){

//printf("Zadej rok,mesic,den\n"); // puvodni ale blbost je to podle nasledujiciho
printf("zadej potupne den mesic rok a zmackni enter za kazdou polozkou\n");

scanf("%d%d%d",&d,&m,&y); // intput C#
//scanf("%d",&d); // funguje i takto, rozdelene na 3 casti
//scanf("%d",&m);
//scanf("%d",&y);

switch(DenTydne(y,m,d))
{
case 0:
{printf("nedele\n"); break;}
case 1:
{printf("pondeli\n"); break;}
case 2:
{printf("utery\n"); break;}
case 3:
{printf("streda\n"); break;}
case 4:
{printf("ctvrtek\n"); break;}
case 5:
{printf("patek\n"); break;}
case 6:
{printf("sobota\n"); break;}	
}

system("pause");
return 0;
}

