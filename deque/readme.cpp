// its a mixture of stack and queue
// header file: <deque>
//we can do bothe the operation at both the ends:
//push pop happens at end
//delete insert happens at first index
#include<iostream>
#include<deque>
using namespace std;

int main()
{
    deque<int> dq;
    dq.push_back(1);
    dq.push_back(2);
    dq.push_back(3);
    for(int i: dq)
    {
        cout<<i<<" ";
    }
    return 0;
}