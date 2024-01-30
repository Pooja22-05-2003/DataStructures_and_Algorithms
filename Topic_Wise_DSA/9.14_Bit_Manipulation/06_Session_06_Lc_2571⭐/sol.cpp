// TC=O(17)
// SC=O(1)
class Solution {
public:
    int minOperations(int n) {
        int Number_of_Bit_added=0;

        // as in constrainsts (maximum range of the number is given as (1e5)) and that can store maximum 17 bits.
        for(int i=0;i<=17;i++)
        {
            // Inbuilt founction that return total number of set bits:
            if(__builtin_popcount(n+(1<<i))<__builtin_popcount(n))
            {
                n=n+(1<<i);
                Number_of_Bit_added++;
            }
        }

        int subtraction_bit_count=__builtin_popcount(n);
        return Number_of_Bit_added+subtraction_bit_count;
    }
};