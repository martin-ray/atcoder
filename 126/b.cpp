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
    
    string s;
    cin >> s;
    int first = stoi(s.substr(0,2));
    int second = stoi(s.substr(2));
    //cout << first <<  " " <<second << endl;
    if(1 <= first && first <=12 && 1 <=second && second <=12){
        cout << "AMBIGUOUS" << endl;
    }
    else if(1 <= first && first <=12 && (second == 0 ||12 < second)){
        cout << "MMYY" << endl;
    }
    else if((12 < first||first == 0) && 1 <=second && second <=12){
        cout << "YYMM" << endl;
    }
    else{
        cout << "NA" << endl;
    }
    return 0;
}