//double hashing can be done using: (hash1(key)+i*(hash2(key))%size (when hash keys are not given)

#include<bits/stdc++.h>
using namespace std;
int elements;
map <int,int> mp;
map<int,int> :: iterator it;
void insert(int n)
{
    int key1, key2;
    for(int i=0; i<10; i++){
    key1=(n+i)%7;
    if (mp[key1]==NULL)
    {
        mp[key1]=n;
        break;
    }
    
    else
    {
        key2=(n+i)%3;
        if (mp[key2]==NULL)
        {
            mp[key2]=n;
            break;
        }
    }
    }
}
int main()
{
    int n;
    cout<<"\nEnter the amount of nos. u wanna insert: ";
    cin>>n;
    cout<<"Enter the nos.:\n";
    int val;
    for (int i = 0; i < n; i++)
    {
        cin>>val;
        insert(val);
    }
    cout<<"\nThe hash table is: \n";
    for(it=mp.begin(); it!=mp.end(); ++it)
    {
        cout<<it->first<<"|->"<<it->second<<endl;
    }
    cout<<endl;
    return 0;
}