#include <iostream>
using namespace std;
void swap(int *firstAdd, int *secAdd)
{
     int temp = *firstAdd;
     *firstAdd = *secAdd;
     *secAdd = temp;
}

// int partition(int *arr, int si, int ei)
// {
//      int pivotElement = arr[si];
//      int count = 0;
//      for (int i = 0; i < ei; i++)
//      {
//           if (pivotElement > arr[i])
//           {
//                count++;
//           }
//      }
//      int pivotIndex = si + count;

//      //swap the pivot element with the element
//      //which is in the correct palce of pivot
//      //element
//      // int temp;
//      // temp=pivot;
//      // arr[0]=arr[correctPlace];
//      // arr[correctPlace]=pivot;

//      swap(&arr[si], &arr[pivotIndex]);

//      int i = si;
//      int j = pivotIndex + 1;
//      while (i < pivotIndex && j <= ei)
//      {
//           if (arr[i] < pivotElement)
//           {
//                i++;
//           }
//           else
//           {
//                swap(&arr[i], &arr[j]);
//                i++;
//                j++;
//           }
//      }

//      return pivotIndex;
// }

/*

int partition(int A[], int start, int end)
{
     int i = start + 1;
     int piv = A[start]; //make the first element as pivot element.
     for (int j = start + 1; j <= end; j++)
     {
          //rearrange the array by putting elements which are less than pivot
          //on one side and which are greater that on other.

          if (A[j] < piv)
          {
               swap(&A[i], &A[j]);
               i += 1;
          }
     }
     swap(&A[start], &A[i - 1]); //put the pivot element in its proper place.
     return i - 1;               //return the position of the pivot
}

*/
int partition(int *arr, int si, int ei)
{
     int pivot = arr[si];
     int i = si + 1;

     for (int j = si + 1; j <= ei; j++)
     {
          if (arr[j] < pivot)
          {
               swap(arr[i], arr[j]);
               i++;
          }
     }
     swap(arr[si], arr[i - 1]);
     return i - 1;
}

void quickSort(int *arr, int si, int ei)
{
     //base case
     if (si >= ei)
     {
          return;
     }
     int c = partition(arr, si, ei);
     quickSort(arr, si, c - 1);
     quickSort(arr, c + 1, ei);
}
int main()
{
     int arr[] = {4, 5, 1, 3, 8, 9, 10, 45, 67, 12};
     int size = sizeof(arr) / sizeof(int);
     quickSort(arr, 0, size - 1);
     for (int i = 0; i < size; i++)
     {
          cout << arr[i] << " ";
     }

     return 0;
}