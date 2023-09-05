//230905
//https://school.programmers.co.kr/learn/courses/30/lessons/150367
//divide and conquer

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string ll2binary(long long n){
    // long long -> 이진수
    //2^N - 1 의 형식으로
    string ret;
    for(int i=0;i<64;++i){
        if(n==0)
            break;
        else if(n&1)
            ret.push_back('1');
        else
            ret.push_back('0');
        n>>=1;
    }
    int len=ret.size();
    if(len==2)
        ret.push_back('0');
    else if(len>3&&len<7)
        for(int i=0;i<7-len;++i)
            ret.push_back('0');

    else if(len>7&&len<15)
        for(int i=0;i<15-len;++i)
            ret.push_back('0');
    
    else if(len>15&&len<31)
        for(int i=0;i<31-len;++i)
            ret.push_back('0');
    
    else if(len>31&&len<63)
        for(int i=0;i<63-len;++i)
            ret.push_back('0');
    
    reverse(ret.begin(),ret.end());
    return ret;
}

bool all_zero(const string& s,int st,int en){
    for(int i=st;i<=en;++i)
        if(s[i]!='0')
            return false;
    return true;
}

bool can_be_expressed(const string& s,int st,int en){
    //divide and conquer

    if(st==en)
        return true;
    
    int mid=(st+en)/2;
    
    if(s[mid]=='0')
        return all_zero(s,st,en);
    else
        return can_be_expressed(s,st,mid-1)&&can_be_expressed(s,mid+1,en);
}

vector<int> solution(vector<long long> numbers) {
    vector<int> answer;
    
    for(long long n:numbers){
        string s=ll2binary(n);
        bool result=can_be_expressed(s,0,s.size()-1);
        answer.push_back(result);
    }
    return answer;
}
