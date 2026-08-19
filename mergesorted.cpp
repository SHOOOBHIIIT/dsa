#include <iostream>
using namespace std;

int main(){
    int a1[50], a2[50], m1[100];
    int l1, l2;

    cout<<"how many elements in 1st sorted array: ";
    cin >> l1;
    cout << "elements: ";
    for(int i = 0; i < l1; i++)
        cin >> a1[i];

    cout << "how many elements in 2nd sorted array: ";
    cin >> l2;
    cout<<"elements: ";
    for(int i=0; i<l2; i++)
        cin >> a2[i];

    int i = 0, j = 0, k = 0;
    while(i < l1 && j < l2){
        if(a1[i] < a2[j])
            m1[k++] = a1[i++];
        else
            m1[k++] = a2[j++];
    }

    while(i < l1)
        m1[k++] = a1[i++];
    while(j < l2)
        m1[k++] = a2[j++];

    cout << "after merging: ";
    for(int t = 0; t < k; t++)
        cout << m1[t] << " ";

    cout << endl;

    return 0;
}
