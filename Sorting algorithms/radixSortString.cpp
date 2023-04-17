//given the length of each string in the array is 3
//sort the given array (sorting the an array of string means that u have to do it acc to the dictionary format(by default))

#include<bits/stdc++.h>
using namespace std;
void printArray(string a[],int n)
{
    for (int i = 0; i < n; i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}
void radixSort(string *arr, int n, int pos,int sl)
{ 
    if(pos>sl)
    return;
    vector<string>b[26];
    for(int i=0; i<n; i++)
    {
        int index=(arr[i][sl-pos])-'a';
        
        b[index].push_back(arr[i]);
    }
    int k=0;
    for (int i = 0; i < 26; i++)
    {
        for (auto p = b[i].begin(); p != b[i].end(); p++)
        {
            arr[k++]=*p;
        }
    }
    radixSort(arr,n,++pos, sl);
}

int main()
{
    string arr[]={"abc","def","fgh","hjk","ihl","wqb","asz","xtn"};
    int n= sizeof(arr)/sizeof(arr[0]);
    int sl;
    cout<<"\nEnter the length of the string in the array: ";
    cin>>sl;
    radixSort(arr,n,1,sl);
    cout<<"\nThe sorted string is: ";
    printArray(arr,n);
    return 0;
}