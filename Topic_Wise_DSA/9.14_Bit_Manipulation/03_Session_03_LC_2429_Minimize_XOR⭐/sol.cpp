/*
Problem in 1 Line :
1. We need to find a number x.
2. 2 conditions on x
    a) Number of set bits in the x should be equal to number of set bits in num2.
    b) Output of X xor num1 should be minimal.


Approach :
1. If we satisfy the 2nd condition on x, then we can take the x as the same number as num1(Now all the bits of x and num1 are same and there xor=0).
2. But now we need to satisify the 2nd condition that, number of set bits in num2==number of set bits in x.

 Ex1: lets' say num1=3 [1 1] , num2=5 [1 0 1] (num2 has 2 number of set bits.)
  x=num1            1 1               
  xor  output:      0 0

  But we need to set 2 bits in x and that is already set , so x=3(1 1)


  Ex2: num1=1[0 1] , num2=12 [1 1 0 0]
  x=          1 1 [ run from left and try to set the bit leftmost part 1st]
  xor=        1 0

  output : 3


EX3:⭐ num1= [1 0 0 1]   num2 contain 3 set bits =[1 1 1]
x=            [1 0 0 1]
xor=           0 0 0 0 [but we need to set 1 more bit in the x]

2 options are there set the 1 st bit(0-->1) or set the 2nd bit (0-->1)

lets explore both options , then we will conclude which is the best part.

lets set 1st bit.          let's set the 2nd bit
num1=   1 0 0 1             1 0 0 1
x=      1 0 1 1             1 1 0 1
output: 0 0 1 0(2)          0 1 0 0 (4)

Note: we neeed to find the minimum output : , so try to set the least significant bit. (left  most bit as we did in the first case).


*/

class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int x=num1; // initially try to take the num1 as x.
       
        // 2. count the number of set bits in the num2.

        int countOfSetBitInNum2=0;
        for(int i=30;i>=0;i--)
        {
            int g=(num2>>i);
            if((g&1)==1) countOfSetBitInNum2++;
        }

        // count the number of set bits in x
         int countOfSetBitInX=0;
        for(int i=30;i>=0;i--)
        {
            int g=(x>>i);
            if((g&1)==1) countOfSetBitInX++;
        }
       
        if(countOfSetBitInX>=countOfSetBitInNum2)
        {
        // ✨✨U missed this condiiton and returning simly x in this case , which is wrong. why?
        // we can reduxe the set bits in x andd make it even smaller.
        // So from left if the bit is set in x try to unset it (till your condition is satisfying (cnt>cnt2))
        int cnt1=countOfSetBitInX;
        int cnt2=countOfSetBitInNum2;
        int i=0;
        while(cnt1>cnt2 && x>0)
        {
            int ggg=(x>>i);
           
            if((ggg&1)==1) 
            {
                 int temp=(1<<i);
                 x=x-temp;
                  
                cnt1--;  
            }
             i++;
          
        }
        return x;
        } 
        else 
        {
            int Count_of_unset_bit=countOfSetBitInNum2-countOfSetBitInX;
            int currcnt=0;
            for(int i=0;i<=30;i++){
                int g=(x>>i);

                if(((g&1)==0) && (Count_of_unset_bit>currcnt))
                {
                    x+=(1<<i);
                    currcnt++;
                } 
            }
        }
   
        return x;

    }
};










