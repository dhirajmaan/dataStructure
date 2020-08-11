/*we are given an array with integers, an empty arry, size of the array with integers,
 and a integer. We need to find all the index of the given integer lying in the array and
 store the indexes in the empty array in assending order.
 slove using recursion

 this one is easy and simple recursion approach
*/
#include<iostream>
using namespace std;
int countInedx(int *array, int size, int key, int *ansAray) {
    int ansSize=0;
    if (size==0) {
        return ansSize;
    }
    ansSize=countInedx(array, size-1, key, ansAray);
    if (array[size-1]==key) {
        ansAray[ansSize]=size-1;
        ansSize++;
        return ansSize;

    }
    else
    {
        return ansSize;
    }


}
int main() {
    int array[]={ 9, 7, 9, 3, 6, 77, 9, 9, 4, 9, 0 };
    int size=11;
    int key=9;
    int ansAray[size];
    int ansSize=countInedx(array, size, key, ansAray);

    for (int i = 0; i < ansSize; i++)
    {
        cout<<ansAray[i]<<" ";
    }


}