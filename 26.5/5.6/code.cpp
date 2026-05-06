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
    ListNode* rotateRight(ListNode* head, int k) {
        // 边界处理：空链表/只有一个节点/ k=0 直接返回
        if (!head || !head->next || k == 0) return head;
        
        // 1. 统计链表长度，找到尾节点
        ListNode* last = head;
        int len = 1; // 初始值为1，因为至少有一个节点
        while (last->next != nullptr) {
            len++;
            last = last->next;
        }
        
        // 2. 消除无效旋转
        k %= len;
        if (k == 0) return head; // 旋转后和原链表一样
        
        // 3. 找到断点位置：从头往后走 len - k 步
        ListNode* now = head;
        for (int i = 1; i < len - k; i++) {
            now = now->next;
        }
        
        // 4. 调整指针
        ListNode* ans = now->next; // 新的头节点
        now->next = nullptr;      // 断开链表
        last->next = head;         // 尾节点连回原头节点
        
        return ans;
    }
};