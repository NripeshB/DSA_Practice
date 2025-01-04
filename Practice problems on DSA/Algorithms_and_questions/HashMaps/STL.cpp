#include <iostream>
#include <map>
#include <unordered_map>

//maps are based on bst hence they have functional TC as log k
//while unordered maps are based on hashmaps so have a functional
//TC of 1 (constant time)
using namespace std;


int main() {

    //creation 

    unordered_map<string, int> m;

    //ways to insert: 
    //1
    pair<string, int> p = make_pair("mera", 3);
    m.insert(p);

    //2
    pair<string, int> pair2("naam", 2);
    m.insert(pair2);

    //3 
    m["nripesh"] = 8;


    //if we type
    m["nripesh"] = 7;
    //it will overwrite the previous written value for the same key


    //search
    //1
    int ans = m["mera"];
    cout<<ans<<endl;

    //2
    int ans = m.at("mera");
    cout<<ans<<endl;


//diff between 1 and 2 is, if a key doesnt exist, then using 1 
//creates it mapped to 0, but 2nd one throws an error.
    

    cout<<m["unknown"]<<endl;
    cout<<m.at("unknown")<<endl;

    // size

    cout<< m.size()<<endl;

    //to check presence 

    cout<<m.count("mera")<<endl;  //returns 1 for presence and 0 for absence
    

    //deletion

    m.erase("mera");
    

    cout<<m.size()<<endl;
    return 0;


}