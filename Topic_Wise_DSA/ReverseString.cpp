// #include <iostream>
// #include <string>

// int main() {
//     std::string str;

//     // Input a string from the user
//     std::cout << "Enter a string: ";
//     std::cin >> str;

//     // Reverse the string
//     std::string reversedStr;
//     for (int i = str.length() - 1; i >= 0; i--) {
//         reversedStr += str[i];
//     }

//     // Print the reversed string
//     std::cout << "Reversed string: " << reversedStr << std::endl;

//     return 0;
// }


// C++ program to reverse a string
#include <bits/stdc++.h>
using namespace std;

// Function to reverse words*/
void reverseWords(string s)
{

	// temporary vector to store all words
	vector<string> tmp;
	string str = "";
	for (int i = 0; i < s.length(); i++) {

		// Check if we encounter space
		// push word(str) to vector
		// and make str NULL
		if (s[i] == ' ') {
			tmp.push_back(str);
			str = "";
		}

		// Else add character to
		// str to form current word
		else
			str += s[i];
            cout<<"--"<<str<<endl;
	}

	// Last word remaining,add it to vector
	tmp.push_back(str);
    for(auto it:tmp) cout<<it<<" ";

	// Now print from last to first in vector
	int i;
	for (i = tmp.size() - 1; i > 0; i--)
		cout << tmp[i] << " ";
	// Last word remaining,print it
	cout << tmp[0] << endl;
}

// Driver Code
int main()
{
	string s = "i like this program very much";
	reverseWords(s);
	return 0;
}
