#include<iostream>
using namespace std;
int c;//count
string keypad[]={ "0","1","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
void allCombinations(string ans, string input)
{
    if (input.empty())
    {
        c++;
        cout<<ans<<" ";
        return;
    }

    //input[0]-'0' will convert the char to int, so as to get the index for the keypad array
    // now for each char(eg:(a,b,c)) we will run recursion for the rest of the buttons
    for (int i = 0; i < keypad[input[0]-'0'].size(); i++)
    {
        char ch=keypad[input[0]-'0'][i]; //first character of the string corresponding to the input(button)
        allCombinations(ans+ch, input.substr(1));
    }
}
int main()
{
    string input="234";
    allCombinations("",input);
    
    cout<<endl<<c;
    return 0;
}