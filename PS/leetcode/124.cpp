//Hard
//Tree+DP
//O(N)

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {

    TreeNode* ptrs[30010];
    unordered_map<TreeNode*,int> ptr2idx;
    int lc[30010],rc[30010];
    int cache[30010];
    int idx=0;

    int dp(TreeNode* cur){
        int tmp=idx++;
        ptrs[tmp]=cur;
        ptr2idx[cur]=tmp;
        int val =cur->val,max_child=0;

        if(cur->left!=NULL){
            max_child=max(max_child,dp(cur->left));
            lc[tmp]=ptr2idx[cur->left];
        }
        if(cur->right!=NULL){
            max_child=max(max_child,dp(cur->right));
            rc[tmp]=ptr2idx[cur->right];
        }
        return cache[tmp]=val+max_child;
    }

public:
    int maxPathSum(TreeNode* root) {

        int ans=-21e8;
        dp(root);

        for(int i=0;i<idx;++i){
            int val=ptrs[i]->val;
            if(lc[i]!=0 && cache[lc[i]]>0)val+=cache[lc[i]];
            if(rc[i]!=0 && cache[rc[i]]>0)val+=cache[rc[i]];
            ans=max(ans,val);
        }
        
        return ans;
    }
};
