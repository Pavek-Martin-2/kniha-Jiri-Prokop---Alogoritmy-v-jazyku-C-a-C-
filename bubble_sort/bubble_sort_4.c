#include <stdio.h>

// "C" bubble sort z knihy Jiri Prokop, Algoritmy v jazyku C a C++

#define pocet 99
int a[pocet] = {
89,26,49,50,0,9,34,67,8,20,66,
85,42,92,2,30,98,94,44,4,24,16,
36,11,56,1,54,41,70,47,93,81,63,
84,80,60,17,27,55,65,96,22,48,46,
45,97,12,29,40,13,18,68,6,53,90,
14,51,72,33,25,38,58,79,28,95,31,
88,10,64,87,61,15,35,74,83,78,21,
7,69,76,57,3,19,62,43,32,77,99,
23,37,91,82,39,52,71,73,5,75,86	
}; //pole nesetridenych prvku


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

