#include <iostream>
using namespace std;
#include "ourmap.h"
int main()
{
    ourmap<int> map;
    for (int i = 0; i < 10; i++)
    {
        char c = '0' + i;
        string key = "abc";
        key = key + c;
        int value = i + 1;
        map.insert(key, value);
        cout << map.getLoadFactor() << endl;
        // cout << "key " << key << " "
        //      << "value " << value << endl;
    }
    cout << "size " << map.size() << endl;
    map.remove("abc2");
    map.remove("abc7");
    cout << "size " << map.size() << endl;

    for (int i = 0; i < 10; i++)
    {
        char c = '0' + i;
        string key = "abc";
        key = key + c;
        int value = i + 1;
        cout << key << " " << map.getValue(key) << endl;
    }
    cout << "size " << map.size() << endl;

    return 0;
}