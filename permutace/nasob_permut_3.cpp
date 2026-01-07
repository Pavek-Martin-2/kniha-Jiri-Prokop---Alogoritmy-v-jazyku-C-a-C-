#include <iostream>
#include <stdio.h>
//using namespace std;

// inverzni permutace

#define DIM 8 // pocet prvku DIM
int klice[DIM]={3,5,7,8,4,2,6,1};
int data[DIM] ={5,4,8,3,1,7,2,6};
/*
vysledek:
  1   2   3   4   5   6   7   8
  6   7   5   1   4   2   8   3
*/


void vymen (int *x, int *y ){
int pom; pom=*x; *x=*y; *y=pom;	
}

int main(){
int i;

for (i=0;i<DIM-1;i++){
	
while (i+1 != klice[i]){
vymen (&data[i], &data[klice[i]-1]);
vymen (&klice[i], &klice[klice[i]-1]);	
}	

}

printf("vysledek:\n");

for (i=0;i<DIM;i++)	
printf("%3d ",klice[i]);
printf("\n");

for (i=0;i<DIM;i++)	
printf("%3d ",data[i]);
printf("\n");

system("pause");
return 0;
}

