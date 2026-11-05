
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {

        if (head == NULL)
            return head;

        ListNode* slow = head;
        ListNode* fast = head->next;

        while (fast != NULL) {

            if (slow->val == fast->val) {
                fast = fast->next;
                slow->next = fast;
            }
            else {
                slow = fast;
                fast = fast->next;
            }
        }

        return head;
    }
};
