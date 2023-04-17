//given a no. what are the diff ways in which we can get it through a dice
//eg. if its 3 then the ways are:111, 12, 21, 3;

#include <bits/stdc++.h>
using namespace std;
int dice[]={1,2,3,4,5,6};

void allComb(vector<int>temp, int n, vector<vector<int> >&ans )
{
    int sum=accumulate(temp.begin(), temp.end(), 0);
    if (sum==n)
    {
        ans.push_back(temp);
        return;
    }
    
    for (int i = 0; i<n && i<6; i++)
    {
        if(sum+dice[i]<=n)
        temp.push_back(dice[i]);
        else continue;

        allComb(temp,n,ans);
        temp.pop_back();
    }
    
}
int main()
{
    int n=7;
    vector<int>temp;
    vector<vector<int> >ans;
    allComb(temp,n,ans);

    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout<<ans[i][j];
        }
        cout<<endl;
    }
    
    return 0;
}