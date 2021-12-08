template <typename T>
class BinarytreeNode
{
public:
    T data;
    BinarytreeNode<T> *left;
    BinarytreeNode<T> *right;

    BinarytreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
    ~BinarytreeNode()
    {
        delete left;
        delete right;
    }
};
