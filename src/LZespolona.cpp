#include "LZespolona.hh"
#include <cmath>
#include <iostream>
#include <cstdlib>
#include <math.h>
#include<cmath>
using namespace std;



ostream& operator << (ostream& StrmWyj, LZespolona liczba) {
  StrmWyj << "(" << liczba.re << showpos << liczba.im << "i)" << noshowpos;
  return StrmWyj;
}
istream & operator >> (istream &StrmWe, LZespolona &L1){
    char lNawias, pNawias, i;
    StrmWe>>lNawias>>L1.re>>L1.im>>i>>pNawias;
    L1.zapis_OK = true;
    if(lNawias != '('){
        L1.zapis_OK = false;
    }
    if(pNawias != ')'){
        L1.zapis_OK = false;
    }
    if(i != 'i'){
        L1.zapis_OK = false;
    }
    if(L1.zapis_OK==false){
        cerr<<"Nieprawidlowy format zespolonej!"<<endl;
        exit(0);
    }
    else {
    return StrmWe;
    }
}

/*!
 * Realizuje dodanie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - pierwszy skladnik dodawania,
 *    Skl2 - drugi skladnik dodawania.
 * Zwraca:
 *    Sume dwoch skladnikow przekazanych jako parametry.
 */
LZespolona  operator + (LZespolona  Skl1,  LZespolona  Skl2)
{
  LZespolona  Wynik;

  Wynik.re = Skl1.re + Skl2.re;
  Wynik.im = Skl1.im + Skl2.im;
  return Wynik;
}
/*!
 * Realizuje odjêcie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - Odjemna
 *    Skl2 - odjemnik
 * Zwraca:
 *    Ró¿nicê dwoch skladnikow przekazanych jako parametry.
 */
LZespolona operator - (LZespolona Skl1, LZespolona Skl2){
  LZespolona wynik;
  wynik.re=Skl1.re-Skl2.re;
  wynik.im=Skl1.im-Skl2.im;
  return wynik;
}
/*!
 * Realizuje mno¿enie dwoch liczb zespolonych.
 * Argumenty:
 *    L1 - pierwszy czynnik,
 *    L2 - drugi czynnik.
 * Zwraca:
 *    Iloczyn dwoch czynnikow przekazanych jako parametry.
 */
LZespolona operator * (LZespolona L1, LZespolona L2){
  LZespolona wynik;
  wynik.re=(L1.re*L2.re)-(L1.im*L2.im);
  wynik.im=(L1.re*L2.im)+(L1.im*L2.re);
  return wynik;
  }
/*!
 * Realizuje sprzezenie liczby zespolonej.
 * Argumenty:
 *    L1 - referencja parametru typu LZespolona,
 * Zwraca:
 *    Sprzezenie liczby zespolonej
 */
LZespolona sprzezenie(LZespolona &L1){
    L1.im=L1.im*(-1);
    return L1;
}
/*!
 * Realizuje Dzielenie liczby zespolonej.
 * Argumenty:
 *    L1 - Dzielna
      L2 - dzielnik
 * Zwraca:
 *    sprzê¿enie ilorazu (nie dzia³a³o bez sprzê¿enia)
 * Dodatkowo:
 * Zmienna pomocnicza temp przechowuje sprzezenie w liczniku ze wzoru na dzielenie
 * liczb zespolonych
 */
LZespolona operator / (LZespolona L1, LZespolona L2){
    LZespolona wynik;
    if (L2.im == 0 && L2.re == 0){
            cerr<<"ERROR: Mianownik jest zerem"<<endl;
            exit(0);
    }
    wynik = L1 * sprzezenie(L2)/pow(Modul(L2),2);
    return wynik;
}
/*
* Funkcja dzieli liczbê zespolon¹ przez liczbê rzeczywist¹
* Parametry:
*    LZespolona L3 - Dzielna
*    LZespolona L4 - modu³ z tej liczby jest dzielnikiem
* Zwraca:
*    Liczbê zespolon¹ dzielon¹ przez modu³ drugiej zespolonej
*/
LZespolona operator / (LZespolona L, double l){
    LZespolona wynik;
    wynik.im = L.im/l;
    wynik.re = L.re/l;
    return wynik;
}
/*!
 * Realizuje liczenie modulu l. zespolonej
 * Argumenty:
 *    L1 - Liczba zespolona z której liczony jest modul
 * Zwraca:
 *    pierwiastek typu double, liczbê która jest modulem l. zespolonej
 */
double Modul(LZespolona L1){
   double wynik , a, b;
   a=L1.re;
   b=L1.im;
   wynik=abs((a*a)+(b*b));
   return sqrt(wynik);
}
/*
* Funkcja tworzy liczbê zespolonš (potrzebne do obliczeñ)
* Parametry:
*    arg 1 - cz. rzeczywista l. zespolonej typu float
*    arg 2 - cz. urojona l. zespolonej typu float
* Zwraca:
*    Liczbê zespolonš utworzonš z argumentów
*/
LZespolona utworz(float arg1, float arg2){
  LZespolona L1;
  L1.re=arg1;
  L1.im=arg2;
  return L1;
}
/*
* Funkcja porównuje dwie liczby zespolone
* Parametry:
*    LZespolona L1 - pierwsza liczba
*    LZespolona L2 - druga liczba
* Zwraca:
*   true - gdy s¹ równe
*   false - gdy nie s¹ równe
*/
bool operator == (LZespolona L1, LZespolona L2){
    if(L1.re==L2.re){
        if(L1.im==L2.im){
            return true;
        }
        else {
            return false;
        }
    }
    else {
        return false;
    }
}
LZespolona operator * (LZespolona L, double l) {
  LZespolona Wynik;
  Wynik.re = L.re * l;
  Wynik.im = L.im * l;
  return Wynik;
}
LZespolona operator * (double l, LZespolona L) {
  LZespolona Wynik;
  Wynik.re = l * L.re;
  Wynik.im = l * L.im;
  return Wynik;
}
LZespolona operator += (LZespolona L1, LZespolona L2){
    L1.re += L2.re;
    L1.im += L2.im;
    return L1;
}

