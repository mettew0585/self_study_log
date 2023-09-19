//hard
//two pointer

class Solution {
public:
    int trap(vector<int>& height) {
        
        int left=0,right=0;
        int ans=0;
        int N=height.size();
        while(left<N){
            right=left+1;
            while(right<N&&height[left]>height[right])++right;
            if(right<N)
                for(int i=left+1;i<right;++i)ans+=(height[left]-height[i]);
            left=right;
        }
        
        left=N-1,right=N-1;
        while(right>=0){
            left=right-1;
            while(left>=0&&height[left]<=height[right])--left;
            if(left>=0){
                for(int i=right-1;i>left;--i)ans+=(height[right]-height[i]);
            }
            right=left;
        }

        return ans;
    }
};
