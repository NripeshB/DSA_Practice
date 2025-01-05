//https://www.naukri.com/code360/problems/implement-a-phone-directory_1062666?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar&leftPanelTabValue=SUBMISSION
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
        root = new TrieNode('\0');
    }

    void insertUtil(TrieNode* root, string  word) {
       
        if(word.length() == 0){
            root->isTerminal = true;
            return;
        }

        
      
        int index = word[0] - 'a';
        TrieNode* child;

        
        if(root->children[index] != NULL ){
            child = root->children[index];
        }

        
        else{
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        insertUtil(child, word.substr(1));
    }

    void insert( string word){
        insertUtil(root,word);
    }

//this function takes in the prefix and the curr node.
// if it stands on a terminal node, it pushes it into the temp data struct 
// if it isnt one then traverses to the next node to curr and pushes the char into the prefix then
// recursively calls itself then backtracks to preserve the prefix.
    void printsugg( vector<string>& temp, string prefix, TrieNode* curr){
        if( curr->isTerminal){
            temp.push_back(prefix);
        }

        for(int i =0; i< 26; i++){
            TrieNode* test = curr->children[i];
            if(test != NULL){
                prefix.push_back(test->data);
                printsugg(temp,  prefix, test);
                prefix.pop_back();
            }
        }
    }
    //this function goes through the characters given in the query, adds it to the prefix and checks 
    //whether they exists as the children of the prev node and names it as curr.
    // if it does exist, it passes the prefix hence built along with an empty data struct to collect
    // the suggestion and then prints it into the output vector 
vector<vector<string> > getsugg(string query){
    TrieNode* prev = root;
    vector<vector<string> > output;
    string prefix = "";

    for(int i =0; i< query.length(); i++){
        char lastch = query[i];
        prefix.push_back(lastch);

        TrieNode* curr = prev->children[lastch - 'a'];

        if(curr == NULL){
            break;
        }

       vector<string> temp;

       printsugg(temp, prefix, curr);

       output.push_back(temp);
       temp.clear();
       prev = curr;
    } 
    return output;
}

};




vector<vector<string>> phoneDirectory(vector<string>&contactList, string &queryStr)
{
    Trie* trie = new Trie();
    for(int i =0; i< contactList.size(); i++){
        trie->insert(contactList[i]);
    }

    return trie->getsugg(queryStr);

}

int main() {
    return 0;
}