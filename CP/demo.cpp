
// #include <bits/stdc++.h>
// using namespace std;

// bool check(int st,vector<int>arr, int n , int lb, int ub )
// {
//     vector<int>newarr;
//     int num=st;
//     newarr.push_back(num);
//     int i=0;
//     int prev=arr[i];
//     int x=num;
//     while(i<n-1 && x<=ub)
//     {
//         x=num-prev;
      
//         if(x<=ub) 
//         {
//             newarr.push_back(x);
            
//             i++;
//             prev=arr[i];
//             num=x;
//         }
//         else break;


//     }

//     if(newarr.size()==n) return true;
//     else return false;
// }
// int solve(vector<int>arr, int n , int lb, int ub)
// {
//     int cnt=0;
//     for(int i=lb;i<=ub;i++)
//     {
//         if(check(i,arr,n,lb,ub)) cnt++;
//         else break;
//     }
//     return cnt;
// }

// int main(){
//     #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
//     #endif
//     //**********


//     //*********
//     int n;
//     cin>>n;
//     vector<int>arr(n);
//     for(int i=0;i<n;i++)
//     {
//         cin>>arr[i];
//     }
//     int lb,ub;
//     cin>>lb;
//     cin>>ub;

//     int ans=solve(arr,n,lb,ub);
//     cout<<"ans:"<<ans<<endl;


//     return 0;
// }


// /*
// // input1 :
// 4
// -2
// -1
// -2
// 5
// 3
// 10



// // output1:
// 3


// input 2:
// 3
// -1
// -3
// 2
// 2
// 8

// output :
// 3




// */


#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <bitset>
using namespace std;

string solve(int n, int k, vector<string>& a) {
    for (int i = 0; i < a.size(); ++i) {
        a[i] = a[i].substr(0, a[i].find_last_not_of(' ') + 1);
    }

    sort(a.begin(), a.end());

    for (int i = 0; i < min(k, (int)a.size()); ++i) {
        string curr = "";
        for (char b : a[i]) {
            curr += to_string(1 - (b - '0'));
        }
        a[i] = max(curr, a[i]);
    }

    int ans = 0;
    for (string s : a) {
        ans += stoi(s, nullptr, 2);
    }

    string binary = bitset<64>(ans).to_string();
    return binary.substr(binary.find('1'));
}
int main() {
    int numberofbits = 3; 
    int maximumoperationsallowed = 2;
    vector<string> arr = {"011","100","100"};

    string result = solve(numberofbits, maximumoperationsallowed, arr);
    cout << result << endl;

    return 0;
}
 