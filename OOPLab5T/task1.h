#pragma once
#include <iostream>


using namespace std;

class Quad {
protected:
    double a;
    double b;
    double c;
    double d;

public:
    Quad(double a, double b, double c, double d) : a(a), b(b), c(c), d(d) {}

     void print() const {
        std::cout << "Quad" << std::endl;
    }


     double P() const {
         return a + b + c + d;
     }

     ~Quad() {}
};

class Rectangle : public Quad {
public:
    Rectangle(double length, double width) : Quad(length, width, length, width) {}

     void print() const {
        std::cout << "Rectangle" << std::endl;
    }

     double S() const {
        return a * b;
    }

    double P() const {
        return 2 * (a + b);
    }

    ~Rectangle() {}
};


class Square : public Rectangle {
public:
    Square(double side) : Rectangle(side, side) {}

     void print() const {
        std::cout << "Square" << std::endl;
    }

     ~Square() {}
};
