#include <iostream>
using namespace std;
#include <queue>
#include "BinarySearchTree.h"
int main()
{
    Bst t;
    t.insertData(10);
    t.insertData(12);
    t.insertData(15);
    t.insertData(20);
    t.insertData(9);
    t.printTree();
    t.deleteData(15);
    t.printTree();
    cout << " deleted root" << endl;
    t.deleteData(10);
    t.printTree();
    cout << endl
         << endl;
    cout<<t.hasData(9)<<endl;
    cout<<t.hasData(99)<<endl;


    return 0;
}