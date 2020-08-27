/*given an integer N, count the no of zeros present in the given integer using recursion*/
#include <iostream>
using namespace std;
int countZero(int n)
{

    if (n <= 9) //if n is a single digit no
    {
        if (n == 0)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    int ans = countZero(n / 10);
    if (n % 10 == 0)
    {
        ans++;

        return ans;
    }
    else
    {
        return ans;
    }
}
int main()
{
    int n;
    cin >> n;
    cout << countZero(n);
}