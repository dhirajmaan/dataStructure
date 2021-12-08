template <typename T>
class QueueArray
{
    T *arr;
    int nextIndex;
    int frontIndex;
    int size;
    int capacity;

public:
    QueueArray()
    {
        arr = new int[4];
        nextIndex = 0;
        frontIndex = -1;
        size = 0;
        // this->capacity = capacity;
    }
    int getSize()
    {
        return size;
    }
    bool isEmpty()
    {
        return size == 0;
    }
    void enqueue(T data)
    { //check if the queue is full or not
        if (size == capacity)
        {
            T *newArr = new T[2 * capacity];
            int j = 0;
            for (int i = frontIndex; i < capacity; i++)
            {
                newArr[i] = arr[i];
                j++;
            }
            for (int i = 0; i < frontIndex; i++)
            {
                newArr[j] = arr[i];
                j++;
            }
            delete[] arr;
            arr = newArr;
            frontIndex = 0;
            nextIndex = capacity;
            capacity *= 2;
            return;
        }
        //when we have our first element inserted st frontIndex to 0
        if (nextIndex == 0)
        {
            frontIndex = 0;
        }
        arr[nextIndex] = data;
        //next index is calculated like this because we want to use empty space from front
        nextIndex = (nextIndex + 1) % capacity;
        size++;
    }
    T front()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return 0;
        }
        return arr[frontIndex];
    }

    T dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return 0;
        }
        T temp = arr[frontIndex];
        frontIndex = (frontIndex + 1) % 10;
        size--;
        //at last if our queue is empty then reset the nextIndex and FrontIndex
        if (isEmpty())
        {
            frontIndex = -1;
            nextIndex = 0;
        }
        return temp;
    }
};