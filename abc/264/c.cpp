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
#define MOD 1000000007
using namespace std;

int main(void){

    int H1,W1,H2,W2;
    cin >> H1 >> W1;
    vector<vector<int>> a(H1,vector<int>(W1));
    for(int h=0;h<H1;h++){
        for(int w=0;w<W1;w++){
            cin >> a[h][w];
        }
    }

    cin >> H2 >> W2;
    vector<vector<int>> b(H2,vector<int>(W2));
    for(int h=0;h<H2;h++){
        for(int w=0;w<W2;w++){
            cin >> b[h][w];
        }
    }

    vector<vector<int>> a_copy(H1,vector<int>(W1));

    for(int bit1 = 0;bit1 < (1 << H1);bit1++){
        for(int bit2 = 0;bit2 < (1 << W1);bit2++){
            a_copy = a;
            int red_h = 0;
            int red_w = 0;
            for(int h = 0; h < H1; h++){
                if(bit1>>h & 1){
                    red_h++;
                    for(int w = 0;w < W1;w++){
                        a_copy[h][w] = 0;
                    }
                }
            }  

            for(int w = 0; w < W1;w++){
                if(bit2>>w & 1){
                    red_w++;
                    for(int h = 0;h < H1;h++){
                        a_copy[h][w] = 0;
                    }
                }
            }

            // for(int h=0;h<H1;h++){
            //     for(int w=0;w<W1;w++){
            //         cout << a_copy[h][w] << " ";
            //     }
            //     cout << endl;
            // }
            // cout << endl;

            // reproduce reduced_a from a_copy
            vector<vector<int>> reduced_a(H1-red_h,vector<int>());
            int hh=0;
            for(int h=0;h < H1;h++){
                int ww=0;
                bool empty_flag = true;
                for(int w=0;w < W1;w++){
                    if(a_copy[h][w]){
                        reduced_a[hh].push_back(a_copy[h][w]);
                        empty_flag = false;
                    }
                }

                if(!empty_flag)hh++;
            }

            if(reduced_a == b){
                cout << "Yes" << endl;
                return 0;
            }
        }
    }

    cout << "No" << endl;

    return 0;
}