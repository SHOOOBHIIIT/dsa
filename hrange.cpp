#include<iostream>
#include <cmath>
using namespace std;

float rng(float s, float deg)
{
    float rad = deg*3.14/180;
    return (s*s*sin(2*rad))/10;
}

int main(){
    float s,deg;
    cout << "enter speed and angle: ";
    cin >> s >> deg;
    cout << "horizontal range: " << rng(s,deg) << "\n";
    return 0;
}
