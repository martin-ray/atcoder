#include<iostream>
#include<algorithm>
#include<map>
#include<string>
#include<vector>
#include<set>
#include<numeric>

long long int gcd(long long int a, long long int b){
  if(a%b == 0){
    return b;
  }else{
    return gcd(b, a%b);
  }
}

using namespace std;

int main(void){

    int n;
    cin >> n;

    vector<pair<int,int>> p(n);
    for(int i=0;i<n;i++){
        cin >> p[i].first >> p[i].second;
    }
    set<pair<int,int>> way;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            //ここで約分すれば問題ない
            int x = p[i].first-p[j].first;
            int y = p[i].second-p[j].second;
            if(x==0){
                if(y<0){
                    y = -1;
                }
                else if(y > 0){
                    y = 1;
                }
                else{
                    y = 0;
                }
            }
            else if(y==0){
                if(x < 0){
                    x = -1;
                }
                else if(x > 0){
                    x = 1;
                }
                else{
                    x = 0;
                }
            }
            else{
                long long int g = abs(gcd(x,y));
                x/=g;
                y/=g;
            }
            way.insert(make_pair(x,y));
            way.insert(make_pair(-x,-y));
            //cout << p[i].first-p[j].first << " "<<p[i].second-p[j].second << endl;;
        }
    }
    
    cout << way.size()<< endl;

    return 0;
}