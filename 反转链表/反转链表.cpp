#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/* ListNode *headInsert(ListNode *list, int val)
{
    ListNode *newHead = new ListNode(-1, list);
    ListNode *newNode = new ListNode(val);
    newNode->next = newHead->next;
    newHead->next = newNode;
    return newHead->next;
}
ListNode *reverseList(ListNode *head)
{
    ListNode *rear = head;
    ListNode *mid = head;
    ListNode *newList = new ListNode(-1, head);
    if (rear == nullptr)
    {
        return nullptr;
    }
    while (rear->next != nullptr)
    {
        head = headInsert(head, rear->next->val);
        rear = rear->next;
    }
    mid->next = nullptr;
    return newList->next;
} */

ListNode *reverseList(ListNode *head)
{
    ListNode *pre = nullptr;
    ListNode *curr = head;
    while (curr)
    {
        ListNode *temp = curr->next;
        curr->next = pre;
        pre = curr;
        curr = temp;
    }
    return pre;
}
int main()
{
    ListNode *ls = new ListNode(0);
    ListNode *rear = ls;
    for (int i = 1; i < 6; i++)
    {
        ListNode *node = new ListNode(i);
        rear->next = node;
        rear = rear->next;
    }
    ListNode *test = ls->next;
    ListNode *re = reverseList(ls);

    return 0;
}