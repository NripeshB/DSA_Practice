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
    //defining a root node for the trie
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
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        //RECURSION
        //the substr(1) reduces the size of the word from the front by one hence at index 0 next letter is present
        insertUtil(child, word.substr(1));
    }

    void insert( string word){
        insertUtil(root,word);
    }

    bool searchUtil(TrieNode* root, string word){
        if (word.length() == 0)
        {
            //if the word is searched then we need to confirm the word found exists or not
            //eg: NO would be true for word NOTHING if we didnt check the isterminal 
            return root->isTerminal;
        }
        //assuming word coming in is in all caps
        int index = word[0] - 'A';
        TrieNode* child;
        //word is present
        if(root->children[index] !=NULL){
            child = root->children[index];
        }

        //if its absent just return false

        else{
            return false;
        }

        //RECURSION

        return searchUtil(child, word.substr(1));
        
    }

    bool searchWord(string word){

        return searchUtil(root, word);
    }


    bool deleteUtil(TrieNode* root, string word) {

        //If word length become 0 this is the base case
        if (word.length() == 0) {
            // Mark current node as not terminal
            if (root->isTerminal) {
                root->isTerminal = false;
                // If no children exist, this node can be deleted
                for (int i = 0; i < 26; i++) {
                    if (root->children[i] != NULL) {
                        return false; // Can't delete this node, as it has children
                    }
                }
                return true; // Safe to delete this node
            }
            return false; // Word not found
        }

        int index = word[0] - 'A';
        TrieNode* child = root->children[index];

        if (child == NULL) {
            return false; // Word not found
        }

        // Recurse to delete the next character
        bool shouldDeleteChild = deleteUtil(child, word.substr(1));

        if (shouldDeleteChild) {
            // Delete the child node
            delete child;
            root->children[index] = NULL;

            // Check if current node can also be deleted
            if (!root->isTerminal) {
                for (int i = 0; i < 26; i++) {
                    if (root->children[i] != NULL) {
                        return false; // Can't delete this node, as it has children
                        //eg: a words like APPLE and APPLY , if i go to delete APPLE then i can only delete
                        // the E as APPLY exists and uses the initial APPL
                    }
                }
                return true; // Safe to delete this node
            }
        }

        return false; // Node cannot be deleted
    }

    void deleteWord(string word) {
        deleteUtil(root, word);
    }

};


int main() {
    Trie* root  = new Trie();
    // insertion, deletion,searching time complexity is O(l) where l is the length of the word
    root->insert("hello");

    cout<<"Does hello exist"<< ": "<<root->searchWord("hello")<< endl;
    Trie* trie  = new Trie();

    trie->insert("HELLO");
    trie->insert("HE");

    cout << "Does HELLO exist? " << trie->searchWord("HELLO") << endl;
    trie->deleteWord("HELLO");
    cout << "Does HELLO exist after deletion? " << trie->searchWord("HELLO") << endl;
    cout << "Does HE exist? " << trie->searchWord("HE") << endl;

    return 0;
}