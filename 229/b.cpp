#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<string>

using namespace std;

int main(void){

    string a,b;
    cin >> a >> b;
    long long int a_in,b_in;

    //桁をそろえる
    if(a.length() < b.length()){
        swap(a,b);
    }

    int keta_dif = (a.length() - b.length());
    a_in = stoll(a);
    b_in = stoll(b);

    for(int i=0;i<b.length();i++){
        if(a_in%10+b_in%10>=10){
            cout << "Hard" << endl;
            return 0;
        }

        a_in/=10;
        b_in/=10;
    }

    cout << "Easy" << endl;


    return 0;
}