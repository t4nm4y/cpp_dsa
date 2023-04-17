#include<iostream>
using namespace std;
/*
    here the board is like this:
    eg: n=4;
    so the indexing in the code is according to this:

      0 1 2 3
      ________
  0  |        |
  1  |        |
  2  |        |
  3  |________| 

*/
int count=0;
bool isSafe(int **arr,int x, int y, int n)
{
    //straight up to koi queen nhi h
    for (int row = 0; row < x; row++)
        if(arr[row][y]==1) return false;

    int row=x,col=y;
    //left diagonally to koi queen nhi h
    while (row>=0 && col >=0)
    {
        if(arr[row][col]==1) return false;
        row--; col--;
    }

    row=x, col=y;
    //right diagonally to koi queen nhi h
    while (row>=0 && col<n)
    {
        if(arr[row][col]==1) return false;
        row--; col++;
    }
    //if teeno directions m queen nhi h then only true
    return true;
}
bool nQueen(int **arr, int x, int n)
{
    if(x==n) return true;

    for (int  col = 0; col < n; col++)
    {
        if (isSafe(arr,x,col,n))
        {
            arr[x][col]=1;
            if (nQueen(arr,x+1,n))
            {
                //print the board
                for (int i = 0; i < n; i++)
                {
                    for (int j= 0; j< n; j++)
                        cout<<arr[i][j]<<" ";
                    cout<<endl;
                }
                cout<<endl;
                count++;
            }
            arr[x][col]=0;
        }
    }
    return false;
}
int main()
{
    int n=4;
    int **arr=new int *[n];
    for (int i = 0; i < n; i++)
    {
        arr[i]=new int[n];
        for (int j= 0; j < n; j++)
        {
            arr[i][j]=0;
        }
    }
    
    nQueen(arr,0,n); // 1 represents the places where we can keep queen
    cout<<count<<endl;

    return 0;
}