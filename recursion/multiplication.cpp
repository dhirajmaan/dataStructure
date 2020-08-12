/*given two integer m and n*. calculate and return their multiplication using rcursion
you can only use subtraction and addition for your calculation no other operaator 
are allowed.
*/
#include <iostream>
using namespace std;
int multiply(int m, int n)
{
    if (n == 0)
    {
        return 0;
    }
    int ans = multiply(m, n - 1);
    return ans + m;
}

int main()
{
    int m, n;
    cin >> m >> n;
    cout << multiply(m, n);
}
