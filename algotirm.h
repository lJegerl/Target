#ifndef ALGOTIRM_H
#define ALGOTIRM_H


class algotirm
{
public:
    algotirm();
    void setRad(int _rad);
    int getRad();
    void hit(double _rad, double _x1, double _y1);
    bool getCheckSquare();
    bool getCheckCircuit();
    bool getCheckSemicircle();
    void setCheckSquare(bool _checkHitSquare);
    void setCheckCircuit(bool _checkHitCircuit);
    void setCheckSemicircle(bool _checkHitSemicircle);
private:
    double firstX = 0, firstY = 0;
    double xSq = firstX;
    double ySq = firstY;
    double rad;
    bool checkHitSquare = false;
    bool checkHitCircuit = false;
    bool checkHitSemicircle = false;
};

#endif // ALGOTIRM_H
