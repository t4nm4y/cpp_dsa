*all operators 
 & : and
 | : or
 ~ : complement (tilden sign)
>> : right shift
<< : left shift

*terminologies
set-bit: if a bit is 1 its called set-bit
if we want to reset-bit: means to set it to 0
if we want to set-bit: means to set it to 1

 (all calculations happen in binary within the system)
*Internally all calculations are done by: 
    first converting the decimal to binary then 
    doing binary operaions on it
    and then converting the final ans to decimal for output.

*convert decimal to any base
    -keep dividing by one and store the reamainder
    -the ans is all the reamainders in reverse order

*convert base a to any base b
    -convert base a to decimal than use the above method to convert to base b

*properties:
when u 'and' with 1 all digits remain the same bcoz( 0&1= 0; 1&1= 1 )
when u 'and' with 0 all digits become 0

when u 'or' with 1 all digits become 1
when u 'or' with 0 digits remain the same bcoz( 0|0= 0; 1|0= 1 )

    ___|_and_|_or____
    1 :|same | 1
    0 :|  0  | same

*a xor 1 = ~a
*a xor 0 = a
*a xor a = 0

        **************** [ very imp property ] ****************************
        if u have a given an array that only contains 1 element that is unique rest all element are twice
        then how to find that unique element in shotest time;
    eg:[1,2,4,2,5,1,4] here 5 is the ans
        ans: just xor all the elements (ie. 1^2^4^2^5^1^4 = 0^5 = 5 )the ans will be the unique element (bcoz a xor a = 0 
        so all duplicates will cancel each other and finally  0 xor 5 will give us 5 only)



*check odd or even
   if( n &1==1 ) then odd else even
   bcoz since 'and' of any digit by 1 give the same digit, so
   if we 'and' the whole no. by 1 it will give me the last digit (eg: [1011 & 1]=[1011 & 0001] = 0001 =1 ); 
                                                                 (eg: [1010 & 1]=[1010 & 0001] = 0000 =0 ).
   and if last digit is 1 the no. is odd
   and if last digit is 0 the no. is even

  *[ last digit is known as LSB, least significant bit ]*

  

*bitwise operators:
1. left shift operator( << )
    meaning:                            ____________________________
    move the binary no. to the left eg:| number: |  101101  |  1010
                                       |    <<1: | 1011010  | 10100
    (simply add zero in the end)

    single left shift:
        a << 1 = a*2  (ie. if u left shift any number by 1 it gets doubled)
    in general :
        a << b = a*(2^b) (ie. [multiply by 2], b times)(ie. doing single left shift, b times)


2. right shift operator( >> )
    meaning:                             ___________________________
    move the binary no. to the right eg:| number: | 101101   | 1010
                                        |    >>1: |  10110   |  101
    (simply delete the last digit)
    
    single right shift:
        a >> 1 = a/2  (ie. if u right shift any number by 1 it gets halfed)
    in general :
        a >> b = a/(2^b) (ie. [divide by 2], b times)(ie. doing single left shift, b times)


what is negative of a no. in binary?
by 2s complement method
negaative of n= ~n+1
    ie. [complement+1]

total nos. that we can store in n bits = 2^n ;
range formula for n bits: [ -2^(n-1) ]to[ 2^(n-1)-1 ] =

    n-1          n-1
 -(2    )  to ( 2   - 1 ) ;

bcoz 
for 1 byte= 8 bits: and the first most box from the left is used to store the sign of the no.(+ve or -ve)
therefore only 7 bits are left (i.e 8-1) we subtract 1 bcoz 1 bit is used to store the sign
now we have 2^7 nos. of +ve, 2^7 of -ve;

so the range will be: { -(2^7)_ _ _ _-1   0 1 2 _ _ _ _ (2^7-1) }
                         \____________/   \___________________/
                               2^7      +          2^7            = 2*(2^7) = 2^8 nos.

since we store 0 as a +ve no. therefore in range we can only store till (2^7-1);
