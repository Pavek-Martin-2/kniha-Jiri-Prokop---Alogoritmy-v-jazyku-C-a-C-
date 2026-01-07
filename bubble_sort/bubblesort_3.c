#include <stdio.h>

// "C" bubble sort z knihy Jiri Prokop, Algoritmy v jazyku C a C++

#define pocet 10
int a[pocet] = {
8,3,7,1,
10,5,
6,
4,2,
9
}; //pole tridenych prvku


int srovnej (int a, int b){
if (a>b) return 1;
else return 0;	
}

int srovnej2(int a, int b){
if (a<b) return 1;
else return 0;	
}

void vymen(int *a, int *b){
int pom;
pom=*a; *a=*b; *b=pom;
}

void bubble(int p[], int n, int (*pf1) (),void (*pf2())){
int i,j;
for (i=1; i<n; i++)
for (j=n-1; j>=i; j--)
if (pf1(p[j-1],p[j]))  // provede se vymena
pf2(&p[j-1],&p[j]); // lze i (*pf2) (&p[j-1], &p[j]);	
}

int main(){
int i;
int (*pf1) (int,int);
void (*pf2) (int *, int *);
pf1=srovnej;
pf2=vymen;

bubble(a,pocet,srovnej,vymen);
for (i=0; i<pocet; i++) printf("%d ",a[i]);
printf("\n");

printf("---------------------------\n");

bubble(a,pocet,srovnej2,vymen);
for (i=0; i<pocet; i++) printf("%d ",a[i]);
printf("\n");
system("pause");

return 0;
}


