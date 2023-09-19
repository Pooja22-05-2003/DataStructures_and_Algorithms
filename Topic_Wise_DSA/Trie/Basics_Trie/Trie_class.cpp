/*
-> Just Like in Linked List here also we need to first create Trie Node class
-> After that we create three functions in our Trie class
-> 1. InsertWord
-> 2. SearchWord
-> 3. RemoveWord
*/
#include <bits/stdc++.h>
using namespace std;
class TrieNode{
    public:
    char data ;
    TrieNode **children;
    bool isTerminal;
    
    TrieNode(char data){
        this->data= data;
        children= new TrieNode*[26];
        //  Initialize all the childre pointers to NULL , because  it should not point to any garbage value
        for(int i=0;i<26;i++){
            children[i]=nullptr;
        }

        isTerminal=false;
    }

};


class Trie{
    TrieNode * root;

    public :
    Trie(){
        root= new TrieNode('\0');
    }

    //  3 functions
    // -> 1. InsertWord
    // -> 2. SearchWord
    // -> 3. RemoveWord

    void InsertWord(string word, TrieNode*root){
        //  base case
        //  empty string=" "
        if(word.size()==0){
            root->isTerminal=true;
            return ;
        }

        // small calulation (We will do small calculation here first , then after that we will call recursion)

        int index=word[0]-'a';
         TrieNode * child;
        if(root->children[index]!=NULL){
            //  It means that that TrieNode with that character is already created
            child=root->children[index];
        }
        else {
            child=new TrieNode(word[0]);
            root->children[index]=child;
            

        }


        //   Recursion call
        InsertWord(word.substr(1),child);
    }
    void insertWord(string word){
        InsertWord(word,root); 
    }

    bool SearchWord(string word , TrieNode * root){
         //  base case
        //  empty string=" "
        if(word.size()==0){
            // if(root->isTerminal==true)  return  true;
            // else return false;
            
            return root->isTerminal;
           
        }

        int index=word[0]-'a';
         TrieNode * child;
        if(root->children[index]!=NULL){
            //  It means that that TrieNode with that character is already created
            child=root->children[index];
            //   Recursion call
             
        }
        else {
          return false;
        }  

        return SearchWord(word.substr(1),child);
    }
    bool searchWord(string word){
        return SearchWord(word, root);
    }

    void RemoveWord(string word , TrieNode * root){
        
        if(word.size()==0){
            root->isTerminal=false;
            return;
        }

        int index=word[0]-'a';
        
        TrieNode * child;
        if(root->children[index]!=NULL){
            child=root->children[index];
            return RemoveWord(word.substr(1),child);
        }
        else {
            return ;
        }

        //  Those nodes which are not forming any word
        //  -> having isTerminal false
        //  -> and having all the children pointing to NULL ptr
        //  -> delete those nodes , they are wasting extra space in our memory
        if(child-> isTerminal==false){
            for(int i=0;i<26;i++){
                if(child-> children[i]!=NULL){
                    //  even one children exist of that nodes, so we can't delete that node
                    return ;
                }
            }

            delete child;
            root->children[index]=NULL;
        }

    }
    void removeWord(string word){
        //  base case
        RemoveWord(word, root);
    }



    
    bool SearchPrefix(string word , TrieNode * root){
         //  base case
        //  empty string=" "
        if(word.size()==0){
            // if(root->isTerminal==true)  return  true;
            // else return false;
            
            return true;
           
        }

        int index=word[0]-'a';
         TrieNode * child;
        if(root->children[index]!=NULL){
            //  It means that that TrieNode with that character is already created
            child=root->children[index];
            //   Recursion call
             
        }
        else {
          return false;
        }  

        return SearchPrefix(word.substr(1),child);
    }
    bool startsWith(string prefix) {
        return SearchPrefix(prefix,root);
    }
};

int main(){
    Trie t;
    t.insertWord("and");
    t.insertWord("pooja");
    t.insertWord("an");
    t.insertWord("hello");

    bool found= t.searchWord("and");
    cout<<" Word Search found or not ? :"<< found<<endl;

    string word2="pooja";
    bool found1=t.searchWord(word2);
    cout<<" Word Search found or not ? :"<< found1<<endl;

    string word3="as";
    bool found2=t.searchWord(word3);
    cout<<" Word Search found or not ? :"<< found2<<endl;

    string PrefixWord="a";
    bool found3=t.startsWith(PrefixWord);
    cout<<"Prifx word found or not?"<<found3<<endl;
    return 0;
}
