#include<iostream>
using namespace std;

void pushstk(int a[], int &n, int x){
    if(n == 100)
    {
        cout << "stack is full\n";
        return;
    }
    a[n] = x;
    n++;
}

void popstk(int a[], int &n){
    if(n == 0){
        cout << "stack is empty\n";
        return;
    }
    cout << a[n-1] << " popped\n";
    n--;
}

void showstk(int a[], int n){
    if(n == 0){
        cout<<"nothing in stack\n";
        return;
    }
    cout << "stack: ";
    for(int i = n-1; i >= 0; i--)
        cout << a[i] << " ";
    cout << endl;
}

int main(){
    int a[100], n = 0;
    int ch, x;

    do
    {
        cout << "\n1.push 2.pop 3.show 4.exit\n";
        cout << "choice: ";
        cin >> ch;

        switch(ch){
            case 1: cout << "value: ";
                    cin >> x;
                    pushstk(a, n, x);
                    break;

            case 2:
             popstk(a, n);
             break;

            case 3: showstk(a, n);
                    break;
        }
    } while(ch != 4);

    return 0;
}
