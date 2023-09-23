#include <iostream>
#include <cmath>

using namespace std;

long int factorial2 (int n) {

    long int rez = 1;
    
    if (n == 0){
        return rez;
    }

    for (int i = 1; i <= n; i++){
        if (i % 2 == n % 2){
            rez *= i;
        }
    }
    return rez;
}

long double tfunc (double x) {

    long double num = 0;
    for (int k = 0; k <= 10; k++){
        num = num + (pow(x,double(2*k + 1)) / double(factorial2(2*k + 1)));
    }

    long double den = 0;
    for (int k = 0; k <= 10; k++){
        den = den + (pow(x,double(2*k)) / double(factorial2(2*k)));
    }

    long double t = num / den;

    return t;
}

long double result (double y) {

    long double num = 7*tfunc(0.25) + 2*tfunc(1 + y);
    long double den = 6 - tfunc(pow(y, 2) - 1);
    long double rez = num / den;
    return rez;

}

int main () {

    long double y;
    cout << "Enter y:" << endl;
    cin >> y;
    cout << "Resul: " << result(y);

    return 0;
}