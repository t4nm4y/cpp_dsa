//kunal kushwaha

#include<iostream>
using namespace std;
int count=0;
void totalPathsMaze(int row, int col, string paths)
{
    if(row==1 &&col==1)
    {
        cout<<paths<<endl;
        count++;
        return;
    }

    if(row>1)
    totalPathsMaze(row-1,col,paths+'d'); //d means one step down
    if(col>1)
    totalPathsMaze(row,col-1,paths+'r'); //r means one step right
    if(row>1&& col>1)
    totalPathsMaze(row-1,col-1,paths+'t'); //t means one diaogonal move
}
int main()
{   
    int row=3;
    int col=3;
    string paths="";
    cout<<endl;
    totalPathsMaze(row,col,paths);
    cout<<endl<<"total no. of paths: "<<count<<endl;
    return 0;
}