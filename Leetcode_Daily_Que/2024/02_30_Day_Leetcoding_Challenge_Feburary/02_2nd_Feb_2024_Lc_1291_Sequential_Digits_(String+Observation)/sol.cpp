// TC=O(8*8)=O(64)
// SC=O(1)
class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        string s="123456789";

        // As the lower range in the constraints given is so the minimum possible len=2(12)

        vector<int>ans;
        for(int len=2;len<=9;len++)
        {
            for(int startInd=0; startInd<=(s.size()-len);startInd++)
            {
                string temp=s.substr(startInd,len);
                int num=stoi(temp);
                if((num>=low )&&( num<=high)) ans.push_back(num);

            }
        }

        return ans;
    }
};