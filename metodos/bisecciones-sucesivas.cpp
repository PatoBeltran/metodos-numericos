/* =================================== *
 *  Patricio Marcelo Beltrán Saldívar  *
 *  Roel Castaño                       *
 *  Mac OS X 10.9.1 Mavericks          *
 *  Métodos numéricos en la Ingeniería *
 *  Método de Bisecciones Sucesivas    *
 *  Encontrar raíz de funciones        *
 *  C++                                *
 * =================================== */

#include <iostream>
#include <math.h>
#include <cmath>
#include <iomanip>

using namespace std;

/* =============== Constants ================== */

//maximum error
const double ERROR = .05;

//maximum number of iterations
const int MAX_I = 40;

//initial value for the first interval
const double A = 0.0;
const double B = 1.3;

//number of decimal places printed
const int PRECISION = 3;

//function for the algebraic ecuation
double f(double x)
{
    return pow(x,10) - 1;
}
/* ============================================= */

//main program
int main()
{
    //Declare variables
    double xtest;

    double a = A;
    double b = B;

    double i = 0;
    double Ea = 100;

    double fa;
    double fb;

    //set printing values to the number of decimal places set in precision
    cout.setf(ios::fixed,ios::floatfield);
    cout<<setprecision(PRECISION);

    //print table header
    cout<<"     a     |     b     |      x    |      i      |     E   "<<endl
    <<"==============================================================="<<endl;

    //iterations for numeric method
    while(Ea > ERROR & i < MAX_I){

        // get the values of the function in the start and end point
        fb = f(b);
        fa = f(a);

        // get the value in the middle of the range
        xtest = (a + b)/2.0;

        //print all the information with the corresponding spaces
        if (i<10){
            cout<<"   "<<a<<"   |   "<<b<<"   |   "<<xtest<<"   |   "<<i<<"     |   "<<Ea<<"   "<<endl;
        }else if(i<100){
            cout<<"   "<<a<<"   |   "<<b<<"   |   "<<xtest<<"   |   "<<i<<"    |   "<<Ea<<"   "<<endl;
        }
        else {
            cout<<"   "<<a<<"   |   "<<b<<"   |   "<<xtest<<"   |   "<<i<<"   |   "<<Ea<<"   "<<endl;
        }

        //check if solution has been found
        if(fa*fb == 0){
            //print table footer and answer
            cout<<"==============================================================="<<endl
            <<"Raiz exacta: ";
            fa == 0 ? cout<<a<<endl : cout<<b<<endl;
            return 0;
        }

        //check if solution has been found
        if(f(xtest) == 0){
            //print table footer and answer
            cout<<"==============================================================="<<endl
            <<endl<<"Raiz exacta: "<<xtest<<endl<<endl;
            return 0;
        }
        else if(f(xtest) > 0) {
            //change range by half
            Ea = (abs(xtest - b)/xtest) *100;
            b = xtest;
        }
        else {
            //change range by half
            Ea = (abs(xtest - a)/xtest) *100;
            a = xtest;
        }

        i++;
    }
    //print table footer and answer
    cout<<"==============================================================="<<endl;
    if(i>=MAX_I){
        cout<<endl<<"Raiz por máximo de iteraciones: "<<xtest<<endl<<endl;
    }
    else {
        cout<<endl<<"Raiz por minimo de error: "<<xtest<<endl<<endl;
    }
    return 0;
}
