/* 
    题目描述：给你一个链表的头节点 head 和一个整数 val ，请你删除链表中所有满足 Node.val == val 的节点，并返回 新的头节点 。
 */

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

ListNode *removeElements(ListNode *head, int val)
{
    ListNode *pre = new ListNode(-1, head);
    ListNode *rear = head;
    ListNode *res = pre;
    while (rear != nullptr)
    {
        while (rear != nullptr && rear->val == val)
        {
            rear = rear->next;
        }
        pre->next = rear;
        pre = pre->next;
        if (rear != nullptr)
        {
            rear = rear->next;
        }
    }
    return res->next;
}
int main()
{
    return 0;
}