#include <string>
#include <vector>
#include <queue>

#define pii pair<int,int>

using namespace std;

const int INF=21e8;

//230907
//graph
//dijkstra  O(ElgV)

vector<pii> adj[210];

vector<int> dijkstra(int from){
    
    priority_queue<pii,vector<pii>,greater<pii>> pq;
    vector<int> dist(210,INF);
    
    pq.push({0,from});
    dist[from]=0;
    
    while(!pq.empty()){
        int cur_dist=pq.top().first;
        int cur_pos=pq.top().second;
        
        pq.pop();
        if(cur_dist>dist[cur_pos])
            continue;
        
        for(pii info : adj[cur_pos]){
            
            if(dist[info.second]>cur_dist+info.first){
                dist[info.second]=cur_dist+info.first;
                pq.push({cur_dist+info.first,info.second});
            }
        }
    }
    
    return dist;
}


int solve(int n,int s,int a,int b){
    int ret=INF;
    vector<int> dist1=dijkstra(s);
    vector<int> dist2=dijkstra(a);
    vector<int> dist3=dijkstra(b);
    
    for(int i=1;i<=n;++i){
        int sum=dist1[i]+dist2[i]+dist3[i];
        ret=min(ret,sum);
    }
    
    return ret;
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = 0;
    
    //preprocess
    for(vector<int> info : fares){
        int c=info[0],d=info[1],f=info[2];
        adj[c].push_back({f,d});
        adj[d].push_back({f,c});
    }
    
    answer=solve(n,s,a,b);
    
    return answer;
}
