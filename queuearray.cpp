#include <iostream>
using namespace std;

void enq(int a[], int &n, int x){
    if(n == 100){
        cout << "queue is full\n";
        return;
    }
    a[n] = x;
    n++;
}

void deq(int a[], int &n){
    if(n == 0)
    {
        cout<<"queue is empty\n";
        return;
    }
    cout << a[0] << " removed\n";
    for(int i = 0; i < n-1; i++)
        a[i] = a[i+1];
    n--;
}

void showq(int a[], int n){
    if(n == 0){
        cout<<"queue is empty\n";
        return;
    }
    cout << "queue: ";
    for(int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout<<"\n";
}

int main(){
    int a[100], n = 0;
    int ch, x;

    do{
        cout << "\n1.enqueue 2.dequeue 3.show 4.exit" << endl;
        cout<<"choice: ";
        cin >> ch;

        switch(ch)
        {
            case 1: cout<<"value: ";
                    cin >> x;
                    enq(a, n, x);
                    break;
            case 2: deq(a, n); break;
            case 3: showq(a, n); break;
        }

    }while(ch != 4);

    return 0;
}
