#pragma once

#include "size.hh"
#include <iostream>

template <int SIZE>
class Vector {

private:

    double size[SIZE];     //Tablica wektora

public:

    Vector();

    Vector(double [SIZE]);

    Vector<SIZE> operator + (const Vector<SIZE> &v);

    Vector<SIZE> operator - (const Vector<SIZE> &v);

    Vector<SIZE> operator * (const double &tmp);

    Vector<SIZE> operator / (const double &tmp);

    const double &operator [] (int index) const;

    double &operator [] (int index);
    bool operator==(const Vector<SIZE> arg) const;


};

template <int SIZE>
bool Vector<SIZE>::operator==(const Vector<SIZE> arg) const
{
    for(int i=0; i<SIZE; i++)
    if(arg[i]!= size[i] )
    {
        return false;
   }
    return true;
    
}


/******************************************************************************
 |  Konstruktor klasy Vector<SIZE>.                                                 |
 |  Argumenty:                                                                |
 |      Brak argumentow.                                                      |
 |  Zwraca:                                                                   |
 |      Tablice wypelniona wartoscia 0.                                       |
 */
     /*!
    * \brief  Konstruktor klasy Vector<SIZE>. 
    *
    * \param[out]  size - Tablice wypelniona wartoscia 0.
    *
    */
 template <int SIZE>
Vector<SIZE>::Vector() {
    for (int i = 0; i < SIZE; ++i) {
        size[i] = 0;
    }
}


/******************************************************************************
 |  Konstruktor klasy Vector<SIZE>.                                                 |
 |  Argumenty:                                                                |
 |      tmp - Jednowymiarowa tablica typu double.                             |
 |  Zwraca:                                                                   |
 |      Tablice wypelniona wartosciami podanymi w argumencie.                 |
 */
    /*!
    * \brief  Konstruktor klasy Vector<SIZE>. 
    *
    *
    * \param[in]  tmp - Jednowymiarowa tablica typu double.  
    * \param[in]   v - drugi skladnik dodawania.
    * \param[out]  tmp - Tablice wypelniona wartosciami podanymi w argumencie.
    *
    */
template <int SIZE>
Vector<SIZE>::Vector(double tmp[SIZE]) {
    for (int i = 0; i < SIZE; ++i) {
        size[i] = tmp[i];
    }
}



/******************************************************************************
 |  Realizuje dodawanie dwoch wektorow.                                       |
 |  Argumenty:                                                                |
 |      this - pierwszy skladnik dodawania,                                   |
 |      v - drugi skladnik dodawania.                                         |
 |  Zwraca:                                                                   |
 |      Sume dwoch skladnikow przekazanych jako wskaznik                      |
 |      na parametr.                                                          |
 */
    /*!
    * \brief  Realizuje dodawanie dwoch wektorow. 
    *
    *
    * \param[in]  this - pierwszy skladnik dodawania.  
    * \param[in]   v - drugi skladnik dodawania.
    * \param[out]  result - Sume dwoch skladnikow przekazanych jako wskaznik na parametr.
    *
    */
 template <int SIZE>
Vector<SIZE> Vector<SIZE>::operator + (const Vector<SIZE> &v) {
    Vector<SIZE> result;
    for (int i = 0; i < SIZE; ++i) {
        result[i] = size[i] += v[i];
    }
    return result;
}


/******************************************************************************
 |  Realizuje odejmowanie dwoch wektorow.                                     |
 |  Argumenty:                                                                |
 |      this - pierwszy skladnik odejmowania,                                 |
 |      v - drugi skladnik odejmowania.                                       |
 |  Zwraca:                                                                   |
 |      Roznice dwoch skladnikow przekazanych jako wskaznik                   |
 |      na parametr.                                                          |
 */
    /*!
    * \brief  Realizuje odejmowanie dwoch wektorow. 
    *
    *
    * \param[in]  this - pierwszy skladnik odejmowania.  
    * \param[in]   v - drugi skladnik odejmowania.
    * \param[out]  result - Roznice dwoch skladnikow przekazanych jako wskaznik na parametr.
    *
    */
 template <int SIZE>
