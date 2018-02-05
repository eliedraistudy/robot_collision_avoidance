//
//  Vector.cpp
//  RobotCollisionAvoidance
//
//  Created by Elie Drai on 05/02/2018.
//  Copyright © 2018 Elie Drai. All rights reserved.
//

#include "Vector.hpp"
#include <iostream>
#include <iomanip>
using namespace std;

void Vector::Print()
{
    cout << "[ ";
    cout << std::fixed << setprecision(2) << X();
    cout << " , ";
    cout << std::fixed << setprecision(2) << Y() << " ] ";
}

bool Vector::Opposites(Vector v, Vector w)
{
    if(!Collinears(w, v))
        return false;
    return (w.x * v.x <= 0 && w.y*v.y <= 0);
}
