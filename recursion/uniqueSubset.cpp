/*
find all the unique subsets of an given array or vector
eg, if set={1,2,2} then all the unique(or distict) subsets are:
{1,2,2 } {1,2} {1} {2,2} {2} and {null}
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void uniqueSubsets(vector<int>orig,vector<vector<int> >&ans,vector<int>&temp,int index)
{
    ans.push_back(temp);//when its called for the first time the null is pushed bcoz it is also a subset(of size 0)
    //then we will push the subsets of size 1, then of size 2, ans so on, 
    //until the subset of size n(where n is the size of the original given array);
    for (int i = index; i < orig.size(); i++)
    {
        if(i!=index && orig[i]==orig[i-1]) continue;
        temp.push_back(orig[i]);
        //we can also write the above 2 lines as: 
        // if(i==index||(i!=index && orig[i]!=orig[i-1])) 
        // temp.push_back(orig[i]);
        // else continue;

        uniqueSubsets(orig,ans,temp,i+1); //recursive calculating the subsets of size+1 stsarting with the current index
        temp.pop_back();
    }
    

}
int main()
{
    //given the original array, it may be unsorted
    vector<int>orig;
    orig.push_back(1);
    orig.push_back(2);
    orig.push_back(2);
    orig.push_back(3);
        
    sort(orig.begin(), orig.end()); //sort the array

    //create an empty vector to store all the unique subsets 
    vector<vector<int> >ans;
    vector<int>temp;
    int index=0;
    uniqueSubsets(orig,ans,temp,index);

    for (int i = 0; i < ans.size(); i++) 
	{
		for (int j = 0; j < ans[i].size(); j++) 
		{
			cout<<ans[i][j]<<" ";
		}
		cout<<endl;
	}
    
    return 0;
}
/* working of the code:
    eg if array is 1,2,2,3
    ans wali vector m 
    pahle 1 sare store honge
    then 2 k sare store honge 
    then next wala 2 k nhi honge since its repeated
    then 3 ke sare store honge.

this is the output:

1 
1 2 
1 2 2 
1 2 2 3 
1 2 3 
1 3 
2 
2 2 
2 2 3 
2 3 
3 

*/