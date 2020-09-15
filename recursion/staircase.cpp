/*a child is running with up a stair case with N steps and can hop either 
1 step, 2 step or 3 step at a time implement to count how many possible ways 
the child can up to the stairs you need to return the no of possible ways W
*/

/*first divide the proplem 
    let's say that we wiil work for the 1st step an recursion will work for the rest step
    for 1st step
        child can take 1 step or,
        child can take 2 step or,
        child can take 2 step

*/
#include <iostream>
using namespace std;
int staircase(int n)
{
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

    int x = staircase(n - 1);
    int y = staircase(n - 2);
    int z = staircase(n - 3);
    return x + y + z;
}

int stair(int n)
{
    if (n < 0)
    {
        return 0;
    }
    if (n == 0)
    {
        return 1;
    }
    return stair(n - 1) + stair(n - 2) + stair(n - 3);
}

int main()
{
    int n;
    cin >> n;
    cout << staircase(n);
    cout << endl;
    cout << stair(n);
    return 0;
}
