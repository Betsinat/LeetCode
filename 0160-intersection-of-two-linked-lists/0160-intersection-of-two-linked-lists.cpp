/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *tempA = new ListNode();
        ListNode* tempB = new ListNode();
        tempA = headA;
        tempB = headB;
        while(tempA != nullptr){
            while(tempB != nullptr){
                if(tempA == tempB) return tempA;
                tempB = tempB -> next;
            }
            tempA= tempA->next;
            tempB= headB;
        }
              return nullptr;
        
    }
};