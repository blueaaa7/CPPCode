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
    ListNode* swapPairs(ListNode* head) {
        if(head == nullptr)return head;
        ListNode* dummyNode = new ListNode(0);
        dummyNode->next = head;
        ListNode* curHead = dummyNode;
        while(curHead->next != nullptr && curHead->next->next != nullptr)
        {
            ListNode* tmp = curHead->next;
            ListNode* tmp1 = curHead->next->next->next;
            curHead->next = curHead->next->next;
            curHead->next->next = tmp;
            curHead->next->next->next = tmp1;

            curHead =  curHead->next->next;
        }
        return dummyNode->next;
    }
};