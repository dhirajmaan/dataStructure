#include <string>
template <typename V>
class MapNode
{
public:
    V value;
    string key;
    MapNode<V> *next;

    MapNode(string key, V value)
    {
        this->key = key;
        this->value = value;
        this->next = nullptr;
    }
    ~MapNode()
    {
        delete next;
    }
};
template <typename V>
class ourmap
{
private:
    int numBuckets;
    int count;
    MapNode<V> **bucket;
    int getBucketIndex(string key)
    {
        int hashcode = 0;
        int currentCoefficient = 1;
        for (int i = key.length(); i >= 0; i--)
        {
            hashcode = hashcode % numBuckets;
            hashcode += key[i] * currentCoefficient;
            currentCoefficient *= 37;
            currentCoefficient = currentCoefficient % numBuckets;
        }
        return hashcode % numBuckets;
    }

private:
    void rehash()
    {
        MapNode<V> **temp = bucket;
        int oldBucketSize = numBuckets;
        numBuckets *= 2;
        count = 0;
        bucket = new MapNode<V> *[numBuckets];
        for (int i = 0; i < numBuckets; i++)
        {
            bucket[i] = nullptr;
        }
        for (int i = 0; i < oldBucketSize; i++)
        {
            MapNode<V> *head = temp[i];
            while (head != nullptr)
            {
                insert(head->key, head->value);
                head = head->next;
            }
        }
        for (int i = 0; i < oldBucketSize; i++)
        {
            MapNode<V> *head = temp[i];
            delete head;
        }
        delete[] temp;
    }

public:
    ourmap()
    {
        numBuckets = 5;
        count = 0;
        bucket = new MapNode<V> *[numBuckets];
        for (int i = 0; i < numBuckets; i++)
        {
            bucket[i] = nullptr;
        }
    }
    ~ourmap()
    {
        for (int i = 0; i < numBuckets; i++)
        {
            delete bucket[i];
        }
        delete[] bucket;
    }
    void insert(string key, V value)
    {
        int bucketIndex = getBucketIndex(key);
        MapNode<V> *head = bucket[bucketIndex];
        while (head != nullptr)
        {
            if (head->key == key)
            {
                head->value = value;
                return;
            }
            head = head->next;
        }
        MapNode<V> *newNode = new MapNode<V>(key, value);
        newNode->next = head;
        bucket[bucketIndex] = newNode;
        count++;
        double loadFactor = (1.0 * count) / numBuckets;
        if (loadFactor > 0.7)
        {
            rehash();
        }
        return;
    }
    int size()
    {
        return count;
    }
    V getValue(string key)
    {
        int bucketIndex = getBucketIndex(key);
        MapNode<V> *head = bucket[bucketIndex];
        while (head != NULL)
        {
            if (head->key == key)
            {
                return head->value;
            }
            head = head->next;
        }
        return 0;
    }
    V remove(string key)
    {
        int bucketIndex = getBucketIndex(key);
        MapNode<V> *head = bucket[bucketIndex];
        MapNode<V> *prev = nullptr;
        while (head != nullptr)
        {
            if (head->key == key)
            { //this is the first node of linklist because prev is NULL
                if (prev == NULL)
                {
                    bucket[bucketIndex] = head->next;
                }
                else
                {
                    prev->next = head->next;
                }
                //save the value because we need to delete the node;
                V value = head->value;
                //we first disconnected the node from the linklist, if we do not do this
                //then our whole linklist will be deleated as we have a recursive destructor
                count--;
                head->next = nullptr;
                delete head;
                return value;
            }

            prev = head;
            head = head->next;
        }
        return 0;
    }
    double getLoadFactor()
    {
        return (1.0 * count) / numBuckets;
    }
};
