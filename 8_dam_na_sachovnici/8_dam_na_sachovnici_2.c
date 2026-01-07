#include <stdio.h>

// 8 dam na sachovnici

int i,k;
int poc=1; // moje
static int a[8];
static int b[15];
static int c[15];
int x[8];

void zkus(int i){
int j;
for (j=0; j < 8; j++){
if(a[j] && b[i+j] && c[i-j+7]){ // podminka pro umisteni	
x[i]=j; // umisteni na i-ty sloupec j-ty radek
a[j]=0;
b[i+j]=0;
c[i-j+7]=0;

if (i<7)
zkus(i+1);
else{
// tisk vysledku
if (poc<10){ // prida na zacatek "0" pro 1-9
printf("0");	
}
printf("%d - ",poc);
for (k=0; k<8; k++)
printf("%d ",x[k]); // tiskne cisla
printf("\n");
//printf("stiskni libovolnou klavesu...\n");
//getch();
poc++;
}
a[j]=1; 
b[i+j]=1;
c[i-j+7]=1; // navrat zpet
}
}
}

int main(){
	
for(i=0; i<8; i++)
a[i]=1;
for(i=0; i<15; i++){
b[i]=1;
c[i]=1;	
}	

zkus(0);
system("pause");
return 0;
}

