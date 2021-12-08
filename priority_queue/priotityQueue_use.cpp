#include <iostream>
using namespace std;
#include "priorityQueue_min.h"
// #include "PriorityQueue_max.h"

int main()
{
    PriorityQueue p;
    p.insert(10);
    p.insert(40);
    p.insert(30);
    p.insert(37);
    p.insert(48);
    p.insert(49);
    p.insert(50);
    p.insert(38);
    // cout << "size " << p.getSize() << endl;
    // p.printVector();
    while (!p.isEmpty())
    {
        cout << p.remove() << " " << endl;
        // p.printVector();
        // cout << endl;
    }

    // for (int i = 0; i < 3; i++)
    // {
    //     cout << p.remove() << " " << endl;
    //     p.printVector();
    //     cout << endl;
    // }

    return 0;
}