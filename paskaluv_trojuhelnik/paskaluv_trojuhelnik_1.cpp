#include <iostream>

using namespace std;
// paskaluv trojuhelnik

int main(){

int p1[13]; 
int p2[13];

// hodnoty koeficientu ve dvou po sobe jdoucich radcich
int i, j;
p1[0]=1; p1[1]=1; // hodnoty prvniho radku

for (i=1; i<12; i++){
for (j=12; j>=i; j--) printf("  ");
for (j=0; j<i; j++) printf("%3d  ",p1[j]);
printf("\n");

p2[0]=1;
for (j=0; j<i; j++) p2[j+1]=p1[j]+p1[j+1];
// hodnoty radku vypocitam z radku predchoziho
p2[i]=1;
for(j=0; j<i+1; j++) p1[j]=p2[j];	
}

system("pause");
return 0;
}


