#include<iostream>
using namespace std;

int count=0;
int n=3;
int **arr=new int *[n];

bool isvalid(int row, int col)
{
    if(row>=0 && row<n && col>=0 && col<n) return true;
    else return false;
}
bool isSafe(int **arr,int row, int col)
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

void nKnight(int **arr,int row,int col,int knights)
{
    if(knights==0) 
    {
        for (int i = 0; i < n; i++)
        {
            for (int j= 0; j< n; j++)
                cout<<arr[i][j]<<" ";
            cout<<endl;
        }
        cout<<endl;
        count++;
        return;
    }
        // return true;
    if(row==n-1 && col==n) return;

    if(col==n)
    {
        nKnight(arr,++row,0,knights);
        return;
    }

    if(isSafe(arr,row,col))
    {
        arr[row][col]=1;
        // ++col;
        // let row = 3 , col = 5, k = 10
        
        nKnight(arr,row,++col,--knights);
        // is call ke baad value hogi col = 6 and k = 9
        col--;
        ++knights;
        arr[row][col]=0;      
    }  

    // to vo iss jaga // call marega for col = 7 and knights = 9
    nKnight(arr,row,++col,knights);
    // but call should have been for cow = 3 , col = 5 and k = 10
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
    nKnight(arr,0,0,n); // 1 represents the places where we place a knight
    cout<<count<<endl;

    return 0;
}