#ifndef COMPLEXNUMBERS_H
#define COMPLEXNUMBERS_H

#include <QObject>
#include <complex>

using namespace std;

class ComplexNumbers : public QObject
{
    Q_OBJECT
public:
    ComplexNumbers(double c_real, double c_imag, double max_iterations);

};

#endif // COMPLEXNUMBERS_H
