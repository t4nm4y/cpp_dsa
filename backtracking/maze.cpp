// now we can move in all directions
// in how many total paths can we go from the starting (0,0) to the diagonally other end
//u have to print the paths also
#include<iostream>
using namespace std;
bool board[3][3]=
{
    {true,true,true},
    {true,true,true},
    {true,true,true}
};
int rows=sizeof(board)/sizeof(board[0]);
int col=sizeof(board)/sizeof(int)/rows;
void printAllPath(string ans,int r, int c,int path[][3], int step)
{
    if (r==rows-1 && c==col-1)
    {
        
    }
    
}
int main()
{
    int path[3][3];
    printAllPath("",0,0,path,0);
    return 0;
}