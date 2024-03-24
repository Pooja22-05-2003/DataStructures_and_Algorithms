
#include <bits/stdc++.h>
using namespace std;

bool check(int st,vector<int>arr, int n , int lb, int ub )
{
    vector<int>newarr;
    int num=st;
    newarr.push_back(num);
    int i=0;
    int prev=arr[i];
    int x=num;
    while(i<n-1 && x<=ub)
    {
        x=num-prev;
      
        if(x<=ub) 
        {
            newarr.push_back(x);
            
            i++;
            prev=arr[i];
            num=x;
        }
        else break;


    }

    if(newarr.size()==n) return true;
    else return false;
}
int solve(vector<int>arr, int n , int lb, int ub)
{
    int cnt=0;
    for(int i=lb;i<=ub;i++)
    {
        if(check(i,arr,n,lb,ub)) cnt++;
        else break;
    }
    return cnt;
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    //**********


    //*********
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int lb,ub;
    cin>>lb;
    cin>>ub;

    int ans=solve(arr,n,lb,ub);
    cout<<"ans:"<<ans<<endl;


    return 0;
}


/*
// input1 :
4
-2
-1
-2
5
3
10



// output1:
3


input 2:
3
-1
-3
2
2
8

output :
3




*/
