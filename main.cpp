#include <iostream> // cout 
#include "arit.h"
using namespace std;   // suma, resta

// g++ -std=c++2b main.cpp arit.cpp -o main
// El main() debe ser muy pero muy pequeñito
int main() {
    std::cout << "Hello FundProg-UNI!" << std::endl;
    
    int a = 50;
    int b = 20;
    int c = suma(a, b);
    cout << c << endl;
    cout << "La suma de " << a << " y " << b << " es " << c << endl;
    int d = resta(a, b);
    cout << d <<endl;
    cout << "La resta de " << a << " y " << b << " es " << d << endl;
    int e= producto(a,b);
    cout<<e<<endl;
    cout << "el producto de " << a << " y " << b << " es " << e << endl;
    int f= cociente(a,b);
    cout<<" el cociente es "<<f;
    return 0;
} 