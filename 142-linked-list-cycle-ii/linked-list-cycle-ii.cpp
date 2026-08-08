class Solution {
public:
    ListNode *detectCycle(ListNode* head) { 
        ListNode *slow = head;
        ListNode *fast = head;
        bool isCycle = false;

        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast) isCycle = true; 
            if(isCycle) break;
        }

        if(!isCycle) return NULL;

        slow = head;
        while(slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }

        return slow;
    }
};