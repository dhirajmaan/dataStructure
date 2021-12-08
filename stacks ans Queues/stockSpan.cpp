#include <iostream>
#include <stack>
using namespace std;
void stockSpan(int *price, int n, int *span)
{
    //span for the first price will be always 1
    span[0] = 1;
    for (int i = 1; i < n; i++)
    { //fixed the first price

        //span for each price is never 0
        span[i] = 1;
        for (int j = i - 1; j >= 0; j--)
        {
            //go to every element before i
            if (price[i] >= price[j])
            {
                span[i]++;
            }
        }
    }
}
void stockSpan_better(int *price, int n, int *span)
{
    stack<int> s;
    span[0] = 1;
    s.push(0);
    for (int i = 1; i < n; i++)
    {
        // Pop elements from stack while stack is not
        // empty and top of stack is smaller than
        // price[i]
        while (!s.empty() and price[s.top()] <= price[i])
        {
            s.pop();
        }

        // If stack becomes empty, then price[i] is
        // greater than all elements on left of it,
        // i.e., price[0], price[1], ..price[i-1].  Else
        // price[i] is greater than elements after
        // top of stack
        if (s.empty())
        {
            span[i] = i + 1;
        }
        else
        {
            span[i] = i - s.top();
        }
        s.push(i);
    }
}
int main()
{
    int price[] = {100, 80, 60, 70, 60, 75, 85};
    int n = sizeof(price) / sizeof(price[0]);
    int *span = new int[n];
    stockSpan_better(price, n, span);
    for (int i = 0; i < n; i++)
    {
        cout << span[i] << " ";
    }

    return 0;
}