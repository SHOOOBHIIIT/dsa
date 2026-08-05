#include <iostream>
using namespace std;

int finddup(int a[], int n)
{
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            if(a[i] == a[j])
                return a[i];
        }
    }
    return -1;
}

int main(){
    int n, a[100];

    cout<<"enter size of array: ";
    cin>>n;

    cout<<"enter elements: ";
    for(int i=0; i<n; i++)
        cin>>a[i];

    int d = finddup(a, n);

    if(d == -1)
        cout<<"no duplicate element\n";
    else
        cout<<"first duplicate is: "<<d<<endl;

    return 0;
}
