//
//  Vector.hpp
//  RobotCollisionAvoidance
//
//  Created by Elie Drai on 05/02/2018.
//  Copyright © 2018 Elie Drai. All rights reserved.
//

#ifndef Vector_hpp
#define Vector_hpp

#include <stdio.h>
#include <cmath>
using namespace std;

class Vector
{
protected:
    //  FIELDS
    double x;
    double y;
    
public:
    //  Properties
    double X() { return x; }
    double Y() { return y; }
    void setX(double d) { x = d; }
    void setY(double d) { y = d; }
    /////////////////////////////////
    
    //  Constructors
    Vector(double xx = 0, double yy=0) : x(xx), y(yy) {}
    Vector(const Vector& v) : Vector(v.x, v.y) {}
    ~Vector() {}
    /////////////////////////////////
    
    //  Methods
    double Length() { return sqrt(x*x + y*y); }
    void Print();
    Vector Unit() { return Vector(x/Length(), y/Length()); }
    double Angle() { return atan2(y, x);}
    Vector RelativeVectorAccordingTo(Vector v) { return Vector(x-v.x, y-v.y);}
    
    /////////////////////////////////
    
    //  Static methods
    static bool Collinears(Vector v,Vector w) { return v*w == 0;}
    static bool Orthogonals(Vector v, Vector w) { return v.x*w.y - v.y*w.x == 0;}
    static bool Opposites(Vector v, Vector w);
    static Vector UnitX() { return Vector(1, 0); }
    static Vector UnitY() { return Vector(0, 1); }
    static Vector Null() { return Vector (0,0); }
    /////////////////////////////////

    
    //  Operators
    double operator*(const Vector& v) {return x*v.x + y*v.y;}
    Vector operator+(const Vector& v) { return Vector(x+v.x, y+v.y); }
    Vector operator-(const Vector& v) { return Vector(x-v.x, y-v.y); }
    Vector operator+(double value) { return Vector(value*x, value*y); }
    void operator=(Vector v) { x = v.x; y = v.y; }
    /////////////////////////////////

};

#endif /* Vector_hpp */
