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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int ci=0;
        ListNode* x=l1;
        ListNode* y=l2;
        ListNode* pre=new ListNode();
        ListNode* ans=pre;
        while(x!=nullptr || y!= nullptr || ci!=0){
            int sum=ci;
            if(x!=nullptr){ 
                sum+=x->val;
                 x=x->next;
            }
            if(y!=nullptr){
                sum+=y->val;
                y=y->next;
            }
            ci=sum/10;
            int now=sum%10;
            pre->next=new ListNode(now);
            pre=pre->next;
        }
        return ans->next;
    }
};