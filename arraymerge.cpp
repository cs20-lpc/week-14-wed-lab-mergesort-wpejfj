#include <iostream>
using namespace std;

void merge(int arr[], int left, int mid, int right)
{
    // TODO:
    // Create temporary arrays
    // Copy data
    // Merge sorted halves back into arr
  int n1 = mid - left + 1;
  int n2 = right - mid;

  int *arr1 = new int[n1];
  int *arr2 = new int[n2];

  for (int i = 0; i < n1; ++i) arr1[i] = arr[left + i];
  for (int j = 0; j < n2; ++j) arr2[j] = arr[mid + 1 + j];

  int i = 0, j = 0, k = left;
  while (i < n1 && j < n2) {
    if (arr1[i] <= arr2[j]) {
      arr[k++] = arr1[i++];
    }
    else {
      arr[k++] = arr2[j++];
    }
  }

  while (i < n1) arr[k++] = arr1[i++];
  while (j < n2) arr[k++] = arr2[j++];

  delete[] arr1;
  delete[] arr2;

}

void mergeSort(int arr[], int left, int right)
{
    if (left < right)
    {
        // TODO:
        // Find middle
        // Recursively sort left half
        // Recursively sort right half
        // Merge both halves
      int mid = left + (right - left) / 2;
      mergeSort(arr, left, mid);
      mergeSort(arr, mid+1, right);
      merge(arr, left, mid, right);

    }
}

void display(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    int arr[10] = {38, 27, 43, 3, 9, 82, 10, 5, 61, 14};
    int n = 10;

    cout << "Before Sorting: ";
    display(arr, n);

    mergeSort(arr, 0, n - 1);

    cout << "After Sorting: ";
    display(arr, n);

    return 0;
}
