#ifndef SMACIERZ_HH
#define SMACIERZ_HH
#include "SWektor.hh"
#include "LZespolona.hh"
#include <iostream>

using namespace std;

template <typename STyp, int SWymiar>
class SMacierz {
SWektor<STyp, SWymiar> tab[SWymiar];

public:
SMacierz();
SWektor<STyp, SWymiar>zwroc_wektor(int nr) const {
    return tab[nr];
}
void zamien_wektor(SWektor <STyp, SWymiar> nowy, int nr) {
    tab[nr] = nowy;
}
const SWektor<STyp, SWymiar> operator * (const SWektor<STyp, SWymiar> & W)const;
const SMacierz<STyp, SWymiar> operator + (const SMacierz <STyp, SWymiar> & M2)const;
const SMacierz<STyp, SWymiar> operator - (const SMacierz <STyp, SWymiar> & M2)const;
const SMacierz <STyp, SWymiar> operator * (const double l)const;
const SMacierz <STyp, SWymiar> operator * (SMacierz & M2)const;
const SMacierz <STyp, SWymiar> transponuj();
const SWektor <STyp, SWymiar> zwroc_kolumne(int k);
const STyp Wyznacznik ();
};
template <typename STyp, int SWymiar>
SMacierz <STyp, SWymiar> :: SMacierz(){
    for (int i = 0; i<ROZMIAR; i++){
        tab[i][i]=2;
    }
}
template <>
SMacierz <LZespolona, ROZMIAR> :: SMacierz(){
    for (int i = 0; i<ROZMIAR; i++){
        tab[i][i].re=2;
        tab[i][i].im=0;
    }
}
template <typename STyp, int SWymiar>
istream& operator >> (istream &Strm, SMacierz <STyp, SWymiar> &M1) {
SWektor<STyp, SWymiar> pomocniczy;
for(int i = 0; i<SWymiar; i++) {
    Strm >> pomocniczy;
    M1.zamien_wektor(pomocniczy,i);
}
return Strm;
}

template <typename STyp, int SWymiar>
ostream& operator << (ostream &Strm, const SMacierz <STyp, SWymiar> &M1) {
for(int i = 0; i<SWymiar; i++) {
    Strm<<M1.zwroc_wektor(i)<<endl;
}
return Strm;
}

template <typename STyp, int SWymiar>
const SWektor<STyp, SWymiar> SMacierz<STyp, SWymiar> :: operator * (const SWektor<STyp, SWymiar> & W)const {
SWektor<STyp, SWymiar> wynik;
STyp pomocnicza;
for (int i = 0; i<SWymiar; i++){
    pomocnicza = this->zwroc_wektor(i) * W;
    wynik.dodaj_wartosc(pomocnicza, i);
}
return wynik;
}

template <typename STyp, int SWymiar>
const SMacierz<STyp, SWymiar> SMacierz<STyp, SWymiar> :: operator + (const SMacierz <STyp, SWymiar> & M2)const {
SMacierz <STyp, SWymiar> M1 = (*this);
SMacierz <STyp, SWymiar> wynik;
SWektor <STyp, SWymiar> pom;
    for (int i = 0; i<SWymiar; i++){
       pom = M1.zwroc_wektor(i)+M2.zwroc_wektor(i);
       wynik.zamien_wektor(pom, i);
    }
return wynik;
}

template <typename STyp, int SWymiar>
const SMacierz<STyp, SWymiar> SMacierz<STyp, SWymiar> :: operator - (const SMacierz <STyp, SWymiar> & M2)const {
SMacierz <STyp, SWymiar> M1 = (*this);
SMacierz <STyp, SWymiar> wynik;
SWektor <STyp, SWymiar> pom;
    for (int i = 0; i<SWymiar; i++){
       pom = M1.zwroc_wektor(i)-M2.zwroc_wektor(i);
       wynik.zamien_wektor(pom, i);
    }
return wynik;
}

