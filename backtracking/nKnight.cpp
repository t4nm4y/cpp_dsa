#include<bits/stdc++.h>
using namespace std;

int cnt=0;
int n=4;
int **arr=new int *[n];

bool isvalid(int row, int col)
{
    if(row>=0 && row<n && col>=0 && col<n) return true;
    else return false;
}
bool isSafe(int row, int col)
{
    if(isvalid(row-2,col-1))
    if(arr[row-2][col-1]==1) return false;

    if(isvalid(row-2,col+1))
    if(arr[row-2][col+1]==1) return false;

    if(isvalid(row-1,col+2))
    if(arr[row-1][col+2]==1) return false;

    if(isvalid(row-1,col-2))
    if(arr[row-1][col-2]==1) return false;

    return true;
}

void nKnight(int row,int col,int knights)
{
    if(knights==0) 
    {
        for (int i = 0; i < n; i++)
        {
            for (int j= 0; j< n; j++)
                cout<<arr[i][j]<<" ";
            cout<<endl;
        }
        cout<<cnt<<endl;

        cnt++;

        if(cnt>50) //the output was getting very big so used exit to stop in between
        exit(0);

        return;
    }
        // return true;
    if(row==n-1 && col==n) return;

    if(col==n)
    {
        nKnight(++row,0,knights);
        return;
    }

    if(isSafe(row,col))
    {
        arr[row][col]=1;
        nKnight(row,++col,--knights);
        col--;
        knights++;
        arr[row][col]=0;      
    }  
    
    nKnight(row,++col,knights);
    return;
}

int main()
{
    for (int i = 0; i < n; i++)
    {
        arr[i]=new int[n];
        for (int j= 0; j < n; j++)
        {
            arr[i][j]=0;
        }
    }
    cout<<" start " <<endl;
    nKnight(0,0,n); // 1 represents the places where we place a knight
    cout<<cnt<<endl;

    return 0;
}