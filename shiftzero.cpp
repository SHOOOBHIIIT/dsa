#include<iostream>
using namespace std;

void shiftzero(int a[], int n){
    int c = 0;

    for(int i = 0; i < n; i++){
        if(a[i] != 0){
         a[c] = a[i];
         c++;
        }
    }

    for(int i=c; i<n; i++)
        a[i] = 0;
}

int main(){
    int n;
    int a[100];

    cout << "how many elements: ";
    cin >> n;

    cout << "enter elements: ";
    for(int i = 0; i < n; i++)
        cin >> a[i];

    shiftzero(a, n);

    cout << "after shifting zeros to end: ";
    for(int i=0; i<n; i++)
        cout << a[i] << " ";
    cout << endl;

    return 0;
}
