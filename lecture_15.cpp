#include <iostream>
using namespace std;
// In this question, we where allocating the book to the students using the Binary Search:
// Creating an function which can check the studentCount:
bool isPossible(int arr[], int mid, int m, int n)
{
    int studentCount = 1;
    int bookSum = 0;

    for (int i = 0; i < n; i++)
    {
        if (bookSum + arr[i] <= mid)
        {
            bookSum += arr[i];
        }
        else
        {
            studentCount++;
            bookSum = arr[i];
        }
        if (studentCount > m || arr[i] > mid)
        {
            return false;
        }
    }
    return true;
}
// Checking whether the solution is possible or not:
int checkPossible(int arr[], int size)
{
    int start = 0;
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum = sum + arr[i];
    }
    int end = sum;
    int ans = -1;
    int m = 2; // No of students

    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (isPossible(arr, mid, m, size))
        {
            ans = mid;
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return ans;
}

int main()
{
    // Allocating the books to the students:
    int size1;
    cout << "Enter the size of an array: ";
    cin >> size1;
    // Creating an array:
    int arr1[100];
    for (int i = 0; i < size1; i++)
    {
        cout << "Value of index " << i << " is: ";
        cin >> arr1[i];
    }
    // Calling function:
    int ans = checkPossible(arr1, size1);
    cout << "The minimum value is: " << ans << endl;
}
