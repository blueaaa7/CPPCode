
//  Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(nullptr) {}
  };
 
 #include <unordered_set>
 using namespace std;
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == nullptr || headB == nullptr)return nullptr;
        unordered_set<ListNode*> unset;
        ListNode* cur = headA;
        while(cur != nullptr)
        {
            unset.insert(cur);
            cur = cur->next;
        }
        ListNode* curB = headB;
        while(curB != nullptr)
        {
            if(unset.count(curB))
            {
                return curB;
                break;
            }
            else
            {
                curB = curB->next;
            }   
        }
        return nullptr;
    }
};