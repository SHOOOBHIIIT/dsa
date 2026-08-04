#include<iostream>
using namespace std;

int main(){
    float s;
    int c = 0;

    cout<<"enter the initial speed of ball: ";
    cin>>s;

    while(s > 0.001){
      c++;
      s = s/2;
    }

    cout<<"no of tips ball will take before stopping: "<<c<<endl;
    return 0;
}
