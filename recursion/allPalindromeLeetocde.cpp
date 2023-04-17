// #include<bits/stdc++.h>
// using namespace std;
// bool isPalindrome(string str, int low, int high)
// {
//     while (low < high)
//     {
//         if (str[low] != str[high])
//             return false;
//         low++;
//         high--;
//     }
//     return true;
// }
// // Recursive function to find all palindromic partitions of str[start..n-1]
// // allPart --> A vector of vector of strings. Every vector inside it stores
// //             a partition
// // currPart --> A vector of strings to store current partition
// void allPalindromicPartUtil(vector<vector<string> >&allPart, vector<string> &currPart, int start, int n, string str)
// {
//     // If 'start' has reached len
//     if (start >= n)
//     {
//         allPart.push_back(currPart);
        
//         return;
//     }
 
//     // Pick all possible ending points for substrings
//     for (int i=start; i<n; i++)
//     {
//         // If substring str[start..i] is palindrome
//         if (isPalindrome(str, start, i))
//         {
//             // Add the substring to result
//             currPart.push_back(str.substr(start, i-start+1));
 
//             // Recur for remaining remaining substring
//             allPalindromicPartUtil(allPart, currPart, i+1, n, str);
             
//             // Remove substring str[start..i] from current
//             // partition
//             currPart.pop_back();
//         }
//     }
// }                   
// vector<vector<string> >allPalindromicPartitions( string str)
// {
//     if(str.empty())
//     int n = str.length();
//     vector<string> currPart;
//     vector<vector<string> > ans;
//     //here i is start index, j in end index of any current string
//     for (int i = 0; i < n; i++)
//     {
//         if (isPalindrome(str,0, i))
//         {
//             currPart.push_back(str.substr(i, j-i+1));
//             allPalindromicPartitions(str.substr(1));
//             currPart.pop_back();
//         }
//     }
//         ans.push_back(currPart);
//         currPart.clear();
//     }
//     return ans;
// }
// int main()
// {
//     string s;
//     cout<<"\nEnter the string: ";
//     cin>>s;
//     vector<vector<string> > ans;
//     ans=allPalindromicPartitions(s);

//     //print
//     for (int i=0; i< ans.size(); i++ )
//     {
//         for (int j=0; j<ans[i].size(); j++)
//             cout << ans[i][j] << " ";
//         cout << "\n";
//     }
//     return 0;
// }