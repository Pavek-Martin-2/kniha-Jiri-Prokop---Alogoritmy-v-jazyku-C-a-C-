#include <stdio.h>

// "C" bubble sort z knihy Jiri Prokop, Algoritmy v jazyku C a C++

#define pocet 100
//int a[pocet] = {8,3,7,1,10,5,6,4,2,9}; //pole tridenych prvku

int a[pocet] = {61,18,59,76,96,79,99,10,85,87,32,63,36,88,17,46,91,9,70,74,33,8,98,27,66,44,83,81,57,35,23,71,53,31,24,80,55,67,15,37,21,25,94,58,69,65,84,48,68,90,38,56,89,16,64,93,4,42,73,47,86,3,14,7,92,72,50,45,1,5,2,6,52,20,19,75,51,13,60,82,49,12,29,95,41,78,97,30,11,100,39,43,22,54,40,34,77,62,26,28};

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

printf("--------------------\n");

bubble(a,pocet,srovnej2,vymen);
for (i=0; i<pocet; i++) printf("%d ",a[i]);
printf("\n");
system("pause");

return 0;
}


