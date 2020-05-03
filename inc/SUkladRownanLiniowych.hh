#include <iostream>
#include "SWektor.hh"
#include "SMacierz.hh"
#include "rozmiar.h"
#include <iomanip>
using namespace std;

template <typename STyp, int SWymiar>
class SUkladRownanLiniowych {
    SMacierz <STyp, SWymiar> M;
    SWektor <STyp, SWymiar> W;
public:
STyp zwroc_wolne (int i)const{
return W[i];
}
void dodaj_wolne (STyp nowa, int i) {
    W.dodaj_wartosc(nowa, i);
}
SWektor <STyp, SWymiar> zwroc_wspolczynniki (int i)const{
    return M.zwroc_wektor(i);
}
void dodaj_wspolczynniki (SWektor <STyp, SWymiar> nowy, int i){
   M.zamien_wektor(nowy, i);
}

SWektor <STyp, SWymiar> obliczuklad();
SWektor <STyp, SWymiar> wekbl();
};

template <typename STyp, int SWymiar>
istream& operator >> (istream &Strm, SUkladRownanLiniowych <STyp, SWymiar> &UklRown) {
SWektor <STyp, SWymiar> wek;
STyp liczba;
for(int i=0; i<ROZMIAR; i++) {
    Strm >> wek;
    UklRown.dodaj_wspolczynniki(wek, i);
}
for(int i=0; i<ROZMIAR; i++) {
    Strm >> liczba;
   UklRown.dodaj_wolne(liczba, i);
}
return Strm;
}

template <typename STyp, int SWymiar>
ostream& operator << (ostream &Strm, const SUkladRownanLiniowych <STyp, SWymiar> &UklRown) {
Strm << endl << "Uklad rownan do rozwiazania: " << endl<<endl;
for(int i=0; i<ROZMIAR; i++) {
Strm << "\t |  " << UklRown.zwroc_wspolczynniki(i) <<  "| | x_" << i+1 << " |";
if (i == ROZMIAR/2){
Strm << " = | " << UklRown.zwroc_wolne(i) << " |" <<endl;
}
else {
Strm << "   | " << UklRown.zwroc_wolne(i) << " |" <<endl;
}
}
Strm << endl;
    return Strm;
}

template <typename STyp, int SWymiar>
SWektor <STyp, SWymiar> SUkladRownanLiniowych <STyp, SWymiar>::obliczuklad(){
    SWektor <STyp, SWymiar> wynik, pomocniczy;
    STyp wyznacznik_glowny, wyznacznik_pomocniczy;
    wyznacznik_glowny = this->M.Wyznacznik();
    for(int i = 0; i<SWymiar; i++){
    this->M.transponuj();
    pomocniczy = this->zwroc_wspolczynniki(i);
    this->M.zamien_wektor(this->W, i);
    wyznacznik_pomocniczy = this->M.Wyznacznik();
    this->M.zamien_wektor(pomocniczy, i);
    this->M.transponuj();
wynik.dodaj_wartosc(wyznacznik_pomocniczy/wyznacznik_glowny, i);
}
return wynik;
}
template <>
SWektor <LZespolona, ROZMIAR> SUkladRownanLiniowych <LZespolona, ROZMIAR>::obliczuklad(){
SWektor <LZespolona, ROZMIAR> wynik, pomocniczy;
LZespolona wyznacznik_glowny, wyznacznik_pomocniczy;
    wyznacznik_glowny = this->M.Wyznacznik();
    for(int i = 0; i<ROZMIAR; i++){
    this->M.transponuj();
    pomocniczy = this->zwroc_wspolczynniki(i);
    this->M.zamien_wektor(this->W, i);
    wyznacznik_pomocniczy = this->M.Wyznacznik();
    this->M.zamien_wektor(pomocniczy, i);
    this->M.transponuj();
wynik.dodaj_wartosc(wyznacznik_pomocniczy/wyznacznik_glowny, i);
}
return wynik;
}
template <typename STyp, int SWymiar>
void wyswrozw(SWektor <STyp, SWymiar> C, SWektor <STyp, SWymiar> B, double x){
cout << "Wektor rozwiazan (x1, x2, x3, x4, x5): " <<endl  << endl << "\t" << C << endl << endl;
cout << fixed << setprecision(2);
cout << "Wektor bledu:" << endl << endl << "\tAx-b  =  (" << B << ")" << endl << endl;
cout << scientific << setprecision(1);
cout << "Dlugosc wektora bledu:" << endl << endl << "\t||Ax-b||  =  " << x << endl << endl;
}

template <typename STyp, int SWymiar>
SWektor <STyp, SWymiar> SUkladRownanLiniowych <STyp, SWymiar> :: wekbl(){
SWektor <STyp, SWymiar> pomocniczy;
SWektor <STyp, SWymiar> wynik;
pomocniczy = this->obliczuklad();
wynik = (this->M) * pomocniczy - (this->W);
return wynik;
}






