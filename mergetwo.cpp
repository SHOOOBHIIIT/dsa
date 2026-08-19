#include<iostream>
using namespace std;

void readarr(int x[], int m, char name){
    cout<<"enter "<<m<<" elements of array "<<name<<" in sorted way: ";
    for(int i = 0; i < m; i++)
        cin >> x[i];
}

int main()
{
    int x[50], y[50], z[100];
    int m, n;

    cout<<"size of 1st array: ";
    cin >> m;
    readarr(x, m, 'A');

    cout<<"size of 2nd array: ";
    cin >> n;
    readarr(y, n, 'B');

    int p = 0, q = 0, k = 0;
    while(p < m && q < n)
    {
      if(x[p] <= y[q])
       z[k++] = x[p++];
      else
       z[k++] = y[q++];
    }

    while(p < m)
     z[k++] = x[p++];

    while(q < n)
     z[k++] = y[q++];

    cout<<"merged sorted array: ";
    for(int t = 0; t < k; t++)
        cout<<z[t]<<" ";
    cout<<"\n";

    return 0;
}
