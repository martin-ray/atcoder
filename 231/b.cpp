#include<iostream>
#include<vector>
#include<queue>
#include<map>

int main(void){

    int n;
    std::map<std::string,int> s;
    std::string tmp;
    int max = 0;


    std::cin >> n;

    for(int i=0;i<n;i++){
        std::cin >> tmp;
        s[tmp]++;
    }

    for(auto itr=s.begin();itr != s.end(); itr++){

        if(itr->second > max){
            max = itr->second;
            tmp = itr->first;
        }

    }

    std::cout << tmp << std::endl;

    return 0;

    
}