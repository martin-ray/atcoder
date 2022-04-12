#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<string>
#include<algorithm>
#include<list>

using namespace std;


int main(void){

    int n;
    string s;

    cin >> n >> s;

    list<int> ans{0,-1};

    auto prev = ans.begin();

    for(int i=0;i<n;i++){
        if(s[i]=='R'){
            prev++;
            ans.insert(prev,i+1);
            prev--;

        }
        else{
            ans.insert(prev,i+1);
            prev--;
        }
    }
    ans.pop_back();

    for(auto itr=ans.begin();itr!=ans.end();itr++){
        cout << *itr << endl;
    }
    return 0;
}