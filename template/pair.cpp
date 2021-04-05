template <typename T, typename U>
class Pair
{
    T x;
    U y;

public:
    void setX(T x)
    {
        this->x = x;
    }
    void setY(U y)
    {
        this->y = y;
    }

    T getX()
    {
        return x;
    }
    U getY()
    {
        return y;
    }
};