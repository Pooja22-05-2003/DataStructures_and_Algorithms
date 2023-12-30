// TC=O(n.k)
// sc=O(n)
class Sol
ution {
public:

    bool makeEqual(vector<string>& words) {
        unordered_map<char,int> count;
        if(words.size()==1) return true;
        for(int i=0;i<words.size();i++){
            for(int j=0;j<words[i].size();j++){
                count[words[i][j]]++;
            }
        }

        // int currCount=0;
        // for(auto it : count){
        //     int c=it.second;
        //     if((c==1 && currCount==1) || (currCount!=0 && c!=currCount)) 
        //     {
        //         return false;
        //     }
            
        //     currCount=c;
        // }
        //   return true;


        // If we can divide the each character in the size of the array, then we can make the array same  else not possible
        int n = words.size();
        for(auto it : count){
            int freq=it.second;
            if(freq%n !=0) return false;
        }

        return true;
    }

};














