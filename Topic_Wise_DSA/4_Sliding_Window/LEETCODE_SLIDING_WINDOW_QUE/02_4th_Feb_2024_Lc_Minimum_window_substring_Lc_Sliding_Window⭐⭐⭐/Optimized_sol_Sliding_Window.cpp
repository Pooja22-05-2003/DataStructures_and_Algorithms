//Optimized approach is sliding Window
//TC=O(n+m)
//SC=O(t)=> string t size.

/*
Approach:
1. Try to find the first valid woindow or substring , in this case, j pointer will only move forward.
2. Now if find some length of the window which is valid, then try to reduce it., now u try to move i++, by 
fixing the j pointer, and then u if the smaller window size is also valid, then update the minimum length, else 
3. try to increase j , and decrease.
4. Do this iteration till last index and final return the minimum possible window size.
*/


class Solution {
public:

    string minWindow(string s, string t) {
        int m=s.size();
        int n=t.size();
        if(n>m) return "";

      
        // it means that the length of the string s> length of the string t.
        int minlen=INT_MAX;
        int finalst=0;

        // map of string t
        unordered_map<char,int>map_t;
        int count=t.size();
        for(auto x:t) map_t[x]++;
        // check for all the possible substring , if it was good , then update the maxlen with comparsion
        string ans="";
        int j=0;
        int i=0;

        while(j<m)
        {
            char c=s[j];

            if(map_t[c]>0)
            {
                   count--;
                 
            }

            // this char freq -- will also happen if that element is not present in the map, and 
            // when we will move i pointer this help, as the element which are not present there frequency will never cross 0.
              map_t[c]--;
             
           
            // now u should start finding the smaller valid windowsize
            // j++;
           
            while(count==0)
            {
               if((j-i+1)<minlen)
               {
                   finalst=i;
                   minlen=(j-i+1);
                   
               }

            //    as u removed the char from the window , so increase its frequency in the map 
               map_t[s[i]]++;
               if(map_t[s[i]]>0)
               {
                   count++; // inside this loop only those character come which is present in the string t.
               }
                

                i++;
            }

            j++;
        }


        if(minlen==INT_MAX ) return "";
        else return s.substr(finalst,minlen);
    }
};