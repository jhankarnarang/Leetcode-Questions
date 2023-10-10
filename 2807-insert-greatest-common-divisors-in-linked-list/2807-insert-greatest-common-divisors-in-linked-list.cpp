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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(head->next == NULL) return head;

        ListNode* list = head;

        ListNode* fast = list->next;

        while(list!=NULL && fast!=NULL) {

            int a = list->val;
            int b = fast->val;
            ListNode* temp = new ListNode(gcd(a, b));
            
            temp->next = fast;

            list->next = temp;

            list = fast;
            fast = fast->next;
        }

        return head;
    }
};