#include<iostream>
using namespace std;

int totalPathsMaze(int row, int col)
{
    if(row==1 || col==1)
    return 1;

    //we can move in any direction

    //                  down         +             right         +              diagonal
    return totalPathsMaze(row-1,col) + totalPathsMaze(row,col-1) + totalPathsMaze(row-1,col-1);
}
int main()
{
    int row=3;
    int col=3;
    cout<<totalPathsMaze(row,col);
    return 0;
}