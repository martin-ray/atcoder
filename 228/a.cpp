#include<iostream>
#include<string>
#include<vector>
#include<map>

using namespace std;

int main(void){

    int s,t,x;
    cin >> s >> t >> x;

    if(s < t){
        if(s <= x && x <t){
            cout << "Yes" << endl;
            return 0;
        }
        else{
            cout << "No" << endl;
            return 0;
        }
    }
    else{
        if(t <= x && x <s){
            cout << "No" << endl;
        }
        else{
            cout << "Yes" << endl;
        }

    }
    return 0;
}