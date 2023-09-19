class TrieNode{
    char data;
    TrieNode** children;
    bool isTerminal;

    TrieNode(char data ){
        this->data=data;
        children= new TrieNode*[26];

        //  after creating children array , initialize it with null to get rid of the grabage value
        for(int i=0;i<26;i++){
            children[i]=nullptr;
        }
        isTerminal=false;
    }

};