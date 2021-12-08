template <typename T>
class Node
{
public:
    T data;
    Node<T> *next;

    Node(T data)
    {
        this->data = data;
        this->next = NULL;
    }
};
template <typename T>
class StackUsingLL
{
    Node<T> *head;
    int size;

public:
    StackUsingLL()
    {
        head = NULL;
        size = 0;
    }

    void push(T data)
    {
        Node<T> *newNode = new Node<T>(data);
        if (head == NULL)
        {
            head = newNode;
            size++;
            return;
        }
        newNode->next = head;
        head = newNode;
        size++;
        return;
    }
    T pop()
    {
        if (isEmpty())
        {
            cout << "stack is empty" << endl;
        }
        Node<T> *temp = head;
        T data = temp->data;
        head = head->next;
        delete temp;
        size--;
        return data;
    }
    T top()
    {
        if (head == NULL)
        {
            cout << "stack is empty" << endl;
        }
        return head->data;
    }
    int getSize()
    {
        return size;
    }
    bool isEmpty()
    {

        return head == NULL;
    }
};
