/*

Approach.
1. What is the maximum range of your answer.
2. It can range from [0 to n-1] 


*/

/*
Approach :
-> Chech for answer from 1 to n IF u found first 

*/

// TTTTTFFFFFFF

// TC=O(n)
// SC=O(1)

#include<bits/stdc++.h>
using namespace std;
bool check(int num , int network,int moneyy,int selll,int upgradee  ){

    int remaining_network=network-num;
    int additional_cost=(remaining_network*selll);
    int total_cost=moneyy+additional_cost;
    int require_cost=(num*upgradee);
    return (total_cost>=require_cost);

}

int solvee(int network,int moneyy,int selll,int upgradee ){
    int maxx=0;
    if((network*upgradee)==moneyy) return network;
    
    else {
        
        for(int i=1;i<network;i++){
           
            if(check(i,network,moneyy,selll,upgradee)) maxx=max(maxx,i);
        }
    }
    //  cout<<"check(1):"<<check(4,4,8,4,4)<<endl;
    return maxx;
}
vector<int>  solve(vector<int> total_house, vector<int>money , vector<int>sell , vector<int>upgrade,int  n){
    vector<int> ans;
    for(int i=1;i<=n;i++){
        int network=total_house[i];
        int moneyy=money[i];
        int selll=sell[i];
        int upgradee=upgrade[i];
        ans.push_back(solvee(network,moneyy,selll,upgradee));
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

    vector<int> total_house(n+1);
    for(int i=1;i<=n;i++){
        cin>>total_house[i];
    }
    vector<int> money(n+1);
    for(int i=1;i<=n;i++){
        cin>>money[i];
    }

    vector<int> sell(n+1);
    for(int i=1;i<=n;i++){
        cin>>sell[i];
    }

    vector<int> upgrade(n+1);
    for(int i=1;i<=n;i++){
        cin>>upgrade[i];
    }




    vector<int> ans=solve(total_house, money , sell , upgrade, n);
    for(int i=0;i<n;i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
	return 0;
}
	


/*
// input1 :
2
4 3
8 9
4 2
4 5

// output1:

3 2

// input 2 :


// output 2:


input3:


output3:


*/

