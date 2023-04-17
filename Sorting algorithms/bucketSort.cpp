// 1) Create n empty buckets using vector of array
// 2) Insert (every element) arr[i] into bucket[n*array[i]];
// 3) Sort elements within each bucket.
// 4) Concatenate all sorted buckets to get the final sorted array.

#include<bits/stdc++.h>
using namespace std;
void printArray(float *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
    
}
void bucketSort(float a[], int n)
{
    //creating n buckets: 
    vector<float>b[n];

    //inserting elements into their respective bucket
    for (int i = 0; i < n; i++)
    {
        int index=n*a[i];
        b[index].push_back(a[i]);
    }
     
    //Sorting elements within each bucket
    for (int i = 0; i < n; i++)
    {
        //it uses insertion sort method
        sort(b[i].begin(),b[i].end());
    }
    
    //Concatenating all sorted buckets
    int index=0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < b[i].size(); j++)
        {
            a[index++]=b[i][j];
        }
    }
}
int main()
{
    float a[]={0.42,0.32,0.23,0.52,0.25,0.47,0.51};
    int n=sizeof(a)/sizeof(a[0]);
    cout<<"\nOriginal array: ";
    printArray(a,n);

    cout<<"\nSorted array: ";
    bucketSort(a,n);
    printArray(a,n);
    cout<<endl;
    return 0;
}