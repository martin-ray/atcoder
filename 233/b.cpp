#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<string>
#include<algorithm>
#include<set>
#include<list>

using namespace std;

int main(void){

    int l,r;
    string s;
    cin >> l >> r;
    cin >> s;
    l--;r--;

    string right,middle,left;
    left = s.substr(0,l);
    middle = s.substr(l,r-l+1);
    right = s.substr(r+1);
    //cout << right << "\n" << middle <<"\n" <<left <<  endl;

    reverse(middle.begin(),middle.end());
    //cout << middle << endl;

    cout << left + middle + right << endl;
    
    return 0;
}