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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == nullptr)return head;
        int count = 0;
        ListNode* dummyNode = new ListNode(0);
        dummyNode->next = head;
        ListNode* curHead = dummyNode;
        while(curHead->next != nullptr)
        {
            count++;
            curHead = curHead->next;
        }
        int count1 = count - n;
        if(count1 < 0)return head;
        curHead = dummyNode;
        while(count1--)
        {
            curHead = curHead->next;
        }
        ListNode* newNode = new ListNode;
        newNode = curHead->next;
        curHead->next = curHead->next->next;
        delete newNode;
        newNode = nullptr;
        return dummyNode->next;
    }
};