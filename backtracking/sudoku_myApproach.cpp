#include<iostream>
using namespace std;

bool isSafe(int row, int col, int key,int board[][9])
{
    //check for the entire row
    for (int i = 0; i < 9; i++)
        if(board[row][i]==key) return false;

    //check for the entire col
    for (int i = 0; i < 9; i++)
        if(board[i][col]==key) return false;

    //check for the 3x3 box
        //finding the starting index of the box (row,col)
        //starting index will be a multiple of 3 (and it should be smaller or equal to  the current index)
    row=row-row%3;
    col=col-col%3;
    for (int i = row; i < row+3; i++)
        for (int j = col; j < col+3; j++)
            if(board[i][j]==key) return false;

    return true;
}

bool sudoku(int row, int col,int board[][9])
{
    if(row==8 && col==9)
    return true;

    // int row=0,col=0;
    if(board[row][col]==0)
    {
        for (int i = 1; i <=9; i++)
        {
            if(isSafe(row,col,i,board))
            {
                int tr=row, tc=col;
                board[row][col]=i;
                col++;
                if(row<8 && col==9)
                {
                    row++;
                    col=0;
                }
                if(sudoku(row,col,board))
                {
                   // print board;
                   for (int i = 0; i < 9; i++)
                   {
                       for (int j = 0; j < 9; j++)
                       {
                           cout<<board[i][j]<<" ";
                       }
                       cout<<endl;
                   }
                   
                }
                else //backtrack
                {
                    row=tr, col=tc;
                    board[row][col]=0;
                    continue;
                }
            }
        }
    }
    else
    {
        col++;
        if(row<8 && col==9)
        {
            row++;
            col=0;
        }
        sudoku(row,col,board);
    }
    return false;   
}
int main()
{
    //here the board of sudoku is represented by 2d array named board
    int board[9][9]=
    {
        {3, 0, 6, 5, 0, 8, 4, 0, 0}, 
        {5, 2, 0, 0, 0, 0, 0, 0, 0}, 
        {0, 8, 7, 0, 0, 0, 0, 3, 1}, 
        {0, 0, 3, 0, 1, 0, 0, 8, 0}, 
        {9, 0, 0, 8, 6, 3, 0, 0, 5}, 
        {0, 5, 0, 0, 9, 0, 6, 0, 0}, 
        {1, 3, 0, 0, 0, 0, 2, 5, 0}, 
        {0, 0, 0, 0, 0, 0, 0, 7, 4}, 
        {0, 0, 5, 2, 0, 6, 3, 0, 0}
    };
    sudoku(0,0,board);
    return 0;
}