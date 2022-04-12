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

    int a,b;
    cin >> a >> b;
    if(a<=5){
        cout << 0 << endl;
    }
    else if(5<a && a <13){
        cout << b/2 << endl; 
    }
    else{
        cout << b << endl;
    }
    
    return 0;
}