#include <iostream>
#include<cmath>
using namespace std;

void hmax(float s, float deg){
    float rad = deg*3.14/180;
    float h = (s*s*sin(rad)*sin(rad))/20;
    cout<<"max height attained: "<<h<<endl;
}

int main(){

    float s, deg;
    cout<<"enter speed and angle: ";
    cin>>s>>deg;

    hmax(s, deg);

    return 0;
}
