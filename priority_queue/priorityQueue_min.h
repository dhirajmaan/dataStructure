#include <vector>
class PriorityQueue
{
    std::vector<int> pq;

public:
    PriorityQueue()
    {
    }
    int getSize()
    {
        return pq.size();
    }
    bool isEmpty()
    {
        return getSize() == 0;
    }
    int getMin()
    {
        if (!isEmpty())
        {
            return pq[0];
        }
        else
        {
            return -1;
        }
    }
    void insert(int value)
    {
        pq.push_back(value);

        int childIndex = pq.size() - 1;
        while (childIndex > 0)
        {
            int parentIndex = (childIndex - 1) / 2;
            if (pq[parentIndex] > pq[childIndex])
            {
                //swap
                int temp = pq[parentIndex];
                pq[parentIndex] = pq[childIndex];
                pq[childIndex] = temp;
            }
            else
            {
                break;
            }
            childIndex = parentIndex;
        }
    }
    int remove()
    {
        if (isEmpty())
        {
            return -1;
        }
        int ans = pq[0];
        pq[0] = pq[pq.size() - 1];
        pq.pop_back();
        //downHeapify 
        int parentIndex = 0;
        int leftChildIndex = (2 * parentIndex) + 1;
        int rightChildIndex = (2 * parentIndex) + 2;
        while (leftChildIndex < pq.size() - 1)
        {
            int minIndex = parentIndex;
            if (pq[minIndex] > pq[leftChildIndex])
            {
                minIndex = leftChildIndex;
            }
            if (pq[minIndex] > pq[rightChildIndex] and rightChildIndex < pq.size() - 1)
            {
                minIndex = rightChildIndex;
            }
            if (parentIndex == minIndex)
            {
                break;
            }
            //swap parent with minIndex
            int temp = pq[parentIndex];
            pq[parentIndex] = pq[minIndex];
            pq[minIndex] = temp;
            //now parent index should change to minIndex
            parentIndex = minIndex;
            leftChildIndex = (2 * parentIndex) + 1;
            rightChildIndex = (2 * parentIndex) + 2;
        }

        return ans;
    }
};