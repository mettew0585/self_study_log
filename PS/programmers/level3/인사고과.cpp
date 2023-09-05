//230905
//https://school.programmers.co.kr/learn/courses/30/lessons/152995
//sorting

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

const int INF=21e8;
const int MAX=100'010;

//O(N)

pair<int,int> wanho;
int max_scr[MAX];//index : 근태 점수 , value: index보다 큰 근태점수를 가진 학생들 중에 제일 큰 동료평가점수
vector<pair<int,int>> filtered;

bool cmp(vector<int> scr1,vector<int> scr2){
    if(scr1[0]!=scr2[0])
        return scr1[0]<scr2[0];
    return scr1[1]<scr2[1];
}

bool cmp2(pair<int,int> scr1,pair<int,int> scr2){
    return scr1.first+scr1.second>scr2.first+scr2.second;
}

void check_max_scr(int st,int en,int val){
    for(int i=st;i<=en;++i)
        max_scr[i]=val;
}

void calc_max_scr(const vector<vector<int>>& scores){
    
    int sz=scores.size();
    int prev_scr1=100'001,max_scr2=-1;
    for(int i=sz-1;i>=0;--i){
        max_scr2=max(max_scr2,scores[i][1]);
        if(prev_scr1!=scores[i][0]){
            check_max_scr(scores[i][0],prev_scr1-1,max_scr2);
        }
        prev_scr1=scores[i][0];
    }
    check_max_scr(0,scores[0][0]-1,max_scr2);
}

void filter(const vector<vector<int>>& scores){
    int max_scr1=scores.back()[0];
    
    for(int i=0;i<scores.size();++i)
        if(scores[i][0]==max_scr1 || scores[i][1] >= max_scr[scores[i][0]+1])
            filtered.push_back({scores[i][0],scores[i][1]});
}

bool is_wanho_filtered(){
    for(int i=0;i<filtered.size();++i){
        if(filtered[i].first==wanho.first&&filtered[i].second==wanho.second)
            return false;
    }
    
    return true;
}

int calc_rank_of_wanho(){
    int wanho_sum=wanho.first+wanho.second;
    for(int i=0;i<filtered.size();++i){
        if(filtered[i].first+filtered[i].second==wanho_sum)
            return i+1;
    }
}


int solution(vector<vector<int>> scores) {
    
    wanho={scores[0][0],scores[0][1]};
    sort(scores.begin(),scores.end(),cmp);//정렬
    calc_max_scr(scores);
    filter(scores);
    if(is_wanho_filtered())
        return -1;
    sort(filtered.begin(),filtered.end(),cmp2);
    
    
    return calc_rank_of_wanho();
}
