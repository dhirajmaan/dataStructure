#include <iostream>
using namespace std;
int power(int x, int n)
{
    if (n == 0)
    {
        return 1;
    }
    int smallOutput = power(x, n - 1);
    return x * smallOutput;
}

int main()
{
    cout << "Enter x and n" << endl;
    int x, n;
    cin >> x >> n;
    int output = power(x, n);
    cout << output << endl;
}