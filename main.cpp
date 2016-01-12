/*
    Simple heat diffusion simulation 1D
    Crank-nicolson

    using boost linear algebra
*/

#include <iostream>
#include <cmath>

#include "Tsystem.hpp"

using namespace std;

int main()
{
    Tsystem heatDif;
    heatDif.run();

    return EXIT_SUCCESS;
}









