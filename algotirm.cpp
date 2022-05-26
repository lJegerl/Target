#include "algotirm.h"
#include <cmath>

algotirm::algotirm()
{

}

void algotirm::setRad(int _rad)
{
    rad = _rad;
}

int algotirm::getRad()
{
    return rad;
}

void algotirm::hit(double _rad, double _x1, double _y1)
{
    double x0 = firstX + _rad;
            double y0 = firstY + _rad;
            if (_x1 <= (x0 + _rad) && _x1 >= x0 && _y1 <= (y0 + _rad) && _y1 >= y0) {
                        checkHitSquare = true;
                    }
                    if (!(pow((_x1 - x0), 2) + pow((_y1 - y0), 2) <= pow(_rad, 2))) {
                        checkHitCircuit = true;
                    }
                    if ((_x1 > x0*2) && (_y1 > y0*2) && ((_x1 * _x1 + _y1 * _y1) <= pow(_rad*3.7, 2))) {
                        checkHitSemicircle = true;
                    }
}

bool algotirm::getCheckSquare()
{
    return checkHitSquare;
}

bool algotirm::getCheckCircuit()
{
    return checkHitCircuit;
}

bool algotirm::getCheckSemicircle()
{
    return checkHitSemicircle;
}

void algotirm::setCheckSquare(bool _checkHitSquare)
{
    checkHitSquare = _checkHitSquare;
}

void algotirm::setCheckCircuit(bool _checkHitCircuit)
{
    checkHitCircuit = _checkHitCircuit;
}

void algotirm::setCheckSemicircle(bool _checkHitSemicircle)
{
    checkHitSemicircle = _checkHitSemicircle;
}
