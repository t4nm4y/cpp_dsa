// given an array, print the sum of all the possible subset;
#include<iostream>
#include<vector>
using namespace std;
void subsetSum(vector<int>subset, vector<int>orig)
{
    if(orig.empty())
    {
        int total=0;
        while (!subset.empty())
        {
            total+=subset.back();
            subset.pop_back();
        }
        cout<<total<<" ";
        return;
    }
    //excluding the last val
    int temp=orig.back();
    orig.pop_back();
    subsetSum(subset,orig);

    //including the last val
    subset.push_back(temp);
    subsetSum(subset,orig);
}
int main()
{
    vector<int>orig;
    orig.push_back(1);
    orig.push_back(2);
    vector<int> subset ;
    subsetSum(subset,orig);
    return 0;
}