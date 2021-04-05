#include <iostream>
//using namespace std;
//#include <math.h>
int findlen(int n)
{
    if (n == 0)
    {
        return 0;
    }
    return 1 + findlen(n / 10);
}
int convert(int n)
{
    int len = findlen(n);
    int a = 9;
    for (int i = 1; i < len; i++)
    {
        a = (a * 10) + 9;
    }
    return a - n;
}
int main()
{
    int n;
    std::cin >> n;
    std::cout << convert(n) << std::endl;
    return 0;
}