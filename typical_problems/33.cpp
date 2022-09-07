#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<string>
#include<algorithm>
#include<set>
#include<list>
#include<bits/stdc++.h>
#include <iomanip>
#include<queue> //do not forget about priority_queue;
//std::cout << std::setprecision(2) << 3.141; // "3.1"


using namespace std;


int H,W;

using namespace std;
int main(void){

    std::cin >> H >> W;
    int num = 0;
    int w_num = W/2 + W%2;
    int h_num = H/2 + H%2;

    if(H<2&&W<2){
        cout << 1 << endl;
        return 0;
    }
    else if(H<2){
        cout << W << endl;
    }
    else if(W<2){
        cout << H << endl;
    }
    else{
        std::cout << w_num*h_num << std::endl;
    }

    
    
    return 0;
}