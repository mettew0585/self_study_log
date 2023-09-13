//230913
//tree?

#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

const int MAX=100'010;

//1e5  O(N)
int N;
int par[MAX];

string num2name[MAX];
unordered_map<string,int> name2num;


void make_tree(vector<string> enroll, vector<string> referral){
    
    name2num["-"]=0;
    num2name[0]="-";
    for(int i=0;i<enroll.size();++i){
        name2num[enroll[i]]=i+1;
        num2name[i+1]=enroll[i];
    }
    
    for(int i=0;i<referral.size();++i){
        int p=name2num[referral[i]];
        par[i+1]=p;
    }
}


vector<int> solve(vector<string> seller, vector<int> amount){
    
    vector<int> sum(MAX,0);
    
    for(int i=0;i<seller.size();++i){
        int cur=name2num[seller[i]];
        int money=amount[i]*100;
        int val=0;
        
        vector<pair<int,int>> v;
        while(money>0&&cur!=0){
            val=money/10;
            sum[cur]+=(money-val);
            cur=par[cur];
            money=val;
        }
        sum[0]+=val;
        
    }
    
    return vector<int> (sum.begin()+1,sum.begin()+N);
}

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    vector<int> answer;
    
    N=enroll.size()+1;
    make_tree(enroll,referral);
    answer=solve(seller,amount);
    
    for(auto a:answer)
        cout<<a<<" ";

    return answer;
}
