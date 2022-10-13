// QUICK SORT
// Time Complexity: 
//         worst case --> O(n^2)
//         average case --> O(nlogn) 
// Space Complexity: O(1)

#include<bits/stdc++.h>
using namespace std;

void swap_(vector<int> &v,int i,int j)
{
    int temp=v[i];
    v[i]=v[j];
    v[j]=temp;
}

//to partition an array with respect to the choosen pivot
int partition_(vector<int> &v, int start, int end_)
{
    int pivot=v[start];
    int m=start,k=start;
    for(int i=k;i<=end_;i++)
    {
        if(v[k]>=pivot) k++;
        else
        {
            m++;
            swap_(v,m,i);
            k++;
        }
    }
    swap_(v,start,m);
    return m;
}

//function to perform quick sort
void quickSort(vector<int> &v, int start, int end_)
{
    if(start<end_)
    {
       int q = partition_(v,start,end_);
       quickSort(v,start,q-1);
       quickSort(v,q+1,end_);
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
    quickSort(v,0,n-1);
    cout << "\nArray after sorting:\n";
    for (int i = 0; i < n; i++)
        cout << v[i] << " ";
    return 0;
}
