#include <iostream>
using namespace std;

void fun(int *num)
{
    *num += 1;
    cout << "add inside fun " << num << endl;
    cout << "value inside fun " << *num << endl;
}
int main()
{
    int *val = new int;
    *val = 0;
    // cout << "value in main" << val << endl;
    cout << "value in main " << *val << endl;
    cout << "address in main " << val << endl;
    fun(val);

    cout << "value after function call " << *val << endl;

    return 0;
}