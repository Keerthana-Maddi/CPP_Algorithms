// MERGE SORT
// Time Complexity: O(nlogn)
// Space Complexity: O(n)

#include <bits/stdc++.h>
using namespace std;

//to merge two sorted arrays
void merge_(vector<int> &v, int start, int mid, int end_)
{
    vector<int> temp(end_ - start + 1);
    int j = start, k = mid + 1, m = 0;
    while (j <= mid && k <= end_)
    {
        if (v[j] <= v[k])
        {
            temp[m] = v[j];
            j++;
            m++;
        }
        else
        {
            temp[m] = v[k];
            k++;
            m++;
        }
    }
    while (j <= mid)
    {
        temp[m] = v[j];
        j++;
        m++;
    }
    while (k <= end_)
    {
        temp[m] = v[k];
        k++;
        m++;
    }
    for (int i = start; i <= end_; i++)
    {
        v[i] = temp[i - start];
    }
}

//function to perform merge sort
void mergeSort(vector<int> &v, int start, int end_)
{
    int mid = start + (end_ - start) / 2;
    if (start < end_)
    {
        mergeSort(v, start, mid);
        mergeSort(v, mid + 1, end_);
        merge_(v, start, mid, end_);
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    cout << "Array before sorting:\n";
    for (int i = 0; i < n; i++)
        cout << v[i] << " ";
    mergeSort(v, 0, n - 1);
    cout << "\nArray after sorting:\n";
    for (int i = 0; i < n; i++)
        cout << v[i] << " ";
    return 0;
}
