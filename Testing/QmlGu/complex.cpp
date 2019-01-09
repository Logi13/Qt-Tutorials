#include "complex.h"

#include <QDebug>

Complex::Complex()
{

}

complex<double> Mandelbrot(complex<double> c, complex<double> z, int max_iter){
    int iter = 0;
    double Re[2][3] = {};
    double Im[2][3] = {};

    while(abs(z) < 2.0 && iter < max_iter){
        z = z * z + c;
        Re[iter][iter] = { z.real() };
        Im[iter][iter] = { z.imag() };
    }
    qDebug() << iter;
    return iter;
};
