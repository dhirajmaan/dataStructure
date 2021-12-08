#include <iostream>
using namespace std;
#include "stackUsingArray.cpp"

int main()
{
     StackUsingArray<char> s;
     s.push(101);
     s.push(102);
     s.push(103);
     s.push(100);
     s.push(105);
     s.push(108);
     s.push(110);
     s.push(109);
     s.push(20);
     s.push(12);
     s.push(40);
     s.push(50);
     s.push(60);
     s.push(70);
     cout << s.isEmpty() << endl;
     cout << s.pop() << endl;
     cout << s.pop() << endl;
     cout << s.pop() << endl;
     cout << s.isEmpty() << endl;
     cout << s.top() << endl;
     s.pop();
     s.pop();
     s.push(5);
     cout << s.top() << endl;

     return 0;
}