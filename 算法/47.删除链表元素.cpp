#include <iostream>
using namespace std;
//   Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

class Solution
{
public:
    ListNode *removeElements(ListNode *head, int val)
    {
        ListNode *NewHead = new ListNode();
        NewHead->next = head;
        ListNode *p = NewHead;
        while (p->next != nullptr)
        {
            if (p->next->val == val)
            {
                p->next = p->next->next;
            }
            else
            {
                p = p->next;
            }
        }
        head = NewHead->next;
        delete NewHead;
        return head;
    }
};

int main()
{
    ListNode l5(3);
    ListNode l4(4,&l5);
    ListNode l3(3,&l4);
    ListNode l2(2,&l3);
    ListNode l1(1,&l2);
      ListNode* cur = &l1;
    while (cur!= nullptr)
    {
        cout<< cur->val<<endl;
        cur= cur->next;
    }
    Solution _so;
    _so.removeElements(&l1,3);
    cur = &l1;
    while (cur!= nullptr)
    {
        cout<< cur->val<<endl;
        cur= cur->next;
    }
    
    return 0;
}