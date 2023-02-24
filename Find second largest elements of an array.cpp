/*
    Below solution is running loop to all the elements of array.
    Alternatively, we can sort the array and simply return arr[len-2] as 2nd largest elements if it is not said "unsorted" array in problem description
*/

#include<iostream>

using namespace std;

int findSecondLargest(int arr[], int len)
{
    int largest = arr[0];
    int secondLargest = arr[0];

    for(int i=0;i<len;i++)
    {
        if (arr[i]>largest)
        {
            secondLargest = largest;
            largest = arr[i];
        }
        else if (arr[i]>secondLargest && arr[i] != largest)
        {
            secondLargest = arr[i];
        }
    }

    return secondLargest;
}

int main()
{
    int arr[] = {10, 2, 45, 8, 24};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout<<findSecondLargest(arr, n)<<endl;;

    return 0;
}
