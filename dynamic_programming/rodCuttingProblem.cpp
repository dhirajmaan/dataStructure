#include <iostream>
using namespace std;
int cutRod(int n, int price[])
{
    if (n <= 0)
    {
        return 0;
    }
    int ans = INT_MIN;
    for (int i = 1; i <= n; i++)
    {
        ans = max(ans, price[i] + cutRod(n - i, price));
    }
    return ans;
}
int helper_cutRod_memoization(int n, int *price, int *memory)
{
    if (n <= 0)
    {
        return 0;
    }
    if (memory[n] != -1)
    {
        return memory[n];
    }
    int ans = INT_MIN;
    for (int i = 1; i <= n; i++)
    {
        ans = max(ans, price[i] + cutRod(n - i, price));
    }
    memory[n] = ans;
    return memory[n];
}
int cutRod_memoization(int n, int price[])
{
    int *memory = new int[n + 1];
    for (int i = 0; i <= n; i++)
    {
        memory[i] = -1;
    }
    return helper_cutRod_memoization(n, price, memory);
}
int cutRod_dp(int n, int price[])
{
    int *ansArr = new int[n + 1];
    ansArr[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        int ans = INT_MIN;
        for (int j = 1; i <= i; j++)
        {
            ans = max(ans, price[j] + ansArr[i - j]);
        }
        ansArr[i] = ans;
    }
    return ansArr[n];
}
int main()
{
    int n;
    cout << "enter the length of the rod: ";
    cin >> n;
    int *price = new int[11]{0, 1, 5, 8, 9, 10, 17, 17, 20, 24, 30};
    cout << cutRod(n, price) << endl;
    cout << cutRod_memoization(n, price) << endl;
    cout << cutRod_dp(n, price) << endl;
    return 0;
}