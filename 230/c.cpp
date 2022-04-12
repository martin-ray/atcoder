#include<iostream>
#include<vector>
#include<map>
#include<queue>
#include<algorithm>

using namespace std;

int main(void){

    long long int n,a,b,p,q,r,s;
    cin >> n >> a >> b;
    cin >> p >> q >> r >> s;

    long long int first = max(1-a,1-b);
    long long int second= min(n-a,n-b);
    long long int third = max(1-a,b-n);
    long long int fourth = min(n-a,b-1);

    //レンダリング
    for(long long int i=p;i<=q;i++){
        for(long long int j=r;j<=s;j++){
            if(i == j - b + a && (b + first <= j && j <= b + second) && (a + first <= i && i <= a + second)){
                cout << "#";
            }
            else if(i == -j + a + b && (b -fourth <= j && j <=b -third) && (a + third <= i && i <= a + fourth)){
                cout << "#";
            }
            else{
                cout << ".";
            }

        }
        cout << "\n";
    }

    return 0;
}