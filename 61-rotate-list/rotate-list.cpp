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
        if( head == NULL || head->next == NULL){
            return head;
        }
        ListNode * tail = head;
        int len = 1;
        // count the no. of nodes
        while( tail->next != NULL ){
            tail = tail->next;
            len++;
        }
        //check wherther k is a multiple of len or not if so then
        k = k%len;
        if( k == 0){
            return head;
        }
  
        int count = len - k;
        ListNode * temp = head;
        // to reach the place from where you want to break the links
        for(int i = 1; i < count; i++ ){
            temp = temp->next;
        }
        ListNode* newHead = temp->next;
        temp->next = NULL;
        tail->next = head;
        return newHead;
        }
};