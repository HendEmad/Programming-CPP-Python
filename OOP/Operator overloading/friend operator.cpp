#include<bits/stdc++.h>
using namespace std;

class binary
{
    int x, y;
public:
    binary(int a = 0, int b = 0)
    {
        x = a;
        y = b;
    }

    binary operator+ (binary c2)
    {
        binary c3;
        c3.x = x + c2.x;
        c3.y = y + c2.y;
        return c3;
    }

    void print()
    {
        cout << x << ", " << y << endl;
    }

//    c3 = c1 + 10    =====>   c3 = c1.operator+(int);
    binary operator+(int n)
    {
        binary b;
        b.x = x + n;
        b.y = y + n;
        return b;
    }

    friend binary operator+(int, binary);
};

//c3 = 10 + c1    ====>    c3 = operator+(10, c1)    ====>    c3 = operator+(int, binary);
binary operator+(int n, binary b1)
{
    binary b2;
    b2.x = n + b1.x;
    b2.y = n + b1.y;
    return b2;
}

int main()
{
    binary c1(3, 1), c2(1, 2), c3;
    c3 = c1 + c2;  // c3 = c1.operator+(c2);
    c3.print();  // 4, 3
    c3 = c1 + 10;
    c3.print();  // 13, 11
    c3 = 10 + c1;
    c3.print();  // 13, 11
}
