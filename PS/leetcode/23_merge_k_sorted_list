//hard
//linked list
//merge sort?

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
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* head=new ListNode(0);
        ListNode* new_list_back=head;
        while(1){
            int min_val=21e8,min_idx=-1;
            ListNode * min_node=NULL;
            for(int i=0;i<lists.size();++i){
                ListNode* cur=lists[i];
                if(cur==NULL)continue;
                if(min_val>cur->val){
                    min_val=cur->val;
                    min_node=cur;
                    min_idx=i;
                }
            }
            if(min_idx==-1)
                break;
            lists[min_idx]=lists[min_idx]->next;
            ListNode* new_node = new ListNode(min_val);
            new_list_back->next=new_node;
            new_list_back=new_node;
        }

        return head->next;
    }
};
