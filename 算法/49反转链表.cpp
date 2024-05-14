
//   Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 

 #include <algorithm>
 #include <stack>
 using namespace std;
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr)return head;
        ListNode* curHead = nullptr; 
        while (head!=nullptr)
        {
            /* code */
            ListNode* newNode = new ListNode(head->val);
            newNode->next = curHead;
            curHead = newNode;
            head = head->next;
        }
        return curHead;
    }

    
};