template <typename STyp, int SWymiar>
const SMacierz <STyp, SWymiar> SMacierz <STyp, SWymiar> :: operator * (const double l)const {
SMacierz <STyp, SWymiar> M1 = (*this);
SMacierz <STyp, SWymiar> wynik;
SWektor <STyp, SWymiar> pom;
for (int i = 0; i<SWymiar; i++){
    pom = M1.zwroc_wektor(i) * l;
    wynik.zamien_wektor(pom, i);
}
return wynik;
}

template <typename STyp, int SWymiar>
const SMacierz <STyp, SWymiar> SMacierz <STyp, SWymiar> :: operator * (SMacierz <STyp, SWymiar> & M2)const {
SWektor <STyp, SWymiar> pom1, pom2;
SMacierz <STyp, SWymiar> wynik;
    for (int i = 0; i<SWymiar; i++){
            for (int j = 0; j<SWymiar; j++){
            pom1 =  M2.zwroc_kolumne(j);
            pom2.dodaj_wartosc(this->zwroc_wektor(j)*pom1,j);
            }
            wynik.zamien_wektor(pom2, i);
}
return wynik.transponuj();
}

template <typename STyp, int SWymiar>
const SMacierz <STyp, SWymiar> SMacierz <STyp, SWymiar> :: transponuj(){
SMacierz <STyp, SWymiar> M;
SWektor <STyp, SWymiar> pomocniczy;
for(int i = 0; i<SWymiar; i++){
pomocniczy= this->zwroc_kolumne(i);
    M.zamien_wektor(pomocniczy, i);
}
for(int b = 0; b<SWymiar; b++) {
    this->zamien_wektor(M.zwroc_wektor(b), b);
}
return *this;
}

template <typename STyp, int SWymiar>
const SWektor <STyp, SWymiar> SMacierz<STyp, SWymiar>::zwroc_kolumne(int k){
SWektor <STyp, SWymiar> pom1, pom2;
    for(int j = 0; j<SWymiar; j++) {
        pom1 = this->zwroc_wektor(j);
        pom2.dodaj_wartosc(pom1.zwroc_wartosc(k),j);
}
return pom2;
}

template <typename STyp, int SWymiar>
const SMacierz <STyp, SWymiar> operator * (const double l, const SMacierz <STyp, SWymiar> & M){
SMacierz <STyp, SWymiar> wynik;
SWektor <STyp, SWymiar> pom;
for (int i = 0; i<SWymiar; i++){
    pom = l*M.zwroc_wektor(i);
    wynik.zamien_wektor(pom, i);
}
return wynik;
}
template <typename STyp, int SWymiar>
const STyp SMacierz <STyp, SWymiar>::Wyznacznik(){
SMacierz <STyp, SWymiar> M = (*this);
STyp pom = 0, wyznacznik = 1;
for (int i = 0; i<SWymiar-1; i++) {
    for (int j = i+1; j<SWymiar; j++) {
        pom = (-1)*M.zwroc_wektor(j).zwroc_wartosc(i)/M.zwroc_wektor(i).zwroc_wartosc(i);
        for (int k = i; k<SWymiar; k++) {
            M.tab[j][k]= M.tab[j][k]+ (pom*M.tab[i][k]);
}
}
}
for (int l = 0; l<SWymiar; l++) {
    wyznacznik = (M.zwroc_wektor(l).zwroc_wartosc(l)* wyznacznik);
}
    return wyznacznik;
}

template <>
const LZespolona SMacierz <LZespolona, ROZMIAR>::Wyznacznik(){
SMacierz <LZespolona, ROZMIAR> M = (*this);
LZespolona pom, wyznacznik;
wyznacznik.re = 1; wyznacznik.im = 0;
for (int i = 0; i<ROZMIAR-1; i++) {
    for (int j = i+1; j<ROZMIAR; j++) {
        pom =(-1)*M.zwroc_wektor(j).zwroc_wartosc(i)/M.zwroc_wektor(i).zwroc_wartosc(i);
        for (int k = i; k<=ROZMIAR; k++) {
            M.tab[j][k] = M.tab[j][k] + (pom * M.tab[i][k]);
}
}
}
for (int l = 0; l<ROZMIAR; l++) {
    wyznacznik = (M.zwroc_wektor(l).zwroc_wartosc(l)* wyznacznik);
}
    return wyznacznik;
}
#endif
