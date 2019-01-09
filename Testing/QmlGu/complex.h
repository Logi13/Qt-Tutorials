#ifndef COMPLEX_H
#define COMPLEX_H

#include <cmath>
#include <complex>
using namespace std;

class Complex
{
public:
    Complex();
    complex<double> z = 0.0;
    complex<double> c = -2.0 + (-2.0i);
    complex<double> Mandelbrot(complex<double> c, complex<double> z, int max_iter);
};



#endif // COMPLEX_H
