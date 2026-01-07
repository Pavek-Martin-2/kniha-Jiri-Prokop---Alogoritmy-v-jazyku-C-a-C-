#include <stdio.h>
#include <conio.h>
// ludolfovo cislo
// pi_5

int main(){
	
double pi, b, c;
b = 1;
c = 1;
pi = 4;

while (4 / b > 0.0000001) {
c= -c;
b += 2;
pi += c * 4/b;	
}

printf("pi = %f\n", pi);

system("pause");
return 0;
}

