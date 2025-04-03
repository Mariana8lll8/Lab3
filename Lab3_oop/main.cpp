#include "Dyhotomia_class.h"
#include <iostream>

using namespace std;

int main()
{
    const double eps = 1e-9;
    double a, b, x0, root;
    Dyhotomia_class *dyh = new Dyhotomia_class();
    NewtonMethod *nm = new NewtonMethod();

    cout << "Введіть a, b для методу дихотомії: ";
    cin >> a >> b;
    dyh->setVolumes(a, b);
    dyh->setTolerance(eps);
    if (dyh->count(root) == 0)
        cout << "Корінь (дихотомія): " << root << endl;

    cout << "Введіть x0 для методу Ньютона: ";
    cin >> x0;
    nm->setVolumes(x0);
    nm->setTolerance(eps);
    if (nm->count(root) == 0)
        cout << "Корінь (метод Ньютона): " << root << endl;

    delete dyh;
    delete nm;

    return 0;
}