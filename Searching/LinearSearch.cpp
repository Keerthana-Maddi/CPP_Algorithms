// LINEAR SEARCH
// Time Complexity: O(n)

#include <bits/stdc++.h>
using namespace std;

// function to perform linear search
int linearSearch(int num, vector<int> &v)
{
    int n = v.size();
    for (int i = 0; i < n; i++)
    {
        if (v[i] == num)
            return i;
    }
    return -1;
}

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    int num;
    cout << "Enter the number to be searched: ";
    cin >> num;
    int index = linearSearch(num, v);
    if (index == -1)
        cout << num << " not found" << endl;
    else
        cout << num << " is at index " << index << endl;
    return 0;
}
