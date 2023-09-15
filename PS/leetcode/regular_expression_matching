//hard
//linked list
//O(N)


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
typedef ListNode ListNode;

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {

        ListNode* cur=head,*nxt=head;
        ListNode* new_head=new ListNode(-1);
        ListNode* prev_node=new_head;

        while(1){
            vector<int> v;
            int sz=0;
            for(int i=0;i<k && cur!=NULL;++i){
                v.push_back(cur->val);
                cur=cur->next;
                ++sz;
            }
            if(sz<k){
                if(!v.empty()){
                    ListNode* tmp=new ListNode(v[0]);
                    prev_node->next=tmp;
                    for(int i=1;i<v.size();++i){
                        ListNode* new_node=new ListNode(v[i]);
                        tmp->next=new_node;
                        tmp=new_node;
                    }
                }
                break;
            }

            ListNode* tmp=new ListNode(v[k-1]);
            prev_node->next=tmp;
            for(int i=k-2;i>=0;--i){
                ListNode* new_node=new ListNode(v[i]);
                tmp->next=new_node;
                tmp=new_node;
            }
            prev_node=tmp;
        }

        return new_head->next;
    }
};
