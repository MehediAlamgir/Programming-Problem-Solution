#include<iostream>
using namespace std;


//https://www.youtube.com/playlist?list=PL2_aWCzGMAwKedT2KfDMB9YA5DgASZb3U

void bubble_sort(int arr[], int len)
{
    for(int i=0;i<len-1;i++)
    {
        int isSwaped = false;
        for(int j=0;j<len-i-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                swap(arr[j], arr[j+1]);
                isSwaped = true;
            }
        }
        if (!isSwaped)
            break;
    }
}

void selection_sort(int arr[], int len)
{
    for(int i=0;i<len-1;i++)
    {
        int min_ind = i;
        for(int j=i+1;j<len;j++)
        {
            if(arr[j]<arr[min_ind])
            {
                min_ind = j;
            }
        }
        swap(arr[i], arr[min_ind]);
    }
}

void insertion_sort(int arr[], int len)
{
    for(int i=1;i<len;i++)
    {
        int value = arr[i];
        int index = i;

        while(index>0 && arr[index-1]>value)
        {
            arr[index] = arr[index-1];
            index = index-1;
        }
        arr[index] = value;
    }
}

int main()
{
    int arr[] = {64, 34, 25, 12, 22, 11, 90};

    int len = sizeof(arr)/sizeof(arr[0]);

    insertion_sort(arr, len);


    for(int i=0;i<len;i++)
        cout<<arr[i]<<" ";

    return 0;
}
