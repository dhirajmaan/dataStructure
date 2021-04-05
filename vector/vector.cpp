#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> v;
    //use [] only for updating and and accessing value
    /* v.push_back(10);
    v.push_back(20);
    cout << v.capacity() << endl;
    cout << v.size() << endl;
    */
    for (int i = 0; i <= 100; i++)
    {
        cout << "capacity " << v.capacity() << endl;
        v.push_back(i);
        cout << "size " << v.size() << endl;
    }

    return 0;
}