/*
Observations:

1.Brilliant observation :- Any character can go anywhere.  

2.Brilliant observation :- It is now easy to solve ; just make all the places empty and then fill those empty spots by the characters you have in such a manner that maximum strings become palindromes!

3.Brilliant observation :- Sort all the empty places according to their size from small to large! :-> And then start filling the smallest empty place because it has the highest chances of being a plaindrome! 

4.Brilliant observation :- Lets handle the empty space of odd length and even length separately 

5.Brilliant observation :- To fill even length space :-> You try all characters with even frequency and try the largest ones first greedily -> In most cases it will work -> if you exhaust all the even characters -> you will start using the odd characters :-> take them all but dont use their odd guy thats it 

6.Brilliant observation :- Odd length? :p Ignore the middle and follow the same algorithm to fill the rest of the places as their length is even.  With which char should you try to fill the middle guy ? -> Odd char frequency just take 1 from him; if it works good. If its not available take 1 frequency from any even guy 

7.Last observation :-> Proof of the greedy theorem :-> Lets say you are trying to make the 4th string palindrome; and you fail do it then you stop your algorithm and declare 3 as your answer

Who is in this world told you that 5th string palindrome making wont be possible? 

Lets prove it and analyse:- > Watch video for it :)  

*/

// TC=O()
// SC=O()


// Ideone Link: https://ideone.com/WxJt5Q
#include <bits/stdc++.h>

using namespace std;
int solve(int n,vector<string>arr)
{
    // First Priority Queue will store the strings size in ascendding order
    vector<int>size;
    unordered_map<char,int>freq;
    for(int i=1;i<=n;i++)
    {
        size.push_back(arr[i].size());
        string curr=arr[i];
        for(int j=0;j<curr.size();j++)
        {
            freq[curr[j]]++;
        }
    }

    sort(size.begin(),size.end());

    priority_queue<int>Even_PQ;
    priority_queue<int>Odd_PQ;

    for(auto it : freq)
    {
        int cnt=it.second;
        if(cnt%2==0)
        {
           Even_PQ.push(cnt) ;
        }
        else 
        {
            Odd_PQ.push(cnt);
        }
    }

    int ans=0;
    for(int i=0;i<n;i++)
    {
        int vl=size[i];
        if(vl%2==0)
        {

            while(vl!=0 and !Even_PQ.empty())
            {
                int guy=Even_PQ.top();
                if(guy!=0)
                {
                if(guy<=vl)
                {
                    vl=vl-guy;
                    Even_PQ.pop();
                }
                else 
                {
                    guy=guy-vl;
                    vl=0;
                    Even_PQ.pop();
                    Even_PQ.push(guy);

                }
                }
                else return ans;

            }

            // It may happen that even Priority not able to fufill the vl elements, so take from odd PQ.
            while(vl!=0 and !Odd_PQ.empty())
            {
                int guy=Odd_PQ.top()-1;
                if(guy!=0)
                {
                if(guy<=vl)
                {
                    vl=vl-guy;
                    Odd_PQ.pop();
                    // because we excluded one odd guy in top() operation , so include that in PQ.
                    Odd_PQ.push(1);

                }
                else 
                {
                    guy=guy-vl;
                    vl=0;
                    Odd_PQ.pop();
                    Odd_PQ.push(guy+1);

                }
                }
                else return ans;


            }

            if(vl==0) 
            {
                ans=i+1;
                continue;
            }
            else return ans;
        }
      
        else 
        {
            //
            vl=vl-1; // middle element ko exclude krke remaining even length ka fill krne ka try krenege
            while(vl!=0 and !Even_PQ.empty())
            {
                int guy=Even_PQ.top();
                if(guy!=0)
                {
                if(guy<=vl)
                {
                    vl=vl-guy;
                    Even_PQ.pop();
                }
                else 
                {
                    guy=guy-vl;
                    vl=0;
                    Even_PQ.pop();
                    Even_PQ.push(guy);

                }
                }
                else return ans;

            }

            // It may happen that even Priority not able to fufill the vl elements, so take from odd PQ.
            while(vl!=0 and !Odd_PQ.empty())
            {
                int guy=Odd_PQ.top()-1;
                if(guy!=0)
                {
                if(guy<=vl)
                {
                    vl=vl-guy;
                    Odd_PQ.pop();
                    // because we excluded one odd guy in top() operation , so include that in PQ.
                    Odd_PQ.push(1);

                }
                else 
                {
                    guy=guy-vl;
                    vl=0;
                    Odd_PQ.pop();
                    Odd_PQ.push(guy+1);

                }
                }
                else return ans;


            }

            if(vl==0) 
            {
                if(Odd_PQ.empty()==false)
                {
                    int top_guy=Odd_PQ.top();
                    Odd_PQ.pop();
                    if(top_guy>=1) 
                    {
                        // it can satisfy our 1 number need.
                          ans=i+1;
                    }
                    top_guy--;
                    if(top_guy!=0) Odd_PQ.push(top_guy);
                }
                else return ans;
              
            }
            else return ans;
        
            //
        }
    }

    return ans;

}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    //**********
    //

    //*********
   
    int n;
    cin>>n;

 
    vector<string>arr(n+1);
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
    }
    
    int ans=solve(n,arr);
    
    cout<<ans<<endl;
    
    return 0 ; 
}
/*
// // input1 :
4
pass sas asps df


// // output1:
3

// // input1 :

// // output1:

// */