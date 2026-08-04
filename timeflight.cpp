#include<iostream>
#include<cmath>
using namespace std;

int main()
{
    float s, deg, rad, t;

    cout << "enter speed and angle in degrees: ";
    cin >> s >> deg;

    rad = deg*3.14/180;
    t = (2*s*sin(rad))/10;

    cout<<"time of flight: "<<t<<" sec\n";
    return 0;
}
