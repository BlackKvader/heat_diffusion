/*
    Simple heat diffusion simulation 1D
    Crank-nicolson

    using boost linear algebra
    It turn out that boost don't have basic algebra :)

    But, there is finaly solution. Eigen :)
*/


#include <iostream>
#include <Eigen/Dense>  // very slow to compile ... 

using namespace std;
using namespace Eigen;

class TfuckEigen{
public:
    Matrix<float, 3, 1> fuck;

    void fuckMe();
};

void TfuckEigen::fuckMe(){
    fuck << 1,2,3; // ondatry
    cout << fuck(1);
}

int main()
{
    TfuckEigen MadaFucker;
    MadaFucker.fuckMe();
    cout << MadaFucker.fuck << endl;

    MatrixXf A(3,3);
   // Matrix3f A;
    Vector3f b;
    VectorXf c(3);

    A << 1,2,3,  4,5,6,  7,8,10;
    b << 3, 3, 4;
    c=b;

    cout << "Here is the matrix A:\n" << A << endl;
    cout << "Here is the vector b:\n" << b << endl;

    Vector3f x = A.colPivHouseholderQr().solve(b);

    cout << "The solution is:\n" << x << endl;

    int num=1;

    cout << "back check: " << A*x << endl;
    cout << "is matrix changed? " << endl << A << endl << b << endl;
    cout << "just second numbers: " << A(num,num) << "  " << b(num) << endl;
    cout << "c:" << endl << c << endl;
}