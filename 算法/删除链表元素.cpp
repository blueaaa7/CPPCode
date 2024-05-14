
//   Definition for singly-linked list.
//   struct ListNode {
//       int val;
//       ListNode *next;
//      ListNode() : val(0), next(nullptr) {}
//     ListNode(int x) : val(x), next(nullptr) {}
//       ListNode(int x, ListNode *next) : val(x), next(next) {}
//   };
 
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* curHead = new ListNode(0);
        curHead->next = head;
        ListNode* cur = curHead;
        while (cur->next != nullptr)
        {
            if(cur->next->val == val)
            {
                ListNode* tmpNode = cur->next;
                cur->next = cur->next->next;
                delete tmpNode;
            }
            else
            {
                cur = cur->next;
            }
        }
        if(cur->next == nullptr && cur->val == val)
        {
            delete cur;
        }
        ListNode* res = curHead->next;
        delete curHead;
        curHead = nullptr;
        return res;
        
        
    }
};