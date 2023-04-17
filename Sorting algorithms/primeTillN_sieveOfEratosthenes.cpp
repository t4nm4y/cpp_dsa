#include<bits/stdc++.h>
using namespace std;
void sieveOfEratosthenes(int n){
    int arr[n]={0};
    for(int i =2; i<n; i++)
    {
        if(arr[i]==0)
        {
        for (int j = i*i; j <= n; j+=i)
            {
            arr[j]=1;
            }
        }   
    }

        for(int i =2; i<n; i++){
            if( arr[i]==0 && n%i==0){                
                cout<<i<<" ";
            }
        }
}
int main()
{
    cout<<endl;
    int n;
    cin >> n;
    cout<<"prime factors are: ";
    sieveOfEratosthenes(n);   
    cout<<endl;
    return 0;
}