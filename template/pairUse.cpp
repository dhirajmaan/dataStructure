#include <iostream>
#include "pair.cpp"
using namespace std;
int main()
{
    Pair<int, int> p;
    p.setX(12);
    p.setY(13);
    cout << p.getX() << " " << p.getY() << endl;

    Pair<float, float> p1;
    p1.setX(12.66);
    p1.setY(13.56);
    cout << p1.getX() << " " << p1.getY() << endl;

    Pair<char, int> p3;
    p3.setX('a');
    p3.setY(67);
    cout << p3.getX() << " " << p3.getY() << endl;

    //we can make a triplet using the same pair class
    //triplet->that contain three variable

    Pair<Pair<char, char>, int> p7;
    p7.setY(12);
    Pair<char, char> p6;
    p6.setX('a');
    p6.setY('b');
    p7.setX(p6);
    cout << p7.getX().getX() << " " << p7.getX().getY() << " " << p7.getY() << endl;

    return 0;
}