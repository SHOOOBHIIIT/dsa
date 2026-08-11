#include <iostream>
using namespace std;
class list
{
    int a[100];
    int n = 0;
public:
    void insert(int p, int x)
    {
        if (n == 100)
        {
            cout << "list is full\n";
            return;
        }
        if (p < 0 || p > n)
        {
            cout << "wrong position\n";
            return;
        }
        for (int i = n; i > p; i--)
            a[i] = a[i - 1];
        a[p] = x;
        n++;
    }

    void del(int p)
    {
        if (n == 0)
        {
            cout << "list is empty\n";
            return;
        }
        if (p < 0 || p >= n)
        {
            cout << "wrong position\n";
            return;
        }
        for (int i = p; i < n - 1; i++)
            a[i] = a[i + 1];
        n--;
    }

    int search(int x)
    {
        for (int i = 0; i < n; i++)
        {
            if (a[i] == x)
                return i;
        }
        return -1;
    }

    void update(int p, int x)
    {
        if (p < 0 || p >= n)
        {
            cout << "wrong position\n";
            return;
        }
        a[p] = x;
    }

    void display()
    {
        if (n == 0)
        {
            cout << "list is empty\n";
            return;
        }
        cout << "list: ";
        for (int i = 0; i < n; i++)
            cout << a[i] << " ";
        cout << "\n";
    }
};

int main()
{
    list l;
    int ch, p, x;

    do
    {
        cout << "\n1.insert 2.delete 3.search 4.update 5.display 6.exit\n";
        cout << "enter choice: ";
        cin >> ch;

        switch (ch)
        {
        case 1:
            cout << "enter position and value: ";
            cin >> p >> x;
            l.insert(p, x);
            break;
        case 2:
            cout << "enter position: ";
            cin >> p;
            l.del(p);
            break;
        case 3:
            cout << "enter value: ";
            cin >> x;
            p = l.search(x);
            if (p == -1)
                cout << "not found\n";
            else
                cout << "found at index " << p << "\n";
            break;
        case 4:
            cout << "enter position and new value: ";
            cin >> p >> x;
            l.update(p, x);
            break;
        case 5:
            l.display();
            break;
        case 6:
            break;
        default:
            cout << "invalid choice\n";
        }
    } while (ch != 6);

    return 0;
}
