#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int countAnalogousArrays(vector<int>& consecutiveDifference, int lowerBound, int upperBound) {
    int cmin = 0;
    int cmax = 0;
    int cur = 0;

    for (int i : consecutiveDifference) {
        cur += i;
        cmin = min(cmin, cur);
        cmax = max(cmax, cur);
    }

    return max(0, upperBound - lowerBound + cmin - cmax + 1);
}

int main() {
   
    std::vector<int> consecutiveDifference = {-2,-1,-2,5};
    int lowerBound = 3;
    int upperBound = 10;

    
    cout<<countAnalogousArrays(consecutiveDifference, lowerBound, upperBound)<<endl;

   

    return 0;
}