#pragma once

#include "size.hh"
#include "vector.hh"
#include <iostream>

class Prism
{

private:
    Vector<3> size[SIZE_Prism]; //Tablica wektora

public:
    Prism();

    Prism(Vector<3> Start,  double h, double w, double l);

    Prism operator+(const Vector<3> &v);

    const Vector<3> &operator[](int index) const;

    Vector<3> &operator[](int index);
void rotacion(Matrix<3> arg)
    {
        for(int i=0; i<8; i++)
        {
size[i]=arg*size[i];
        }
        
    }
    void move(Vector<3> arg)
    {
         *this=*this+arg;
    }
};

Prism::Prism()
{
}

Prism::Prism(Vector<3> Start, double h, double w, double l)
{
    for (int i = 0; i < SIZE_Prism; i++)
        size[i] = Start;

    size[1][0] += w;

    
    size[2][1] += h;

    size[3][0] += w;
    size[3][1] += h;

    size[4][1] += h;
    size[4][2] += l;

  size[5][0] += w;
  size[5][1] += h;
    size[5][2] += l;
    size[6][2] += l;

      size[7][0] += w;
    size[7][2] += l;
}
/*!
    * \brief  Realizuje dodawanie prostokata z wektorem. 
    *
    *
    * \param[in]  this - pierwszy skladnik dodawania (prostokat),  
    * \param[in]   v - drugi skladnik dodawania (Vector).  
    * \param[out]  result - przesuniecie prostokata o wektor
    *
    */
Prism Prism::operator+(const Vector<3> &v)
{
    Prism result;
    for (int i = 0; i < SIZE_Prism; ++i)
    {
        result[i] = size[i] + v;
    }
    return result;
}


/*!
    * \brief  Funktor prostokata.
    *
    *
    * \param[in]  index - index prostokata.  
    * \param[out]  size - Wartosc prostokata w danym miejscu tablicy jako stala.
    *
    */
const Vector<3> &Prism::operator[](int index) const
{
    return size[index];
}

/*!
    * \brief  Funktor prostokata.
    *
    *
    * \param[in]  index - index prostokata.  
    * \param[out]  size - Wartosc prostokata w danym miejscu tablicy.
    *
    */
Vector<3> &Prism::operator[](int index)
{
    return size[index];
}

/*!
    * \brief  Przeciazenie operatora <<  
    *
    *
    * \param[in]  out - strumien wejsciowy,   
    * \param[in]  tmp - prostokat. 
    * \param[out] out
    */
std::ostream &operator<<(std::ostream &out, Prism const &tmp)
{
    for (int i = 0; i < SIZE_Prism; ++i)
    {
        out << tmp[i] << std::endl;
        if((i+1)%2==0)
                out <<  std::endl;
    }
 
    return out;
}

