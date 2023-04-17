//given an amount, display the method to make it by using min no. of notes and coins
//eg: for 54-> 50 + 2+ 2 (ie. 50 rupee note+ 2*(2ruppe coin) )
#include<iostream>
using namespace std;

int main()
{
    int n=54;
    int ans=0;
    int money[10]={2000,500,200,100,50,20,10,5,2,1};
    cout<<"\ntype of notes,coins required: ";
    for (int i = 0; i < 10; i++)
    {
        ans+=n/money[i];
        if(n/money[i]!=0)
        {
            n-=(n/money[i])*money[i];
            cout<<money[i]<<" ";
        }
    }
    cout<<"\ncount: "<<ans<<endl;
    return 0;
}