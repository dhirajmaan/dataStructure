#include <iostream>
using namespace std;
int findWays(int n)
{
    if (n <= 0)
    {
        return 0;
    }
    if (n == 1)
    {
        return 1;
    }
    if (n == 2)
    {
        return 2;
    }
    if (n == 3)
    {
        return 4;
    }
    return (findWays(n - 1) + findWays(n - 2) + findWays(n - 3));
}
int main()
{
    int n;
    cin >> n;
    cout << findWays(n) << endl;

    return 0;
}