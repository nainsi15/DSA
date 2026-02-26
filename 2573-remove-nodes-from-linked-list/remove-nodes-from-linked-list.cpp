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
    ListNode *reverse(ListNode* head){
        ListNode *prev = NULL;
        ListNode *temp = head;

        while(temp != NULL){
            ListNode * curr = temp->next;
            temp->next = prev;
            prev = temp;
            temp = curr;
        }
        return prev;
    }
    
    ListNode* removeNodes(ListNode* head) {
        head = reverse(head);
        int maxi = head->val;
        ListNode *temp = head;

        while(temp->next != NULL && temp != NULL){
            if(temp->next->val < maxi){
                temp->next = temp->next->next;
            }
            else{
                temp = temp->next;
                maxi = temp->val;
            }
        }
        return reverse(head);
    }
};