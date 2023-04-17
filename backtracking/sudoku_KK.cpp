
//solve sudoku without taking arguements in the function
//so here i didnt take row and col as arguements int the sudoku() function
#include<iostream>
using namespace std;

bool isValid(int row, int col, int key, int board[][9])
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

bool sudoku(int board[][9])
{
    bool foundEmpty=false;
    int row,col;
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if(board[i][j]==0)
            {
                row=i, col=j;
                foundEmpty=true;
                goto check; //empty element milte hi exit the for loops and directly check that which no. we can put there.
            }
        }
    }
    //if no empty space found in the sudoku, this means sudoku is solved
    if (!foundEmpty) return true;
    
    check:
    for (int i = 1; i <=9; i++)
    {
        if(isValid(row,col,i, board))
        {
            board[row][col]=i;

            //agar i put krne se sudoku solve hogya then ques is solved, else backtrack
            if (sudoku(board)) return true;
            else board[row][col]=0; //backtrack
        }
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

    if(sudoku(board))
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
    
    return 0;
}