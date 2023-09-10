#include <string>
#include <vector>
#include <iostream>

using namespace std;

const int INF=21e8;

pair<int,int> cache[100'010];

void init(){
    for(int i=0;i<=100'000;++i)
        cache[i]={-1,-1};
}

pair<int,int> dp(int pnt){
    // first:다트던진횟수 second : 불, 싱글
    if(cache[pnt].first!=-1)return cache[pnt];
    if(pnt==0)return {0,0};
    
    pair<int,int> ret={INF,INF};
    
    //fire
    if(pnt-50>=0){
        pair<int,int> val=dp(pnt-50);
        ret={val.first+1,val.second+1};
    }
    for(int j=1;j<=3;++j){
        for(int i=20;i>=1;--i){
            if(pnt-j*i>=0){
                pair<int,int> val=dp(pnt-i*j);
                if(ret.first>val.first+1){
                    if(j==1)
                        ret={val.first+1,val.second+1};
                    else
                        ret={val.first+1,val.second};
                }
            }
        }
    }
    
    return cache[pnt]=ret;
}

vector<int> solution(int target) {
    init();
    pair<int,int> ans=dp(target);
    return {ans.first,ans.second};
}
