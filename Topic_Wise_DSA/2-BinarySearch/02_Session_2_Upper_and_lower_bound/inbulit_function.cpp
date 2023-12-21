#include <bits/stdc++.h>

using namespace std;

int main() {
    
    
    int n ; 
    cin>>n ; 
    vector <int> b ; 
    int i = 0 ; 
    while(i<n){
        int yy ; cin>>yy ; 
        b.push_back(yy);
        i++;
    }
    sort(b.begin(),b.end()); 
    
    auto mg = upper_bound(b.begin(),b.end(),35); 
    auto kf = mg - b.begin();
    
    int ram=kf;//returns__the index of number slightly greater than 100 in array/.

		  //cout<<ram<<"\n";
	int lol = b[ram] ;
	cout<<ram ; 
	cout<<'\n';
    cout<<lol; 
    
    return 0 ; 
}












