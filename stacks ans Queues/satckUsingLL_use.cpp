#include <iostream>
#include<stack>
using namespace std;
#include "stackUsingLinkList.cpp"

int main()
{

    StackUsingLL<string> s;
    cout << s.isEmpty() << endl;

    s.push("apple");
    s.push("ball");
    s.push("cat");
    s.push("dog");
    s.push("elephant");

    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;

    cout << s.getSize() << endl;


    return 0;
}