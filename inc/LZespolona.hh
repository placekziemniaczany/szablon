#ifndef LZESPOLONA_HH
#define LZESPOLONA_HH
#include <iostream>
using namespace std;
/*!
 *  Plik zawiera definicje struktury LZesplona oraz zapowiedzi
 *  przeciazen operatorow arytmetycznych dzialajacych na tej
 *  strukturze.
 */


/*!
 * Modeluje pojecie liczby zespolonej
 */
struct  LZespolona {
  double   re;    /*! Pole repezentuje czesc rzeczywista. */
  double   im;    /*! Pole repezentuje czesc urojona. */
  bool zapis_OK;
  public:
    /*! Pole potrzebne do sprawdzenia poprawnosci formatu l.zespolonej */
};


/*
 * Dalej powinny pojawic sie zapowiedzi definicji przeciazen operatorow
 */

/* Prototypy przeciš¿eñ i funkcji */
LZespolona  operator + (LZespolona  Skl1,  LZespolona  Skl2);
LZespolona operator - (LZespolona, LZespolona);
LZespolona operator * (LZespolona, LZespolona );
LZespolona operator / (LZespolona L1, LZespolona L2);
LZespolona sprzezenie (LZespolona &L1);
LZespolona operator / (LZespolona L, double l);
LZespolona operator += (LZespolona L1, LZespolona L2);

double Modul(LZespolona);
LZespolona utworz(float arg1, float arg2);
LZespolona operator * (LZespolona L, double l);
LZespolona operator * (double l, LZespolona L);
bool operator == (LZespolona L1, LZespolona L2);
ostream& operator << (ostream& StrmWyj, LZespolona liczba);
istream& operator >> (istream &StrmWe, LZespolona &L1);

#endif
