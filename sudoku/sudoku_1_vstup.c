#include <stdio.h>
#include <stdlib.h>

#define RADEK 9

// pro sudoku vytvoreni vstupnih souboru *.txt

int main(){
short m[RADEK][RADEK];
short i,j,k;
FILE *fw;

printf("data zapisu do souboru, sudoku_1.txt\n"); // moje

for (i=0;i<RADEK;i++){
printf("zadej hodnoty %d.radku\n",i+1);
for (j=0;j<RADEK;j++)
scanf("%d",&m[i][j]);
}
k=1;
while (k>0){
printf("kontrolni vypis\n")	;
for(i=0;i<RADEK;i++){
printf("%d ",i+1);
for(j=0;j<RADEK;j++)
printf("%d ",m[i][j]);
printf("\n");
}

printf("zadej cislo radku pro opravu nebo nulu pro konec\n");
scanf("%d",&k);
if(k!=0){
for(j=0;j<RADEK;j++)
scanf("%d  ",&m[k-1][j]);	
}

// zapis do souboru
//printf("data zapisu do souboru, sudoku_1.txt\n");
fw=fopen("sudoku_1.txt","w");
for(i=0;i<RADEK;i++)
for(j=0;j<RADEK;j++)
//printf("%d\n",m[i][j]); // moje
fprintf(fw,"%d\n",m[i][j]);
fclose(fw);
}

system("pause");
return 0;
}


