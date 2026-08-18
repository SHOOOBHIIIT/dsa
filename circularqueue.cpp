#include<iostream>
using namespace std;

class cque{
    int a[5];
    int cap;
    int f;
    int r;
    int cnt;

public:
    cque(){
        cap = 5;
        f = 0;
        r = -1;
        cnt = 0;
    }

    void push(int val){
        if(cnt == cap){
            cout << "circular queue is full\n";
            return;
        }
        r = (r+1)%cap;
        a[r] = val;
        cnt++;
    }

    void pop(){
        if(cnt == 0)
        {
         cout << "circular queue is empty" << endl;
         return;
        }
        f = (f+1)%cap;
        cnt--;
    }

    void show(){
        cout << "circular queue: ";
        for(int i = 0; i < cnt; i++)
            cout << a[(f+i)%cap] << " ";
        cout << endl;
    }
};

int main()
{
    cque q;
    int x;

    cout << "enter 5 values to push: ";
    for(int i=0; i<5; i++){
        cin >> x;
        q.push(x);
    }

    q.show();

    q.pop();
    q.pop();

    cout << "after 2 pops: ";
    q.show();

    return 0;
}
