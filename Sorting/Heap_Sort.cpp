//HEAP SORT
//Time Complexity: O(nlogn)
//Space Complexity: O(1)

#include<bits/stdc++.h>
using namespace std;

//to heapify a subtree rooted with node at index 'i' 
void heapify(vector<int> &v, int i, int n)
{
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int largest = i;
    if (left < n && v[left] > v[largest])
        largest = left;
    if (right < n && v[right] > v[largest])
        largest = right;
    if (largest != i)
    {
        swap(v[i], v[largest]);
        heapify(v, largest, n);
    }
}

//function to perform heap sort
void heapSort(vector<int> &v)
{
    int n = v.size();
    // building a max heap from given vector elements
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(v, i, n);
    }

    // Picking the elements in sorted order
    for (int i = n - 1; i > 0; i--)
    {
        swap(v[0], v[i]);
        heapify(v, 0, i);
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
    heapSort(v);
    cout << "\nArray after sorting:\n";
    for (int i = 0; i < n; i++)
        cout << v[i] << " ";
    return 0;
}