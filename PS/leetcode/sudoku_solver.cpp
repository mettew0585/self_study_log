//hard
//backtracking

#define pii pair<int,int>
#define Y first
#define X second

class Solution {
public:
    vector<vector<int>> board,ans;
    bool block_chk[3][3][10],row_chk[9][10],col_chk[9][10];
    vector<pii> empty_cells;

    void dfs(int k){
        if(k==empty_cells.size()){
            ans=board;
            return;
        }

        int y=empty_cells[k].Y,x=empty_cells[k].X;

        for(int i=1;i<=9;++i){
            if(block_chk[y/3][x/3][i]||row_chk[y][i]||col_chk[x][i])
                continue;
            
            board[y][x]=i;
            block_chk[y/3][x/3][i]=row_chk[y][i]=col_chk[x][i]=true;
            dfs(k+1);
            board[y][x]=0;
            block_chk[y/3][x/3][i]=row_chk[y][i]=col_chk[x][i]=false;
        }
    }

    void solveSudoku(vector<vector<char>>& brd) {

        board = vector<vector<int>> (9,vector<int>(9,0));
        
        //char to int
        for(int y=0;y<9;++y)
            for(int x=0;x<9;++x){
                if(brd[y][x]!='.'){
                    board[y][x]=brd[y][x]-'0';
                    block_chk[y/3][x/3][board[y][x]]=
                    row_chk[y][board[y][x]]=col_chk[x][board[y][x]]=true;
                }
                else{
                    board[y][x]=0;
                    empty_cells.push_back({y,x});
                }
            }
        
        dfs(0);

        for(int y=0;y<9;++y)
            for(int x=0;x<9;++x)
                brd[y][x]=ans[y][x]+'0';
    }
};
