//Trie
//dfs

class Solution {
public:

    vector<vector<string>> ans;

    struct trie_node{
        bool terminal;
        trie_node* children[26];

        trie_node(){
            terminal=false;
            for(int i=0;i<26;++i)children[i]=NULL;
        }

        void insert(const string& word,int idx){
            if(idx==word.size()){
                terminal=true;
                return;
            }

            int next=word[idx]-'a';
            if(children[next]==NULL)
                children[next]=new trie_node();
            children[next]->insert(word,idx+1);
        }

        trie_node* next_node(char c){
            int next=c-'a';

            if(children[next]==NULL)return NULL;
            else return children[next];
        }
    };

    void dfs(const string& s,int idx,vector<string>& v,trie_node* head){

        if(idx==s.size()){
            ans.push_back(v);
            return;
        }

        trie_node* cur=head;
        vector<pair<int,trie_node*>> ptr_v;
        for(int i=idx;i<s.size();++i){
            cur=cur->next_node(s[i]);
            if(cur==NULL)break;
            if(cur->terminal)
                ptr_v.push_back({i,cur});
        }
        
        for(pair<int,trie_node*> idx_ptr:ptr_v){
            v.push_back(s.substr(idx,idx_ptr.first+1-idx));
            dfs(s,idx_ptr.first+1,v,head);
            v.pop_back();
        }
        
    }
    
    string concat(vector<string> v){
        string ret;
        for(int i=0;i<v.size();++i){
            ret+=v[i];
            if(i!=v.size()-1)ret+=" ";
        }
        return ret;
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string> answer;
        trie_node* head;
        head=new trie_node();

        for(string word:wordDict){
            head->insert(word,0);
        }

        vector<string> v;
        dfs(s,0,v,head);

        for(vector<string> s_v :ans)
            answer.push_back(concat(s_v));
        
        return answer;
    }
};
