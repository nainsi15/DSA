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
    ListNode* deleteMiddle(ListNode* head) {
         if( head == NULL || head->next == NULL){
            return NULL;
        }
    ListNode *temp = head;
    int count = 0;

    while( temp != NULL){
        count++;
        temp = temp->next;
    }
    int res =(count/2);
    temp = head;

    for( int i = 1; i < res ; i++){
        temp = temp ->next;
    }
    temp->next = temp->next->next;
    return head;

    }
};