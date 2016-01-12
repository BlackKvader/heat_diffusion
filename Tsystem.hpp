/*
    Whole sYstem for heat diffusion
    using boost to solve linear equations

    basic equation:
    -c[i-1] + 2(1+R)c[i] - c[i+1] = c_old[i-1] + 2(R-1)c_old[i] + c_old[i+1]

    than solve triangular matrix

    nice source:
    http://web.cecs.pdx.edu/~gerry/class/ME448/notes/pdf/CN_slides.pdf
*/

#include <Eigen/Dense>

#include <string>
// #include <stringstream>
#include <fstream>
#include <iostream>  
#include <cmath>

// #define forAll(comand) for (int forAll_i=0;forAll_i<hate;farAll++){bod[i].command}

using namespace std;
using namespace Eigen;

#define hate 10 // length of the system

class Tsystem{
public:
    // eigen variables
    Matrix<float, hate, 1> c;
    Matrix<float, hate, 1> c_old; // old concentration
    Matrix<float, hate, 1> c_forward; // calculated from forward run
    Matrix<float, hate, 1> c_solution; // solution
    Matrix<float, hate, hate> mat; // matrix for backwad calculation

    int num_step; // current step number
    const string out_file_name;
//    ofstream outfile;

    void init(); // initialization of bod[*], and Tsystem variables
    void makeStep(); // make crank-nicolson diffusion step
    void makeOut(); // make output. Useing n_step
    void run();

    void calcForward();
};