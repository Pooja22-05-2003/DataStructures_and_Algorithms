// O(logn)
// SC=O(logn)
/*
Approach :
1. if n=1 , then ind=0, and for (even index => Possibilities are (0,2,4,6,8)=5)
2. If n =2, then ind=0,1 and for (even ind -> Possiblities are (5) , and for odd indexed , possibilities are(2,3,5,7)=>    4 odd numbers lie between 0 and 9)=> So answer is multiplication of both (5*4)=20
3. If n=3, then ind=0,1,2 So output=> 5*4*5=> 100.
4. So by observation , for n=even (odd indexes are -> n/2 and even indexes are also -> n/2)
   So , output = pow(4,n/2)*pow(5,n/2)
5. For n=odd, (even indexes are -> (n/2+1) and odd indexes are (n/2))
   So, output = pow(4,n/2)*pow(5,n/2)
6. Remember to apply mod after each operation.To prevent overflow.
*/

class Solution {
public:
    int mod=1000000007;

    // Solve Function is Nothing but , it is a power function
    long long  solve(long long  x, long long  y){
        if(y==0) return 1;
        long long ans=solve(x,y/2);
        ans=ans*ans;
        ans=ans%mod;
        if(y%2==1) ans*=x;
        ans=ans%mod;
        return ans;
        
    }
    int countGoodNumbers(long long n) {
        if(n%2==0){
            return( solve(4,n/2)*solve(5,n/2))%mod;
        }
        else {
            return (solve(5,(n/2)+1)*solve(4,n/2))%mod;
        }
    }
};