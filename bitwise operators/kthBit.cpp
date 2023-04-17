#include<iostream>
#include<bits/stdc++.h>
using namespace std;
// type 1:
//working of the code
// we only need 1 in the kth place rest should be 0. this can be done by: ( 1<<(k-1 ); -->this is called a mask
// nowif we 'and' the whole no. with this mask, we get only the kth digit of the original no. and rest all will be 0
// now we need to right shift the ans same no. of times, so only the kth digit will remain

//eg:
//n = 13, k = 3
// 13      : 1101
// 1<<(k-1):  100 (& with 0 gives 0, & with 1 gives the no. itself) --> this 0100 is called a mask
//     &   : 0100 
//  >>(k-1):    1

// the final ans is 1

int main()
{
    int n=13;
    int k=3;
    //type 1:
    cout<<"the kth bit in the binary representation of the no. is: "
    <<( (n&( 1<<(k - 1) ))>>(k - 1) );

    //type 2:
    //if we want to set the kth bit to 1
    // we can similarly 'or' this time (bcoz 'or' of anythig with 1 gives 1; with 0 gives the no. itself))
    //here mask is same as type1-> only kth bit is 1 and rest is 0 
    cout<<endl<<"after setting the kth bit to 1 the no. becomes: "
    <<( (n|( 1<<(k - 1) )));

    //type 3:
    //if we want to set the kth bit to 0
    //mask-> only the kth bit is 0 and rest is 1
    //then 'and' the no. with the mask (bcoz 'and' of anythig with 0 gives 0; with 1 gives the no. itself)
    // now how to get this mask
    //(it simply the complement of the mask that we used in type 1) = ~( 1<<(k-1 )
    cout<<endl<<"after setting the kth bit to 0 the no. becomes: "
    <<( (n&~( 1<<(k - 1) )));
    return 0;
}