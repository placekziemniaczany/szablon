#ifndef SWEKTOR_HH
#define SWEKTOR_HH
#include "rozmiar.h"
#include <iostream>
#include<cmath>
using namespace std;

template <typename STyp, int SWymiar>
class SWektor {
STyp tab[ROZMIAR];

public:
SWektor();
STyp zwroc_wartosc(int nr) const {
return tab[nr];
}
void dodaj_wartosc(STyp nowa, int nr) {
tab[nr]=nowa;
}
SWektor<STyp,SWymiar> operator + (const SWektor<STyp,SWymiar> &W2) const;
SWektor<STyp,SWymiar> operator - (const SWektor<STyp,SWymiar> &W2) const;
STyp operator * (const SWektor <STyp,SWymiar> &W2) const;
SWektor<STyp, SWymiar> operator * (double l)const;
SWektor<STyp, SWymiar> operator / (double l)const;
bool operator == (const SWektor<STyp, SWymiar> & W2) const;
bool operator != (const SWektor<STyp, SWymiar> & W2) const;
const double dlugosc ();
STyp operator [] (unsigned int index) const {
if (index < 0 || index > SWymiar) {
    cerr << "indeks poza zakresem" << endl;
    exit(1);
}
else return tab[index];
}
STyp &operator [] (unsigned int index) {
if (index < 0 || index > SWymiar) {
    cerr << "indeks poza zakresem" << endl;
    exit(1);
    }
else return tab[index];
}
};
template <typename STyp, int SWymiar>
SWektor <STyp, SWymiar>::SWektor(){
    for(int i = 0; i<ROZMIAR; i++) {
        tab[i]=0;
}
}
template <>
SWektor <LZespolona, ROZMIAR>::SWektor(){
    for(int i = 0; i<ROZMIAR; i++) {
        tab[i].re=0;
        tab[i].im=0;
}
}
template <typename STyp, int SWymiar>
istream& operator >> (istream &Strm, SWektor <STyp, SWymiar> &W){
    STyp pomocnicza;
    for(int i = 0; i<ROZMIAR; i++) {
        Strm>>pomocnicza;
        W.dodaj_wartosc(pomocnicza, i);
    }
    return Strm;
}

template <typename STyp, int SWymiar>
ostream& operator << (ostream &Strm, const SWektor <STyp, SWymiar> &W){
for(int i=0; i<ROZMIAR; i++) {
    Strm<<W.zwroc_wartosc(i)<<" ";
}
return Strm;
}

template <typename STyp, int SWymiar>
SWektor<STyp,SWymiar> SWektor<STyp,SWymiar>::operator + (const SWektor<STyp,SWymiar> &W2) const {
SWektor <STyp, SWymiar> wynik;
STyp pomocnicza;
for (int i=0; i<ROZMIAR; i++) {
    pomocnicza = this->zwroc_wartosc(i) + W2.zwroc_wartosc(i);
    wynik.dodaj_wartosc(pomocnicza,i);
}
return wynik;
}
template <typename STyp, int SWymiar>
SWektor<STyp,SWymiar> SWektor<STyp,SWymiar>::operator - (const SWektor<STyp,SWymiar> &W2) const {
SWektor <STyp, SWymiar> wynik;
STyp pomocnicza;
for (int i=0; i<ROZMIAR; i++) {
    pomocnicza = this->zwroc_wartosc(i) - W2.zwroc_wartosc(i);
    wynik.dodaj_wartosc(pomocnicza,i);
}
return wynik;
}

template <typename STyp, int SWymiar>
STyp SWektor<STyp, SWymiar> :: operator * (const SWektor<STyp, SWymiar> &W2)const{
STyp pomocnicza, wynik = 0;
for (int i=0; i<ROZMIAR; i++) {
    pomocnicza = this->zwroc_wartosc(i) * W2.zwroc_wartosc(i);
    wynik = wynik + pomocnicza;
}
return wynik;
}
template <>
LZespolona SWektor<LZespolona, ROZMIAR> :: operator * (const SWektor<LZespolona, ROZMIAR> &W2)const{
LZespolona pomocnicza, wynik;
wynik.im = 0; wynik.re = 0;
for (int i=0; i<ROZMIAR; i++) {
    pomocnicza = this->zwroc_wartosc(i) * W2.zwroc_wartosc(i);
    wynik = wynik + pomocnicza;
}
return wynik;
}


template <typename STyp, int SWymiar>
SWektor<STyp, SWymiar> SWektor<STyp, SWymiar>::operator * (double l)const{
SWektor <STyp, SWymiar> wynik;
STyp pomocnicza;
for (int i=0; i<ROZMIAR; i++){
    pomocnicza = this->zwroc_wartosc(i) * l;
    wynik.dodaj_wartosc(pomocnicza, i);
}
return wynik;
}

template <typename STyp, int SWymiar>
SWektor <STyp, SWymiar> SWektor<STyp, SWymiar>:: operator / (double l) const {
SWektor <STyp, SWymiar> wynik;
STyp pomocnicza;
if (l == 0){
    cerr<<"ERROR: Dzielenie przez 0!!";
    exit(0);
}
for (int i=0; i<ROZMIAR; ++i) {
    pomocnicza = this->zwroc_wartosc(i)/l;
    wynik.dodaj_wartosc(pomocnicza, i);
}
return wynik;
}

template <typename STyp, int SWymiar>
bool SWektor<STyp, SWymiar> :: operator == (const SWektor<STyp, SWymiar> & W2) const{
for (int i=0; i<ROZMIAR; i++){
    if(this->zwroc_wartosc(i)==W2.zwroc_wartosc(i)){
        return true;
    }
    else {
        return false;
    }
}
}
template <typename STyp, int SWymiar>
bool SWektor<STyp, SWymiar> :: operator != (const SWektor<STyp, SWymiar> & W2) const {
for (int i=0; i<ROZMIAR; i++){
    if(this->zwroc_wartosc(i)==W2.zwroc_wartosc(i)){
        return false;
    }
    else {
        return true;
    }
}
}
template <typename STyp, int SWymiar>
SWektor <STyp, SWymiar> operator *(double l, SWektor <STyp, SWymiar> W2){
SWektor <STyp, SWymiar> wynik;
STyp pomocnicza;
for (int i=0; i<ROZMIAR; i++){
    pomocnicza = W2.zwroc_wartosc(i) * l;
    wynik.dodaj_wartosc(pomocnicza, i);
}
return wynik;
}
template <typename STyp, int SWymiar>
const double SWektor<STyp, SWymiar> :: dlugosc (){
    return sqrt(*this * *this);
}

template <>
const double SWektor<LZespolona, ROZMIAR> :: dlugosc (){
LZespolona pom1;
pom1 = *this * *this;
return sqrt(pow(pom1.re, 2) + pow(pom1.im, 2));

}


#endif

