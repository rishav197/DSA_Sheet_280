#include <bits/stdc++.h>
using namespace std;
/*print all duplicate in input string*/

void prtDups(string &s){
    unordered_map<char, int> mp;

    for(int i=0; i<s.length(); ++i){
        mp[s[i]]++;
    }

    for(auto &it : mp){
        if(it.second>1){
            cout<<it.first<<" "<<it.second<<endl;
        }
    }
}

int main(){

    string s = "test string";
    prtDups(s);

    return 0;
}