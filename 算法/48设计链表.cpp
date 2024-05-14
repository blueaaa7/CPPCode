class MyLinkedList
{
public:
    MyLinkedList()
    {
        head = new Node(0);
        size = 0;
    }

    int get(int index)
    {
        if (index >= size || index < 0)
            return -1;
        Node *curNode = head->next;
        while (index--)
        {
            curNode = curNode->next;
        }
        return curNode->val;
    }

    void addAtHead(int val)
    {
        Node *newNode = new Node(val);
        newNode->next = head->next;
        head->next = newNode;
        size++;
    }

    void addAtTail(int val)
    {
        Node *newNode = new Node(val);
        Node *cur = head;
        while (cur->next != nullptr)
        {
            cur = cur->next;
        }
        cur->next = newNode;
        size++;
    }

    void addAtIndex(int index, int val)
    {
        if (index > size || index < 0)
            return;
        Node *newNode = new Node(val);
        Node *cur = head;
        while (index--)
        {
            /* code */
            cur = cur->next;
        }
        newNode->next = cur->next;
        cur->next = newNode;
        size++;
    }

    void deleteAtIndex(int index)
    {
        if (index >= size || index < 0)
            return;
        Node* cur = head;
        while (index--)
        {
            /* code */
            cur = cur->next;
        }
        Node* tmp = cur->next;
        if(tmp != nullptr)
        {
            cur->next = tmp->next;
            delete tmp;
            tmp = nullptr;
             size--;
        }
       
    }

private:
    struct Node
    {
        int val;
        Node *next;
        Node(int va) : val(va), next(nullptr) {}
    };
    Node *head;
    int size;
};
