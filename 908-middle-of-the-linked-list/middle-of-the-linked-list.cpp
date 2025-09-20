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
    ListNode* middleNode(ListNode* head) {
         vector<ListNode*> arr;

   ListNode* temp = head;
   while( temp != NULL){
    arr.push_back(temp);
    temp = temp->next;
   }
   int mid = arr.size()/2;

        return arr[mid];

    }
};