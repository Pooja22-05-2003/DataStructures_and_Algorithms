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
    // This line finds the iterator pointing to the first element in the range [b.begin(), b.end()) that is greater than 35. The result is stored in the variable mg.
    auto mg = upper_bound(b.begin(),b.end(),35); 


    // This line calculates the index of the element found by upper_bound relative to the beginning of the vector b. It subtracts the iterator b.begin() from the iterator mg. The result is stored in the variable kf.
    auto kf = mg - b.begin();
    
    int ram=kf;//returns__the index of number slightly greater than 100 in array/.

		  //cout<<ram<<"\n";
	int lol = b[ram] ;
	cout<<ram ; 
	cout<<'\n';
    cout<<lol; 
    
    return 0 ; 
}












