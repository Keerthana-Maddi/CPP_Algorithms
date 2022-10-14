// BINARY SEARCH
// Time Complexity: O(logn)
// But binary search works only if the elements are in order or sorted

#include <bits/stdc++.h>
using namespace std;

// function to perform binary search
int binarySearch(int num, vector<int> &v)
{
    int l = 0, h = v.size() - 1;
    while (l <= h)
    {
        int m = l + (h - l) / 2;
        if (v[m] == num)
            return m;
        else if (v[m] < num)
            l = m + 1;
        else
            h = m - 1;
    }
    return -1;
}

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);

    // binary search works only if the array is sorted
    cout << "Input the elements in sorted order:\n";

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    int num;
    cout << "Enter the number to be searched: ";
    cin >> num;
    int index = binarySearch(num, v);
    if (index == -1)
        cout << num << " not found" << endl;
    else
        cout << num << " is at index " << index << endl;
    return 0;
}
