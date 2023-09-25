//two pointer


#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> gems) {
    vector<int> answer;
    unordered_map<string,int> cnt;
    
    for(string word:gems)
        cnt[word]=0;
    
    int i=0,j=0,kind=0,all_cnt=cnt.size();
    int min_len=21e8,left=-1,right=-1;
    
    int c=0;
    
    while(i<gems.size()){
        ++c;
        string front=gems[i];
        while(j<gems.size()&&kind<all_cnt){
            string word=gems[j];
            if(cnt[word]==0)++kind;
            ++cnt[word];
            ++j;
        }
        if(kind==all_cnt&&min_len>(j-i+1)){
            min_len=j-i+1;
            left=i,right=j-1;
        }
        if(cnt[front]==1)--kind;
        --cnt[front];
        ++i;
    }
    
    answer.push_back(left+1);answer.push_back(right+1);
    
    return answer;
}
