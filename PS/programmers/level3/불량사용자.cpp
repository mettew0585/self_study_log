#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> ids[10];
bool checked[300];
int ans;

bool match(string id,string to_ban){
    if(id.size()!=to_ban.size())
        return false;
    for(int i=0;i<id.size();++i){
        if(to_ban[i]=='*')continue;
        if(id[i]!=to_ban[i])return false;
    }
    return true;
}

void make_ids(vector<string> user_id, vector<string> banned_id){
    for(int i=0;i<banned_id.size();++i){
        string to_ban=banned_id[i];
        for(int j=0;j<user_id.size();++j){
            string id=user_id[j];
            if(match(id,to_ban))
                ids[i].push_back(j);
        }
    }
}

int vec2bits(vector<int> v){
    int bits=0;
    for(int i=0;i<v.size();++i)
        bits|=(1<<v[i]);
    return bits;
}

void dfs(int k,vector<int>& pick,vector<bool>& chk,int size){
    if(k==size){
        int bits=vec2bits(pick);
        cout<<bits<<"\n";
        if(checked[bits])return;
        
        checked[bits]=true;
        ++ans;
        return;
    }
    
    for(int i=0;i<ids[k].size();++i){
        if(chk[ids[k][i]])continue;
        
        pick.push_back(ids[k][i]);
        chk[ids[k][i]]=true;
        dfs(k+1,pick,chk,size);
        pick.pop_back();
        chk[ids[k][i]]=false;
    }
}

int solution(vector<string> user_id, vector<string> banned_id) {
    make_ids(user_id,banned_id);
    
    vector<int> pick;
    vector<bool> chk(10,false);
    dfs(0,pick,chk,banned_id.size());
    
    return ans;
}
