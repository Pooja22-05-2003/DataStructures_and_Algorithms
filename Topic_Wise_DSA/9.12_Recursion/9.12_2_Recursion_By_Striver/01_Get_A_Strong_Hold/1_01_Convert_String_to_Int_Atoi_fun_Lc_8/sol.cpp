// ❌❌My Approach is wrong and failing on so many test cases.
// class Solution {
// public:
//     int myAtoi(string s) {
//         if(s.empty()) return 0;
//         int len=s.size();

//         int i=0;
//         int sign=1;

//         while(i<len && s[i]==' ') i++;
//         if(i==len) return 0;

//         if(s[i]=='-') {
//             sign=0;
//             i++;
//         }
//         else if(s[i]=='+'){
//             i++;
//         }

//         long int output=0;

//         while(s[i]>='0' && s[i]<='9'){
//             output=output*10;
//             if(output<=INT_MIN || output >=INT_MAX) break;
//             output=output+(s[i]-'0');
//             i++;
//         }

//         if(sign==0) output=-1*output;
//         if(output<INT_MIN) return INT_MIN;
//         if(output<INT_MAX) return INT_MAX;
//         return (int) output;
//     }
// };

class Solution {
public:
    int myAtoi(string s) {
        if (s.empty()) return 0;
        int len = s.size();

        int i = 0;
        int sign = 1;

        while (i < len && s[i] == ' ') i++;
        if (i == len) return 0;

        if (s[i] == '-') {
            sign = 0;
            i++;
        } else if (s[i] == '+') {
            i++;
        }

        long int output = 0;

        while (s[i] >= '0' && s[i] <= '9') {
            
// This condition is used to check for overflow during the conversion of the string to an integer. Let's break it down:

//1. output > INT_MAX / 10: This part checks if multiplying the current output value by 10 would result in an overflow. If output is already greater than INT_MAX / 10, then multiplying it by 10 will definitely exceed the limits of an integer.

//2. (output == INT_MAX / 10 && (s[i] - '0') > INT_MAX % 10): This part is a more detailed check. It first checks if the current output value is equal to INT_MAX / 10. If it is, it then checks whether adding the next digit (s[i] - '0') would cause an overflow. If the next digit is greater than the remaining space in the last digit of INT_MAX, an overflow would occur.


// The value of INT_MAX % 10 is 7.

// In general, for a positive integer n, n % 10 gives the last digit of n when expressed in base 10. For INT_MAX, which is 2147483647, the last digit is 7 when divided by 10, so INT_MAX % 10 is 7.

            // the 2nd case of this is like lets say (output*10)= 2147483640, so at max we can add number from 0 to 7 only.
            if (output*10 > INT_MAX || (output *10== INT_MAX  && (s[i] - '0') > INT_MAX % 10))
            {
                return (sign == 0) ? INT_MIN : INT_MAX;
            }
            output = output * 10 + (s[i] - '0');
            i++;
        }

        if (sign == 0) output = -output;

        if (output < INT_MIN) return INT_MIN;
        if (output > INT_MAX) return INT_MAX;

        return (int)output;
    }
};
