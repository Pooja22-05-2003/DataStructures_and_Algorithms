#include<bits/stdc++.h>
using namespace std;

int solve(int n, int m, string s){
    vector<int>freq(26,0);
    for(int i=0;i<s.size();i++)
    {
        freq[s[i]-'a']++;
    
    }

    for(int i=0;i<=25;i++)
    {
            cout<<"i:"<<i<<" freq[i]:"<<freq[i]<<endl;
    }
    // sort(freq.begin(),freq.end());

    cout<<";;;;;;"<<endl;
    
    for(int i=25;i>=0;i--)
    { 
         if(m<=0) break;
       
        if ((freq[i]>0) && (freq[i]>=m))
        {
            freq[i]=freq[i]-m;
            m=0;
            break;
            
        }
        else if(freq[i]>0 && freq[i]<m)
        {
           freq[i]=freq[i]-m; 
           m=m-freq[i];
        }
    }
    for(int i=0;i<=25;i++)
    {
            cout<<"i:"<<i<<" freq[i]:"<<freq[i]<<endl;
    }

    int ans=0;
    for(int i=0;i<=25;i++)
    {
        ans=ans+pow((freq[i]),2);
    }


    return ans;
}  

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    //**********
//

    //*********

	int n;
    cin>>n;

    int m;
    cin>>m;

    string s;
    cin>>s;
    
    cout<<solve(n,m,s)<<endl;
	return 0;
}
	

/*
input1 :
6
2
bacacc



Output 1:
6



input2 :
15
3
xxxxxxxxxxxxxxx



Output2:
144

*/
