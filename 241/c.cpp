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


int main(void){
    int n;
    cin >> n;

    vector<string> s(n);
    for(int i=0;i<n;i++){
        cin >> s[i];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            //horizon
            int rest = 2;
            int count = 0;
            int h=i,w=j;
            while(rest>=0&&w<n){
                if(s[h][w]=='#'){
                    count++;
                }
                else{
                    if(rest==0)break;
                    count++;
                    rest--;
                }
                w++;
                if(count == 6){
                    cout << "Yes" << endl;
                    return 0;
                }
            }

            rest = 2;count = 0;h=i;w=j;
            while(rest>=0&&w>=0){
                if(s[h][w]=='#'){
                    count++;
                }
                else{
                    if(rest==0)break;
                    count++;
                    rest--;
                }
                w--;
                if(count == 6){
                    cout << "Yes" << endl;
                    return 0;
                }
            }
            rest = 2;count = 0;h=i;w=j;
            //vertical
            while(rest>=0&&h<n){
                if(s[h][w]=='#'){
                    count++;
                }
                else{
                    if(rest==0)break;
                    count++;
                    rest--;
                }
                h++;
                if(count == 6){
                    cout << "Yes" << endl;
                    return 0;
                }
            }

            rest = 2;count = 0;h=i;w=j;
            //vertical
            while(rest>=0&&h>=0){
                if(s[h][w]=='#'){
                    count++;
                }
                else{
                    if(rest==0)break;
                    count++;
                    rest--;
                }
                h--;
                if(count == 6){
                    cout << "Yes" << endl;
                    return 0;
                }
            }

            //diagonal
            rest = 2;count = 0;h=i;w=j;
            while(rest>=0&&h<n&&w<n){
                if(s[h][w]=='#'){
                    count++;
                }
                else{
                    if(rest==0)break;
                    count++;
                    rest--;
                }
                h++;
                w++;
                if(count == 6){
                    cout << "Yes" << endl;
                    return 0;
                }
            }

            //diagonal2
            rest = 2;count = 0;h=i;w=j;
            while(rest>=0&&h<n&&w>=0){
                if(s[h][w]=='#'){
                    count++;
                }
                else{
                    if(rest==0)break;
                    count++;
                    rest--;
                }
                h++;
                w--;
                if(count == 6){
                    cout << "Yes" << endl;
                    return 0;
                }
            }

            

        }
    }

    cout << "No" << endl;

    return 0;
}