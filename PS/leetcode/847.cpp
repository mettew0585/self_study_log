//hard
//bit manipulation + graph

const int INF =21e8;

class Solution {
public:

    int cache[12][1<<12];
    int n,all_visited;

    void init(){
        for(int i=0;i<12;++i)
            for(int j=0;j<(1<<12);++j)
                cache[i][j]=-1;
    }

    int bfs(vector<vector<int>>& graph){
        queue<pair<int,int>> q;
        for(int i=0;i<n;++i){
            q.push({i,1<<i});
            cache[i][1<<i]=0;
        }

        while(!q.empty()){
            int cur=q.front().first,bits=q.front().second;
            q.pop();

            if(bits==all_visited)
                return cache[cur][bits];
            

            for(int nxt:graph[cur]){
                if(cache[nxt][bits|(1<<nxt)]!=-1)
                    continue;
                cache[nxt][bits|(1<<nxt)]=cache[cur][bits]+1;
                q.push({nxt,bits|(1<<nxt)});
            }
        }
        return -1;
    }
    int shortestPathLength(vector<vector<int>>& graph) {
        n=graph.size();
        all_visited=(1<<n)-1;
        init();
        int ans=bfs(graph);
        return ans;
    }
};
