#include <iostream>

using namespace std;

// hanojske veze

int PVez(int vyska, int odkud, int kam, int pomoci)
{
int counter;
counter++;
if (vyska>0)
{
PVez ((vyska-1),odkud, pomoci, kam);
printf("prenes kotouc z %i na %i\n", odkud, kam);
PVez((vyska-1),pomoci, kam, odkud);
}
return counter;
}

int main(){
// grafika pridano mnou

cout<<"     hanojske veze\n\n";
cout<<"    x         x         x\n";
cout<<"    x         x         x\n";
cout<<"    x         x         x\n";
cout<<"    x         x         x\n";
cout<<"   xxx        x         x\n";
cout<<"  xxxxx       x         x\n";
cout<<" xxxxxxx      x         x\n";	
cout<<"xxxxxxxxx     x         x\n";
cout<<"-------------------------\n";
cout<<"    1         2         3\n";
	
	
int n;
int cnt;
printf("zadej pocet kotoucu : \n");
scanf("%i",&n); // input
cnt=PVez(n,1,2,3);
printf("pocet volani: %i\n",cnt);
	
system("pause");
return 0;
}

