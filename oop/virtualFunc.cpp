#include<bits/stdc++.h>
using namespace std;
class base{
    int a=10;
    public:
    virtual void display()
    {
        cout<<"\nthis is base msg";
    }
   virtual void temp()
    {
        cout<<"\na: "<<a;
    }
};
class derived:public base{
    int b=20;
    public:
    void display()
    {
        cout<<"\nthis is derived msg";
    }
    void temp()
    {
        cout<<"\nb: "<<b;
    }
};
int main()
{
    base *bp;
    derived d;
    bp=&d;
    bp->display();
    bp->temp();
    return 0;
}