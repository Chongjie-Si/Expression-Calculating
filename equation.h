//
// Created by 司翀杰 on 2019/9/8.
//

#ifndef UNTITLED_EQUATION_H
#define UNTITLED_EQUATION_H

#include <cmath>
#include <iostream>
#include <complex>
using namespace std;

class Equation {
private:
    double real;
    double x;
    double dx;

public:
    //构造函数
    Equation(){real = 0; x = 0; dx = 0;}
    Equation(double real){this->real = real; this->x = 0; this->dx = 0;}
    Equation(double real, double x){this->real = real; this->x = x;this->dx = 0;}
    Equation(double real, double x, double dx){this->real = real; this->x = x; this->dx = dx;}

    double getreal(){return this->real;}
    double getx(){return this->x;}
    double getdx(){return this->dx;}

    //重载运算符

    // +  double
    Equation operator +(const double num){
        Equation ret;
        ret.real = this->real + num;
        ret.x = this->x + num;
        ret.dx = this->dx + num;
        return ret;
    }

    //+ equation
    Equation operator +(const Equation r){
        Equation ret;
        ret.real = this->real + r.real;
        ret.x = this->x + r.x;
        ret.dx = this->dx + r.dx;
        return ret;
    }

    // -  double
      Equation operator -(const double num){
        Equation ret;
        ret.real = this->real - num;
        ret.x = this->x - num;
        ret.dx = this->dx - num;
        return ret;
    }

    //- equation
    Equation operator -(const Equation r){
        Equation ret;
        ret.real = this->real - r.real;
        ret.x = this->x - r.x;
        ret.dx = this->dx - r.dx;
        return ret;
    }

    // *  double
    Equation operator *(const double num) {
        Equation ret;
        ret.real = this->real * num;
        ret.x = this->x * num;
        ret.dx = this->dx * num;
        return ret;
    }

    // * equation
    Equation operator *(const Equation r){
        Equation ret;
        ret.real = this->real * r.real;
        ret.x = this->x * r.real + this->real * r.x;
        ret.dx = this->x * r.x;
        return ret;
    }

    // /  double
    Equation operator /(const double num){
        Equation ret;
        ret.real = this->real / num;
        ret.x = this->x / num;
        ret.dx = this->dx / num;
        return ret;
    }

    // / equation
    Equation operator /(const Equation r){
        if(r.x == 0 and r.dx == 0) {
            Equation ret;
            ret.real = this->real / r.real;
            ret.x = this->x / r.real;
            ret.dx = this->dx / r.real;
            return ret;
        }
        return 0;
    }

    friend double sin(Equation ret);
    friend double cos(Equation ret);
    friend double tan(Equation ret);
    friend double asin(Equation ret);
    friend double acos(Equation ret);
    friend double atan(Equation ret);
    friend double abs(Equation ret);
    friend double log10(Equation ret);
    friend Equation pow(Equation ret1, Equation ret2);
    friend double log(Equation ret);
};


double sin(Equation ret){
    if(ret.x == 0 and ret.dx == 0) return sin(ret.real);
    else return 0;
}
double cos(Equation ret){
    if(ret.x == 0 and ret.dx == 0) return cos(ret.real);
    else return 0;
}
double tan(Equation ret){
    if(ret.x == 0 and ret.dx == 0) return tan(ret.real);
    else return 0;
}
double asin(Equation ret){
    if(ret.x == 0 and ret.dx == 0) return asin(ret.real);
    else return 0;
}
double acos(Equation ret){
    if(ret.x == 0 and ret.dx == 0) return acos(ret.real);
    else return 0;
}
double atan(Equation ret){
    if(ret.x == 0 and ret.dx == 0) return atan(ret.real);
    else return 0;
}
double abs(Equation ret){
    if(ret.x == 0 and ret.dx == 0) return abs(ret.real);
    else return 0;
}
Equation pow(Equation ret1, Equation ret2){
    Equation r;
    if(ret1.dx == 0 and ret2.x == 0 and ret2.dx == 0){
        double t = ret2.real;
        r.real = pow(ret1.real,t);
        r.x = 2 * ret1.real * ret2.x;
        r.dx = ret1.x * ret1.x;
        return r;
    }
    r.real = 0;
    r.x = 0;
    r.dx = 0;
    return r;
}

double log10(Equation ret){
    if(ret.x == 0 and ret.dx == 0) return log10(ret.real);
    else return 0;
}
double log(Equation ret){
    if(ret.x == 0 and ret.dx == 0) return log(ret.real);
    else return 0;
}

void solution(double a, double b, double c){
    if(a == 0){
        if(b == 0) cout<<"方程无解"<<endl;
        else cout<<"x = "<< -c/b<<endl;
    }
    else{
        double delta = b * b - 4 * a * c;
        if(delta < 0) cout<<"方程无实根"<<endl;
        else if(delta > 0) {
            double x1 = (-b - sqrt(delta)) / 2 / a;
            double x2 = (-b + sqrt(delta)) / 2 / a;
            cout << "x1 = " << x1 << ", x2 = " << x2 << endl;
        }
        else{
            double x = -b / 2 / a;
            cout<<"x1 = x2 = "<<x<<endl;
        }
    }
}

#endif //UNTITLED_EQUATION_H
