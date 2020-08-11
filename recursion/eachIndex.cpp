/*we are given an array with integers, an empty arry, size of the array with integers,
 and a integer. We need to find all the index of the given integer lying in the array and
 store the indexes in the empty array in assending order.
 slove using recursion
*/

#include<iostream>
using namespace std;
int countIndex(int *array, int size, int key, int* ansArr) {
    int ansSize=0;
    if (size==0) {
        return ansSize;
    }
    ansSize=countIndex(array+1, size-1, key, ansArr);
    for (int i = 0; i < ansSize; i++)
    {
        ansArr[i]++;
    }
    if (array[0]==key) {
        for (int i = size-1; i >=0; i--)
        {
            ansArr[i+1]=ansArr[i];
        }
        ansArr[0]=0;
        ansSize++;
        return ansSize;

    }
    else
    {
        return ansSize;
    }



}
int main()
{
    int array[]={ 5, 6, 5, 6, 7, 5 };
    int size=6;
    int ansArr[6];
    int key=5;
    int ansSize= countIndex(array, size, key, ansArr);
    for (int i = 0; i < ansSize; i++)
    {
        cout<<ansArr[i]<<" ";
    }



}