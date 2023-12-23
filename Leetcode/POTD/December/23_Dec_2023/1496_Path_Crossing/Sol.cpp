// We can do this using hashTable(and will store all the previos paths, which we had already visited)

// TC=O(N)
// SC=O(N)
class Solution {
public:
    bool isPathCrossing(string path) {
        // This map will store the corresponding values of 'N' , 'E' , 'S', 'w'
        unordered_map<char,pair<int,int>> moves;
        moves['N']={0,1};
        moves['E']={1,0};
        moves['W']={-1,0};
        moves['S']={0,-1};
        unordered_set<string> visited;
        visited.insert("0,0");
        int x=0;
        int y=0;
        for(auto it : path){
            pair<int,int> temp=moves[it];
            int f=temp.first;
            int ss=temp.second;
            x+=f;
            y+=ss;
            string s=to_string(x)+","+to_string(y);
            if(visited.find(s)!=visited.end()) return true;
            visited.insert(s);
        }
        return false;


    }
};