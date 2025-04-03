#include "Dyhotomia_class.h"
#include <iostream>
#include <cmath>

using namespace std;

Dyhotomia_class::Dyhotomia_class() {}
Dyhotomia_class::~Dyhotomia_class() {}

double Dyhotomia_class::func(double x)
{
    return 3 * x - 4 * log(x) - 5; 
}

void Dyhotomia_class::setVolumes(double vol_a, double vol_b)
{
    a = vol_a;
    b = vol_b;
}

void Dyhotomia_class::setTolerance(double vol_eps)
{
    eps = vol_eps;
}

int Dyhotomia_class::count(double &x)
{
    if (func(a) * func(b) > 0)
    {
        cout << "Немає розв'язку на проміжку" << endl;
        return 1;
    }
    double c;
    while ((b - a) > eps)
    {
        c = (a + b) / 2;

        if (func(c) == 0)
        {
            x = c;
            return 0;
        }
        else if (func(a) * func(c) < 0)
        {
            b = c;
        }
        else
        {
            a = c;
        }
    }
    x = (a + b) / 2;
    return 0;
}

NewtonMethod::NewtonMethod() {}
NewtonMethod::~NewtonMethod() {}

double NewtonMethod::func(double x)
{
    return 3 * x - 4 * log(x) - 5;
}

double NewtonMethod::dfunc(double x)
{
    return 3 - 4 / x;
}

void NewtonMethod::setVolumes(double vol_x0)
{
    x0 = vol_x0;
}

void NewtonMethod::setTolerance(double vol_eps)
{
    eps = vol_eps;
}

int NewtonMethod::count(double &x)
{
    x = x0;

    while (fabs(func(x)) > eps)
    {
        if (dfunc(x) == 0)
        {
            cout << "Помилка: похідна стала нулем" << endl;
            return 1;
        }
        x = x - func(x) / dfunc(x);
    }
    return 0;
}
