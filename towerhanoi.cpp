#include <iostream>
using namespace std;

void toh(int n, char s, char u , char d)
{
    if(n == 1){
        cout << "move disk 1 from " << s << " to " << d << endl;
        return;
    }

    toh(n-1, s, d, u);
    cout << "move disk " << n << " from " << s << " to " << d << "\n";
    toh(n-1, u, s, d);
}

int main()
{
    int n;
    cout<<"enter no of disks: ";
    cin>>n;

    toh(n, 'S', 'U', 'D');

    return 0;
}
