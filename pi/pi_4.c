#include <stdio.h>
#include <conio.h>
// pi 4

int main(){
double pi1, pi2, a, b, c, q;
a = 4;
b = 3;
c = -1;
pi1 = 4;
pi2 = 4.0 - (4.0 / 3.0);
printf("pi2 = %f\n", pi2);

// funkce fabs vraci absolutni hodnotu racionalniho argumentu
while (fabs(pi1-pi2) > 0.000001) {
pi1 = pi2;
c = -c;
b += 2.0;
pi2 = pi1 + c * a/b;
}

printf("pi2 = %f\n", pi2);

system("pause");
return 0;
}

