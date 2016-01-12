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

#include "Tsystem.hpp"

// #include "Tbod.hpp"


#define D  1
#define dt  1
#define dx  1 
#define max_step  50
#define OUT_FILE_NAME "out1/out"
#define R 1.0*dx*dx/(dt*D)

// #define forAll(comand) for (int forAll_i=0;forAll_i<hate;farAll++){bod[i].command}

using namespace std;
using namespace Eigen;

void Tsystem::init(){
    // matrix initialization
    for (int r=0;r<hate;r++)
        for (int s=0;s<hate;s++)
            mat(r,s)=0;

    for (int i=0;i<hate-1;i++){
        mat(i,i+1)=1; // horny okraj
        mat(i+1,i)=1; // spodny okraj
    }
    for (int i=0;i<hate;i++){
        mat(i,i+1)=2+2.0*R; // diagonala
    }

    // c_old initialization
    for (int i=0;i<round(hate/3);i++)
        c_old(i)=0;
    for (int i=round(hate/3);i<round(2.0*hate/3);i++)
        c_old(i)=200;
    for (int i=round(2.0*hate/3);i<hate;i++)
        c_old(i)=0; 

    c=c_old; // for first rewrite
    num_step=0;
}

void Tsystem::calcForward(){
    // first edge
    c_forward(0) = 2.0*(R-1)*c_old(0)+c_old(1);
    // middle
    for (int i=1;i<(hate-1);i++){
        c_forward(i) = c_old(i-1) + 2.0*(R-1)*c_old(i) + c_old(i+1);
    }
    // last edge
    c_forward(hate-1) = c_old(hate-2) + 2.0*(R-1)*c_old(hate-1);
}

void Tsystem::makeStep(){
    // calculate forward euler
    calcForward();
    // calculation of matrixes is not necessary. mat is constant
    // solve system  (backward)
    c_solution = mat.colPivHouseholderQr().solve(c_forward);
    // update everything
    num_step++;
    c_old=c;
    c=c_solution;
    // time = ...
}

void Tsystem::makeOut(){
    string s;
    s = "out/" + num_step;
    ofstream outfile(s.c_str());
    for (int i=0;i<hate;i++){
        outfile << c(i) << endl;
    }
}

void Tsystem::run(){
    init();
    for (int i=0;i<max_step;i++)
        makeStep();

    cout << "simulation done" << endl;
}
