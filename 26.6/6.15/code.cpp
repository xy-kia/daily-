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
    ListNode* midN(ListNode* head){
        ListNode* slow = head, * fast = head;
        while(fast && fast -> next){
            slow = slow -> next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode* rList(ListNode* head){
        ListNode* pre = nullptr, *cur = head;
        while(cur) {
            ListNode* nt = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nt;
        }
        return pre;
    }
    int pairSum(ListNode* head) {
        ListNode* mid = midN(head);
        ListNode* head2 = rList(mid);
        int ans = 0;
        while(head2){
            ans = max(ans, head->val + head2->val);
            head = head->next;
            head2 = head2->next;
        }
        return ans;
    }
};