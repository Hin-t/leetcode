/*
    题目描述：你可以选择使用单链表或者双链表，设计并实现自己的链表。

    单链表中的节点应该具备两个属性：val 和 next 。val 是当前节点的值，next 是指向下一个节点的指针/引用。

    如果是双向链表，则还需要属性 prev 以指示链表中的上一个节点。假设链表中的所有节点下标从 0 开始。

    实现 MyLinkedList 类：

    MyLinkedList() 初始化 MyLinkedList 对象。
    int get(int index) 获取链表中下标为 index 的节点的值。如果下标无效，则返回 -1 。
    void addAtHead(int val) 将一个值为 val 的节点插入到链表中第一个元素之前。在插入完成后，新节点会成为链表的第一个节点。
    void addAtTail(int val) 将一个值为 val 的节点追加到链表中作为链表的最后一个元素。
    void addAtIndex(int index, int val) 将一个值为 val 的节点插入到链表中下标为 index 的节点之前。如果 index 等于链表的长度，那么该节点会被追加到链表的末尾。如果 index 比长度更大，该节点将 不会插入 到链表中。
    void deleteAtIndex(int index) 如果下标有效，则删除链表中下标为 index 的节点。
 */
#include <iostream>
using namespace std;

class MyLinkedList
{
public:
    struct ListNode
    {
        int val;
        ListNode *next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode *next) : val(x), next(next) {}
    };

    ListNode *myList = nullptr;
    MyLinkedList() { ListNode *myList = nullptr; }

    int get(int index)
    {
        int count = 0;
        ListNode *res = myList;
        while (res != nullptr)
        {
            if (count == index)
            {
                return res->val;
            }
            else
            {
                count++;
            }
            res = res->next;
        }
        return -1;
    }

    void addAtHead(int val)
    {
        ListNode *newNode = new ListNode(val);
        ListNode *rear = myList;
        if (rear == nullptr)
        {
            myList = newNode;
        }
        else
        {
            newNode->next = myList;
            myList = newNode;
        }
    }

    void addAtTail(int val)
    {
        ListNode *rear = myList;
        ListNode *newNode = new ListNode(val);
        if (rear != nullptr)
        {
            while (rear->next != nullptr)
            {
                rear = rear->next;
            }
            rear->next = newNode;
        }
        else
        {
            myList = newNode;
        }
    }

    void addAtIndex(int index, int val)
    {
        if (index == 0)
        {
            addAtHead(val);
        }
        else
        {
            int count = 0;
            ListNode *rear = myList;
            ListNode *newNode = new ListNode(val);
            while (rear != nullptr && count != index - 1)
            {
                count++;
                rear = rear->next;
            }
            if (count == index - 1 && rear != nullptr)
            {
                newNode->next = rear->next;
                rear->next = newNode;
            }
        }
    }

    void deleteAtIndex(int index)
    {
        ListNode *rear1 = myList;
        ListNode *rear2 = myList;
        int count = -1;
        while (rear1 != nullptr)
        {
            count++;
            rear1 = rear1->next;
        }
        if (index == count)
        {
            for (int i = 0; i < index - 1; i++)
            {
                rear2 = rear2->next;
            }
            rear2->next = nullptr;
        }
        if (index < count && index != 0)
        {
            for (int i = 0; i < index - 1; i++)
            {
                rear2 = rear2->next;
            }
            rear2->next = rear2->next->next;
        }
        if (index == 0 && myList != nullptr)
        {
            myList = myList->next;
        }
    }

    ListNode *detectCycle(ListNode *head)
    {
        ListNode *pre = head;
        ListNode *curr = head;
        ListNode *move = head;
        if (head == nullptr || head->next == nullptr)
        {
            return nullptr;
        }
        else
        {
            while (curr != nullptr && curr->next != nullptr)
            {
                pre = pre->next;
                curr = curr->next->next;
                if (pre == curr)
                {
                    break;
                }
                if (curr != nullptr && curr->next != nullptr)
                {
                    return nullptr;
                }
            }
            while (move != curr)
            {
                curr = curr->next;
                while (curr != pre)
                {
                    if (curr == move)
                    {
                        return move;
                    }
                    curr = curr->next;
                }
                move = move->next;
            }
            return nullptr;
        }
    }
};

int main()
{
    MyLinkedList *obj = new MyLinkedList();

    obj->addAtHead(1);
    obj->addAtTail(3);
    obj->addAtIndex(3, 2);
    
    obj->addAtTail(3);
    obj->addAtTail(2);
    obj->addAtTail(0);
    obj->addAtTail(-4);
}
/*
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */