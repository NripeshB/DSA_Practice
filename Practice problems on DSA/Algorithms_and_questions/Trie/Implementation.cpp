#include <iostream>
using namespace std;

class TrieNode{
    public: 
    char data;
    TrieNode* children[26];
    bool isTerminal;

    TrieNode(char data){
        this->data = data;

        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }

        isTerminal = false;
        
    }
};

class Trie{
    public:
    TrieNode* root;
    Trie(){
        //initialising the root node with a null character
        root = new TrieNode('\0');
    }

    void insertUtil(TrieNode* root, string  word) {
        //it is the end of the word
        if(word.length() == 0){
            root->isTerminal = true;
            return;
        }

        //defining the index, assuming word inserted is in caps
        //we take the first letter as we reduce the word length at each recursive call
        int index = word[0] - 'A';
        TrieNode* child;

        //the letter is present, then the children node at the corresponding letter index should have some value
        // and after finding it, you should traverse it ahead;
        if(root->children[index] != NULL ){
            child = root->children[index];
        }

        //And if it isnt present then
        else{
            child = new TrieNode(word[index]);
            root->children[index] = child;
        }

        //RECURSION
        //the substr(1) reduces the size of the word from the front by one hence at index 0 next letter is present
        insertUtil(child, word.substr(1));
    }

    void insert( string word){
        TrieNode* root;
        insertUtil(root,word);
    }
};


int main() {
    Trie* root  = new Trie();
    root->insert("hello");
    return 0;
}