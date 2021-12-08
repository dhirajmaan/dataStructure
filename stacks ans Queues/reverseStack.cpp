/*
reverse a given stack with the help of the empty stack



*/

/*
 this  is reversing a stack using recursion without using the extra 
 space or any other data structure

 */
#include <iostream>
#include <stack>
using namespace std;
void reverseUsingAnotherStack(stack<int> &s1, stack<int> &s2)
{
    if (s1.size() == 1)
    {
        return;
    }
    int top = s1.top();
    s1.pop();
    reverseUsingAnotherStack(s1, s2);
    //transfer all element to s2
    while (!s1.empty())
    {
        int temp = s1.top();
        s1.pop();
        s2.push(temp);
    }
    s1.push(top);
    while (!s2.empty())
    {
        int temp = s2.top();
        s2.pop();
        s1.push(temp);
    }
}
void insertAtLast(stack<int> &s, int element)
{
    if (s.empty())
    {
        s.push(element);
        return;
    }
    int temp = s.top();
    s.pop();
    insertAtLast(s, element);
    s.push(temp);
}
void reverseWithoutAnyOtherDataStructure(stack<int> &ss)
{
    if (ss.size() == 1)
    {
        return;
    }
    int top = ss.top();
    ss.pop();
    reverseWithoutAnyOtherDataStructure(ss);
    insertAtLast(ss, top);
}

int main()
{
    stack<int> s1;
    stack<int> s2;
    s1.push(100);
    s1.push(200);
    s1.push(300);
    s1.push(400);
    s1.push(500);
    // insertAtLast(s1, 99);
    // reverse(s1);

    reverseUsingAnotherStack(s1, s2);
    while (!s1.empty())
    {
        cout << s1.top() << " ";
        s1.pop();
    }
}