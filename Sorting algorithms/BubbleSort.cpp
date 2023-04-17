//the largest element comes at the end after each iteration, like a bubble, the lightest comes at top
//so the each time since the last element comes to its final position, so we only have to iterate till n-counter
#include<bits/stdc++.h>
using namespace std;
int main()
{
    cout<<endl;
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    int counter = 1;
    while (counter < n){
        for (int i = 0; i < n-counter; i++){
            if (a[i]>a[i+1])
            {
                int temp = a[i];
                a[i] = a[i+1];
                a[i+1]=temp;
            }
        }
        counter++;
    }
    for (int i = 0; i < n; i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    return 0;
}