Vector<SIZE> Vector<SIZE>::operator - (const Vector<SIZE> &v) {
    Vector<SIZE> result;
    for (int i = 0; i < SIZE; ++i) {
        result[i] = size[i] -= v[i];
    }
    return result;
}

   /*!
    * \brief  Realizuje mnozenie wektora przez liczbe zmiennoprzecinkowa. 
    *
    *
    * \param[in]  this - pierwszy skladnik mnozenia (wektor),  
    * \param[in]   v - drugi skladnik mnozenia (liczba typu double).  
    *                   Może być ciągły lub jako zbiór osobnych punktów.
    * \param[out]  result - Iloczyn dwoch skladnikow przekazanych jako wskaznik  na parametr.   
    *                     kwadratu reprezentującego dany punkt.
    *
    */

template <int SIZE>
Vector<SIZE> Vector<SIZE>::operator * (const double &tmp) {
    Vector<SIZE> result;
    for (int i = 0; i < SIZE; ++i) {
        result[i] = size[i] *= tmp;
    }
    return result;
}


 /*!
    * \brief  Realizuje dzielenie dwoch wektorow. 
    *
    *
    * \param[in]  this - licznik dzielenia,  
    * \param[in]   v - mianownik dzielenia.
    * \param[out]  result - Iloraz dwoch skladnikow przekazanych jako wskaznik na parametr.
    */

template <int SIZE>
Vector<SIZE> Vector<SIZE>::operator / (const double &tmp) {
    Vector<SIZE> result;

    for (int i = 0; i < SIZE; ++i) {
        result[i] = size[i] / tmp;
    }

    return result;
}


/******************************************************************************
 |  Funktor wektora.                                                          |
 |  Argumenty:                                                                |
 |      index - index wektora.                                                |
 |  Zwraca:                                                                   |
 |      Wartosc wektora w danym miejscu tablicy jako stala.                   |
 */

  /*!
    * \brief  Funktor wektora.  
    *
    *
    * \param[in]   index - index wektora.
    * \param[out]  index - Wartosc wektora w danym miejscu tablicy jako stala.
    */

 template <int SIZE>
const double &Vector<SIZE>::operator [] (int index) const {
    if (index < 0 || index >= SIZE) {
        std::cerr << "Error: Wektor jest poza zasiegiem!" << std::endl;
    }
    return size[index];
}


/******************************************************************************
 |  Funktor wektora.                                                          |
 |  Argumenty:                                                                |
 |      index - index wektora.                                                |
 |  Zwraca:                                                                   |
 |      Wartosc wektora w danym miejscu tablicy.                              |
 */
 /*!
    * \brief  Funktor wektora.  
    *
    *
    * \param[in]   index - index wektora.
    * \param[out]  index - Wartosc wektora w danym miejscu tablicy.
    */
 template <int SIZE>
double &Vector<SIZE>::operator[](int index) {
    return const_cast<double &>(const_cast<const Vector<SIZE> *>(this)->operator[](index)); // czemu tak ?
}


/******************************************************************************
 |  Przeciazenie operatora <<                                                 |
 |  Argumenty:                                                                |
 |      out - strumien wejsciowy,                                             |
 |      tmp - wektor.                                                         |
 */
 /*!
    * \brief  Przeciazenie operatora << 
    *
    *
    * \param[in]   out - strumien wejsciowy,  
    * \param[in]  tmp - wektor.
    */
 template <int SIZE>
std::ostream &operator << (std::ostream &out, Vector<SIZE> const &tmp) {
    for (int i = 0; i < SIZE; ++i) {
        out  << tmp[i]<<" "; 
    }
    return out;
}

 

/******************************************************************************
 |  Przeciazenie operatora >>                                                 |
 |  Argumenty:                                                                |
 |      in - strumien wyjsciowy,                                              |
 |      tmp - wektor.                                                         |
 */
  /*!
    * \brief  Przeciazenie operatora >>
    *
    *
    * \param[in]   in - strumien wejsciowy,  
    * \param[in]  tmp - wektor.
    */
 template <int SIZE>
std::istream &operator >> (std::istream &in, Vector<SIZE> &tmp) {
    for (int i = 0; i < SIZE; ++i) {
        in >> tmp[i];
    }
    std::cout << std::endl;
    return in;
}
