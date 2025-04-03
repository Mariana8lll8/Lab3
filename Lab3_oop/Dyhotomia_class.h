#pragma once
#include <iostream>
#include <cmath>

class Dyhotomia_class
{
public:
    Dyhotomia_class(void);
    ~Dyhotomia_class(void);

    void setVolumes(double vol_a, double vol_b);
    void setTolerance(double vol_eps);
    int count(double &x);

private:
    double a, b, eps;
    double func(double x); 
};

class NewtonMethod
{
public:
    NewtonMethod(void);
    ~NewtonMethod(void);

    void setVolumes(double vol_x0);
    void setTolerance(double vol_eps);
    int count(double &x);

private:
    double x0, eps;
    double func(double x);
    double dfunc(double x); 
};
