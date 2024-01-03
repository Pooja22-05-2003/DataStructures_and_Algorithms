/*
1.Approach as the constraint for the n are high, so try to break the problems into 2 half, It
will prevent from overflow.
2. Also in the if the power is in negative, we do the division by 1 ...like pow(2,-2)=1/pow(2,2)....so we 
change the n value to absolute and convert x to 1/x.

*/

// TC=O
class Solution {
public:
    
    double myPow(double x, int n) {
        if(n==0) return 1;
        if(n<0){
            n=abs(n);
            x=1/x;
        }

        double temp=myPow(x,n/2);

        // This techinque of dividing in half, will prevent overflow
        if(n%2==0){
            return temp*temp;
        }
        else return x*temp*temp;
    }
};






