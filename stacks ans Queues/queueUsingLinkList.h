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
class QueueUsingLinkList
{
private:
    Node<T> *head;
    Node<T> *tail;
    int size;

public:
    QueueUsingLinkList()
    {
        head = NULL;
        tail = NULL;
        size = 0;
    }
    void enqueue(T data)
    {
        Node<T> *newNode = new Node<T>(data);
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
            size++;
            return;
        }
        tail->next = newNode;
        tail = newNode;
        size++;
        return;
    }
    int getSize()
    {
        return size;
    }
    bool isEmpty()
    {
        return size == 0;
    }
    T dequeue()
    {
        if (size == 0)
        {
            cout << "queue is empty" << endl;
        }
        Node<T> *temp = head;
        head = head->next;
        T tempData = temp->data;
        delete temp;
        size--;
        return tempData;
    }
    T front()
    {
        if (isEmpty())
        {
            cout << "Queue Empty!" << endl;
            return 0;
        }
        return head->data;
    }
};
