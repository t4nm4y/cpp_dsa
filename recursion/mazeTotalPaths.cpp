#include<iostream>
using namespace std;

int totalPathsMaze(int row, int col)
{
    if(row==1 || col==1)
    return 1;

    //since form any current position we can either go down or right
    //therefore add (the no. of ways from the position one row down) + (the no. of ways from the position one col right)
    //which is same as reducung the size of the matrix and finding the total paths
    return totalPathsMaze(row-1,col) + totalPathsMaze(row,col-1);
}
int main()
{
    int row=4;
    int col=3;
    cout<<totalPathsMaze(row,col);
    return 0;
}