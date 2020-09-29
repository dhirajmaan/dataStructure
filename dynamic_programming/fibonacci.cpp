#include <iostream>
using namespace std;
int fibo_helper(int n, int ans[])
{
    //base case
    if (n <= 1)
    {
        return n;
    }
    //check if the answer exist
    if (ans[n] != -1)
    {
        return ans[n];
    }
    //if we rech at this point that means the answer is not present
    //so we need to calcuate
    int a = fibo_helper(n - 1, ans);
    int b = fibo_helper(n - 2, ans);
    //save the output for future use
    ans[n] = a + b;
    //return the answer
    return ans[n];
}
int fibo(int n)
{
    int *ans = new int[n + 1];
    for (int i = 0; i < n + 1; i++)
    {
        ans[i] = -1;
    }

    return fibo_helper(n, ans);
}

int main()
{
    int n;
    cin >> n;
    cout << fibo(n) << endl;
    return 0;
}