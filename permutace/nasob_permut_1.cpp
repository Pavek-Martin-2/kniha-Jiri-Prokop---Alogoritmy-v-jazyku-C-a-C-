#include <stdio.h>
#include <iostream>

//using namespace std;

#define DELKA 18

int main(){
char *zapis="(124) (36) (136) (45)";
int i,j,k,m,jeste;
int q; // pro mzv
char znak, current, start;
char oznac[DELKA];
char vstup[DELKA];
char vystup[DELKA];
j=DELKA;

for (i=0;i<j;i++){
oznac[i]='0';
vstup[i]=zapis[i];	
}

for (i=0;i<j;i++){
	
if (vstup[i]=='('){
oznac[i]='1';
znak=vstup[i+1];	
}

else if (vstup[i]==')'){
vstup[i]=znak;
oznac[i]='1';
}

}

// overeni
i=0;
jeste=1;
k=0;

while (jeste==1){
while(i<j){
jeste=0;

if (oznac[i]=='0'){
jeste=1;
start=vstup[i];
vystup[k]='(';
k++;
vystup[k]=vstup[i];
oznac[i]=1;

for (q=0;q<=k;q++){
printf("%c",vystup[q]); // mzv
printf("\n");

// getch();
i++;
current=vstup[i];
m=i+1;

L:
while(m<j){

if (vstup[m]==current){
oznac[m]='1';
m++;
current=vstup[m];	
}
m++;
}	

if (current!=start){
k++;
vystup[k]=current;
m=0;

for (q=0;q<k;q++) printf("%c", vystup[q]); // mezivysledky
printf("\n");
goto L;	
}else{
k++;

vystup[k]=')';
}

for (q=0;q<k;q++) printf("%c", vystup[q]); // mezivysledky
printf("\n");
k++;	
}
}

i++;	
}
}
for (q=0;q<k;q++) printf("%c", vystup[q]); // mezivysledky
printf("\n");

system("pause");
return 0;
}


