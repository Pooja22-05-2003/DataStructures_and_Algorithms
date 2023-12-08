#include <bits/stdc++.h>
using namespace std;

int main() {
	map<string, int> m;
	int n;cin>>n;
	for (int i=0;i<n;i++){
		string s;cin>>s;
		m[s]++;
	}
	vector<string> ans;
	for (auto i:m)
		if (i.second>1)
			ans.push_back(i.first);
	sort(ans.begin(), ans.end());
	for (string i:ans)cout<<i<<' ';
	return 0;
}