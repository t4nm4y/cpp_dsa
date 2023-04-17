#include<iostream>
using namespace std;
class complex
{
    private:
    int real, imag;
public:
//func overloading
    complex()//when no arguments are passed
    {
        real=0;
        imag=0;
    }
    complex(int r, int i)//when 2 int are passed
    {
        real=r;
        imag=i;
    }

//operator overloading
    complex operator + (complex temp)
    {
        complex result;
        result.imag=imag+temp.imag;
        result.real=real+temp.real;
        return result;
    }

//func of a class
    void display()
    {
        cout<<real<<" +i"<<imag<<endl;
    }
};
int main()
{
    complex c1(1,2), c2(10,12);
    complex c3=c1+c2;
    c3.display();

    return 0;
}