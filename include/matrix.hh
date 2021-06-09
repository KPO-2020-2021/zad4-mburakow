#pragma once

#include "size.hh"
#include "vector.hh"
#include <iostream>
#include <cmath>
#include <cstdlib>
template <int SIZE>
class Matrix {

private:
    double value[SIZE][SIZE];               // Wartosci macierzy

public:
    Matrix(double [SIZE][SIZE]);            // Konstruktor klasy

    Matrix();                               // Konstruktor klasy

    Vector<SIZE> operator * (Vector<SIZE> tmp);           // Operator mnożenia przez wektor
    Matrix<SIZE> operator * (Matrix<SIZE> tmp);         
    Matrix<SIZE> operator + (Matrix<SIZE> tmp);
    double  &operator () (unsigned int row, unsigned int column);
    float Wyznacznik();
    const double &operator () (unsigned int row, unsigned int column) const;
    
};

template <int SIZE>
Matrix<SIZE> Matrix<SIZE>::operator*(Matrix<SIZE> tmp)
{
    Matrix<SIZE> result;
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            result(i, j) = 0;
            for (int k = 0; k < SIZE; k++)
                result(i, j) += this->value[i][k] * tmp(k, j);
        }
    }
    return result;
}


/******************************************************************************
 |  Konstruktor klasy Matrix<SIZE>.                                                 |
 |  Argumenty:                                                                |
 |      Brak argumentow.                                                      |
 |  Zwraca:                                                                   |
 |      Macierz wypelnione wartoscia 0.                                       |
 */
   /*!
    * \brief  Konstruktor klasy Matrix<SIZE>
    *
    * \param[out]  value - Macierz wypelnione wartoscia 0. 
    *
    */
 template <int SIZE>
Matrix<SIZE>::Matrix() {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            if(i==j)
            value[i][j] = 1;
            else
            value[i][j] = 0;
        }
    }
}


/******************************************************************************
 |  Konstruktor parametryczny klasy Matrix<SIZE>.                                              |
 |  Argumenty:                                                                |
 |      tmp - dwuwymiarowa tablica z elementami typu double.                               |
 |  Zwraca:                                                                   |
 |      Macierz wypelniona wartosciami podanymi w argumencie.                 |
 */
    /*!
    * \brief  Konstruktor parametryczny klasy Matrix<SIZE>.
    *
    *
    * \param[in]  tmp - dwuwymiarowa tablica z elementami typu double. 
    * \param[out]  value - Macierz wypelniona wartosciami podanymi w argumencie. 
    *
    */
 template <int SIZE>
Matrix<SIZE>::Matrix(double tmp[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            value[i][j] = tmp[i][j];
        }
    }
}


/******************************************************************************
 |  Realizuje mnozenie macierzy przez wektor.                                 |
 |  Argumenty:                                                                |
 |      this - macierz, czyli pierwszy skladnik mnozenia,                     |
 |      v - wektor, czyli drugi skladnik mnozenia.                            |
 |  Zwraca:                                                                   |
 |      Iloczyn dwoch skladnikow przekazanych jako wektor.                    |
 */
    /*!
    * \brief  Realizuje mnozenie macierzy przez wektor.   
    *
    *
    * \param[in]  this - macierz, czyli pierwszy skladnik mnozenia,
    * \param[in]   v - wektor, czyli drugi skladnik mnozenia.
    * \param[out]  result - Iloczyn dwoch skladnikow przekazanych jako wektor. 
    *
    */
template <int SIZE>
Vector<SIZE> Matrix<SIZE>::operator * (Vector<SIZE> tmp) {
    Vector<SIZE> result;
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            result[i] += value[i][j] * tmp[j];
        }
    }
    return result;
}


/******************************************************************************
 |  Funktor macierzy                                                          |
 |  Argumenty:                                                                |
 |      row - numer wiersza.                                                  |
 |      column - numer kolumny.                                               |
 |  Zwraca:                                                                   |
 |      Wartosc macierzy w danym miejscu tablicy.                             |
 */
     /*!
    * \brief   Funktor macierzy    
    *
    *
    * \param[in]  row - numer wiersza.
    * \param[in]   column - numer kolumny.
    * \param[out]  value - Wartosc macierzy w danym miejscu tablicy. 
    *
    */
 template <int SIZE>
double &Matrix<SIZE>::operator()(unsigned int row, unsigned int column) {

    if (row >= SIZE) {
        throw "Error: Macierz jest poza zasiegiem"; 
        exit(0); // lepiej byłoby rzucić wyjątkiem stdexcept
    }

    if (column >= SIZE) {
        throw "Error: Macierz jest poza zasiegiem";
        exit(0); // lepiej byłoby rzucić wyjątkiem stdexcept
    }

    return value[row][column];
}


/******************************************************************************
 |  Funktor macierzy                                                          |
 |  Argumenty:                                                                |
 |      row - numer wiersza.                                                  |
 |      column - numer kolumny.                                               |
 |  Zwraca:                                                                   |
 |      Wartosc macierzy w danym miejscu tablicy jako stala.                  |
 */

      /*!
    * \brief   Funktor macierzy    
    *
    * \param[in]  row - numer wiersza.
    * \param[in]   column - numer kolumny.
    * \param[out]  value - Wartosc macierzy w danym miejscu tablicy jako stala. 
    *
    */
 template <int SIZE>
