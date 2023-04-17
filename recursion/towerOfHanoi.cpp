// w4 lab A q4
#include<bits/stdc++.h>
using namespace std;
int toh(int n, char start, char destination, char help, int &c)
{
   
    if (n==0)
    {
        return c;
    }
    toh(n-1,start,help,destination, c);
    cout<<"Move Disk "<<n<<" from "<<start<<" to "<<destination<<endl;
    c++;
    toh(n-1, help, destination, start, c);
}
int main()
{
    int n;
    cout<<"\nEnter the no. of disks: ";
    cin>>n;
    int count=0;
    toh(n,'A','C','B',count); 
    cout<<"\ntotal no. of steps: "<<count<<endl;
    return 0;
}