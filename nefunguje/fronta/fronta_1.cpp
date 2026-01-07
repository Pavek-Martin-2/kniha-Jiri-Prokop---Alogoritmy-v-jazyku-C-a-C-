#include <iostream>
using namespace std;

// fronta

class Fronta{
int *f;
int zac,max,z,k,pocet;
public:
Fronta (int n) // konstruktor
}

max=n;
f=new int[max];
z=1;
k=1;
pocet=0;
}

~Fronta(){free (f);} // destruktor
void init() {z=1;k=1;pocet=0;} // inicializace zasobniku
void vloz (int x);
int vezmi();
};

// vlozeni objetu x
void Fronta::vloz(int x)
{
if (pocet==max)
{ cout<<"fronta je plna\n";
system("pause");
return;
}
f[k++]=x; if (k>max) k=1; pocet++;
}
// vyjmuti objektu
int Fronta::vezmi()
{
if (pocet==0)
{
cout<<"fronta je prazdna\n";
system("pause");
return 0;
}	
zac=z; if (++z>max) z=1; return f[zac];
}

// ukazka
int main()
{
Fronta a(5);
int i;
a.init();
a.vloz(9);
a.vloz(5);
a.vloz(2);
for (i=0;i<3;i++)
cout<<a.vezmi()<<" ";
cout<<endl;
system("pause");
return 0;
}


