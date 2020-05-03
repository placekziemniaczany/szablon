#include <iostream>
#include "LZespolona.hh"
#include "SWektor.hh"
#include "SMacierz.hh"
#include "SUkladRownanLiniowych.hh"
#include <iomanip>

using namespace std;

int main() {
char znak;
cin>>znak;
if(znak == 'r'){
SUkladRownanLiniowych <double, ROZMIAR> U;
SWektor <double, ROZMIAR> C, B;
double x = 0;
cin>>U;
cout << fixed << setprecision(2);
cout<<U;
C = U.obliczuklad();
B = U.wekbl();
x = B.dlugosc();
wyswrozw(C, B, x);
}
else if(znak == 'z') {
SUkladRownanLiniowych <LZespolona, ROZMIAR> U;
SWektor <LZespolona, ROZMIAR> D, E;
cin>>U;
double x;
D = U.obliczuklad();
cout << fixed << setprecision(2);
cout<<U;
E = U.wekbl();
x = E.dlugosc();
wyswrozw(D, E, x);
}
else {cerr<<"Nie rozpoznano formatu liczb!"<<endl;
exit(0);}


}
