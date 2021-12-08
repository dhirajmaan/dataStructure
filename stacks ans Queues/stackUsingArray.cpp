#include <climits>
template<typename T>
class StackUsingArray
{
    T *stack;
    int next;
    int capacity = 4;

public:
    StackUsingArray()
    {
        stack = new T[capacity];
        next = 0;
        // capacity = sizeOfStack;
    }

    bool isEmpty()
    {
        return capacity == 0;
    }
    int size()
    {
        return next;
    }
    void push(T data)
    {
        if (next == capacity)
        {
            T *newStac = new T[2 * capacity];
            for (int i = 0; i < capacity; i++)
            {
                newStac[i] = stack[i];
            }
            delete[] stack;
            capacity *= 2;
            stack = newStac;
        }
        stack[next] = data;
        next++;
        return;
    }
    T pop()
    {
        if (next == 0)
        {
            cout << "stack is empty  ";
            return 0;
        }
        next--;
        return next;
    }
    T top()
    {
        if (next == 0)
        {
            cout << " stack is empty" << endl;
            return 0;
        }
        return stack[next - 1];
    }
};