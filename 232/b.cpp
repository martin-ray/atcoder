#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<string>
#include<algorithm>
#include<set>
#include<list>

using namespace std;

#define ALPH 26

int main(void){

    string s;
    string t;
    string ttmp;
    cin >> s >> t;

    for(int i=0;i<ALPH;i++){
        ttmp = t;
        for(int j=0;j<s.size();j++){
            if(ttmp[j]+ i >'z'){
                ttmp[j] = 'a' + ttmp[j] + i - 'z' - 1;
            }
            else{
                ttmp[j] = ttmp[j] + i;
            }
            
        }
        if(ttmp==s){
            std::cout << "Yes" << endl;
            return 0;
        }
    }

    std::cout << "No" << endl;
    
    return 0;
}