//230913
//tree

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

const int MAX=300'010;

int par[MAX];
vector<int> adj[MAX],children[MAX],depth[MAX];
vector<bool> vis(MAX,false);

int max_depth;

void dfs(int cur,int d){
    
    max_depth=max(max_depth,d);
    
    vis[cur]=true;
    depth[d].push_back(cur);
    
    for(int i=0;i<adj[cur].size();++i){
        int nxt=adj[cur][i];
        if(vis[nxt])
            continue;
        children[cur].push_back(nxt);
        par[nxt]=cur;
        dfs(nxt,d+1);
    }
}

void make_tree(vector<vector<int>> edges){
    
    for(vector<int> a:edges){
        adj[a[0]].push_back(a[1]);
        adj[a[1]].push_back(a[0]);
    }
    
    dfs(0,0);
}

long long solve(vector<int> a){
    
    long long ans=0;
    vector<long long> val;
    for(int b:a)
        val.push_back(b);
    
    for(int i=max_depth;i>=1;--i){
        for(int j=0;j<depth[i].size();++j){
            int cur=depth[i][j];
            
            ans+=abs(val[cur]);
            val[par[cur]]+=val[cur];
            val[cur]=0;
        }
        
    }
    
    if(val[0]!=0)return -1;
    
    return ans;
}


long long solution(vector<int> a, vector<vector<int>> edges) {
    long long answer = -2;
    
    make_tree(edges);
    answer=solve(a);
    
    return answer;
}
