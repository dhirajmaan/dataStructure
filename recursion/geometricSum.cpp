/*given integer k find the geomeirc sum 
1+ 1/2+ 1/2^2 + 1/2^3 +1/2^4...............1/2^k
*/

#include <iostream>
#include <math.h>
using namespace std;
double gSum(int k)
{
    if (k == 0)
    {
        return 1;
    }

    return (1 / pow(2, k)) + gSum(k - 1);
}
int main()
{
    int k;
    cin >> k;
    cout << gSum(k);
}