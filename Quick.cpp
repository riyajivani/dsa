#include <iostream>
using namespace std;

class quicksort
{
public:

    quicksort(){}

    void sort(int arr[], int left, int right)
    {
        if (left < right)
        {
            int pivot = arr[left];
            int i = left;
            int j = right + 1;

            do
            {
                do
                {
                    i++;
                } while (pivot > arr[i]);
                do
                {
                    j--;
                } while (pivot < arr[j]);

                if (i < j)
                {
                    swap(arr, i, j);
                }

            } while (i < j);

            if (i > j)
            {
                swap(arr, left, j);
            }

            sort(arr, left, j - 1);
            sort(arr, j + 1, right);
        }
    }

    void swap(int arr[], int i, int j)
    {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    void display(int arr[])
    {
        for (int i = 0; i < 10; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    quicksort s;
    int arr[10];

    cout << "enter your 10 array element" << endl;
    for (int i = 0; i < 10; i++)
    {
        cin >> arr[i];
    }
    
    int left = 0;
    int right = 9;

    cout << "your element before sorting:" << endl;
    s.display(arr);

    s.sort(arr, left, right);

    cout << "your element after sorting:" << endl;
    s.display(arr);

    return 0;
}