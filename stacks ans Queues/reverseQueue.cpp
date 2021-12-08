/*
given a queue you are required to reverse a queue without using any other datastructure
 */
#include <iostream>
#include <queue>
using namespace std;
void reverse(queue<int> *q)//while passing the queue either use refrence or pointer 
{
    /*
        we will do it using recursion 
        #base case 
        if the queue is empty return

        #so first we will call front function and save it in a temp variable 
        # then we will call recursion on the queue and assume that the queue is reversed 
        
        #small calculation
        we will push the the element that we have back to the queue
    */

   
    if (q->empty())
    {
        return;
    }
    int temp = q->front();
    q->pop();
    reverse(q);
    q->push(temp);
}
int main()
{
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    reverse(&q);
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }

    return 0;
}
