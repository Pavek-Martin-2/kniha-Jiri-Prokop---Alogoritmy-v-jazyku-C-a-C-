#include <iostream>

using namespace std;

// nefunguje

class zasobnik {
int v;
int max;
public:
zasobnik(int n)
{
max = n;
v = 0;
zas = new int[max]; // alokace pameti
}

~Zasobnik() {free(zas);} // destruktor
// tady hazi chybu
void vloz(int);
int vezmi;
}; // konec deklarace tridy zasobnik

// vlozeni obektu
void vloz (int ob)
{
if (v == max)
cout<<"zasobnik je plny\n";
system("pause");
return;	
}

zas[v++]=ob;
}

// vyjmuti obektu
int vezmi ()
{
if (v == 0)	
}
cout<<"zasobnik je prazdny\n";
system("pause");
return 0;
}

return zas[--v];
}
// ukazka
int main()
{
Zasobnik c(10);
int i;
c.init();
c.vloz(9);
c.vloz(5);
c.vloz(2);
for (i=0; i<3; i++)
cout<<c.vezmi()<<" ";
cout<<"\n";
system("pause");
}


