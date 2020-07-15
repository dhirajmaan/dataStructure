#include <iostream>
using namespace std;
void printNumber(int n)
{

    if (n == 0)
    {
        return;
    }
    printNumber(n - 1);
    cout << n << endl;
}
int main()
{
    cout << "Enter the number up to which you want to print" << endl;
    int n;
    cin >> n;
    printNumber(n);
}