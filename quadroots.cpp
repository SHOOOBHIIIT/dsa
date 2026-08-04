#include <iostream>
#include <cmath>
using namespace std;

int main(){
    float a, b, c, d;

    cout << "enter coefficients a b c: ";
    cin >> a >> b >> c;

    d = b*b - 4*a*c;

    if(d == 0)
    {
        cout << "both roots are real and equal: " << -b/(2*a) << "\n";
    }
    else if(d > 0){
        cout<<"roots are real and distinct: "<< (-b+sqrt(d))/(2*a) <<" and "<< (-b-sqrt(d))/(2*a) <<endl;
    }
    else
    {
        cout << "roots are imaginary\n";
    }

    return 0;
}