const double &Matrix<SIZE>::operator () (unsigned int row, unsigned int column) const {

    if (row >= SIZE) {
       throw "Error: Macierz jest poza zasiegiem";
        exit(0); // lepiej byłoby rzucić wyjątkiem stdexcept
    }

    if (column >= SIZE) {
        throw "Error: Macierz jest poza zasiegiem";
        exit(0); // lepiej byłoby rzucić wyjątkiem stdexcept
    }

    return value[row][column];
}

/******************************************************************************
 |  Przeciążenie dodawania macierzy                                                          |
 |  Argumenty:                                                                |
 |      this - macierz, czyli pierwszy skladnik dodawania,                     |
 |      v - wektor, czyli drugi skladnik dodawania.                                               |
 |  Zwraca:                                                                   |
 |      Macierz - iloczyn dwóch podanych macierzy.                  |
 */

    /*!
    * \brief   Przeciążenie dodawania macierzy     
    *
    * \param[in]  this - macierz, czyli pierwszy skladnik dodawania, 
    * \param[in]   v - wektor, czyli drugi skladnik dodawania. 
    * \param[out]  result - Macierz - iloczyn dwóch podanych macierzy.
    *
    */
 template <int SIZE>
Matrix<SIZE> Matrix<SIZE>::operator + (Matrix<SIZE> tmp) {
    Matrix<SIZE> result;
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            result(i, j) = this->value[i][j] + tmp(i, j);
        }
    }
    return result;
}

/******************************************************************************
 |  Przeciazenie operatora >>                                                 |
 |  Argumenty:                                                                |
 |      in - strumien wyjsciowy,                                              |
 |      mat - macierz.                                                         |
 */

     /*!
    * \brief   Przeciazenie operatora >>  
    *
    * \param[in]  in - strumien wyjsciowy,  
    * \param[in]   mat - macierz.  
    * \param[out]  in
    *
    */
 template <int SIZE>
std::istream &operator>>(std::istream &in, Matrix<SIZE> &mat) {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            in >> mat(i, j);
        }
    }
    return in;
}


/******************************************************************************
 |  Przeciazenie operatora <<                                                 |
 |  Argumenty:                                                                |
 |      out - strumien wejsciowy,                                             |
 |      mat - macierz.                                                        |
 */
    /*!
    * \brief   Przeciazenie operatora <<  
    *
    * \param[in]  out - strumien wejsciowy,   
    * \param[in]   mat - macierz.  
    * \param[out]  out
    *
    */
 template <int SIZE>
std::ostream &operator<<(std::ostream &out, const Matrix<SIZE> &mat) {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            out << "| " << mat(i, j) << " | "; //warto ustalic szerokosc wyswietlania dokladnosci liczb
        }
        std::cout << std::endl;
    }
    return out;
}

template <int SIZE>
float Matrix<SIZE>::Wyznacznik()
{


float wyznacznik = 1;
Matrix<SIZE> tablica=*this;
for (int k = 0; k <  SIZE - 1; k++)
{

for (int i = (1+k); i <  SIZE; i++)
{

for (int j = (0+k); j <  SIZE; j++)
{
tablica(i,j) = tablica(i,j)-((tablica(i,k) /  tablica(k,k))*tablica(k,j));
}
}
}


for(int i =0 ; i< SIZE ;i++)
wyznacznik=wyznacznik*tablica(i,i);
return wyznacznik;

} 


Matrix<3> obr_x(double kat){
    double rad = kat * M_PI/180;
    Matrix<3> wynik;
    wynik(0, 0) = 1;
    wynik(0, 1) = 0;
    wynik(0, 2) = 0;

    wynik(1, 0) = 0;
    wynik(1, 1) = cos(rad);
    wynik(1, 2) = -sin(rad);

    wynik(2, 0) = 0;
    wynik(2, 1) = sin(rad);
    wynik(2, 2) = cos(rad);
    return wynik;
}
Matrix<3> obr_y(double kat)
{
    double rad = kat * M_PI / 180;
    Matrix<3> wynik;
    wynik(0, 0) = cos(rad);;
    wynik(0, 1) = 0;
    wynik(0, 2) = sin(rad);

    wynik(1, 0) = 0;
    wynik(1, 1) = 1;
    wynik(1, 2) = 0;

    wynik(2, 0) = -sin(rad);
    wynik(2, 1) = 0;
    wynik(2, 2) = cos(rad);
    return wynik;
}
Matrix<3> obr_z(double kat)
{
    double rad = kat * M_PI / 180;
    Matrix<3> wynik;
    wynik(0, 0) = cos(rad);;
    wynik(0, 1) = -sin(rad);
    wynik(0, 2) = 0;

    wynik(1, 0) = sin(rad);
    wynik(1, 1) = cos(rad);
    wynik(1, 2) = 0;

    wynik(2, 0) = 0;
    wynik(2, 1) = 0;
    wynik(2, 2) = 1;
    return wynik;
}