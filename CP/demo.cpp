// TC=O(N+M)
// SC= O(26)=O(1)

#include <bits/stdc++.h>
using namespace std;


bool checkEquality( unordered_map<char,int> &Map1, unordered_map<char,int> &Map3)
{
   for(char temp='a';temp<='z';temp++){
      if(Map1[temp]!=Map3[temp]){
         return false;
      }
   }
   return true;
}
string  solve(string s1,string s2){
   unordered_map<char,int> Map1;
   unordered_map<char,int> Map2;
   unordered_map<char,int> Map3;
   unordered_map<char,int> Map4;

   // here we can create 4 hash array or maps
   //  Map1 contain frequency of char of odd index in string s1.
   //  Map2 contain frequency of char of even index in string s2.
   //  Map3 contain frequency of char of odd index in string s3.
   //  Map4 contain frequency of char of even index in string s4.

   for(int i=0;i<s1.size();i++){
      if(i%2==0){
         Map2[s1[i]]++;
      }
      else {
         Map1[s1[i]]++;
      }
   }

   for(int i=0;i<s2.size();i++){
      if(i%2==0){
         Map4[s2[i]]++;
      }
      else {
         Map3[s2[i]]++;
      }
   }


   //  chech if map1 all characters count are equal to map3
   //  all character count  
   // && 
   //  chech if map2 all characters count are equal to map4
   //  all character count  

   //  If both condition are satisftying than we can make twins by performing operations
   //  else not.

   if(checkEquality(Map1,Map3) && checkEquality(Map2,Map4) ) return "YES";
   else return "NO";

}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    //**********

    //*********

    string s1,s2;
    cin>>s1;
    cin>>s2;
    cout<<solve(s1,s2)<<endl;
   


}






/*
input :
cdab
abcd

 

output :
YES


input :
dcba
abcd

 

output :
NO

input 3:
dcba
bcda

output3:
YES

*/




