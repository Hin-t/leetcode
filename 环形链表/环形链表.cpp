/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
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
/*
    暴力破解，傻瓜方法
 */
// ListNode *detectCycle(ListNode *head)
// {
//     ListNode *pre = head;
//     ListNode *curr = head;
//     ListNode *move = head;
//     if (head == nullptr || head->next == nullptr)
//     {
//         return nullptr;
//     }
//     else
//     {
//         while (curr != nullptr && curr->next != nullptr)
//         {
//             pre = pre->next;
//             curr = curr->next->next;
//             if (pre == curr)
//             {
//                 if (move == curr)
//                 {
//                     return move;
//                 }
//                 else
//                 {
//                     while (move != curr)
//                     {
//                         curr = curr->next;
//                         while (curr != pre)
//                         {
//                             if (curr == move)
//                             {
//                                 return move;
//                             }
//                             curr = curr->next;
//                         }
//                         move = move->next;
//                     }
//                 }
//             }
//             if (curr == nullptr || curr->next == nullptr)
//             {
//                 return nullptr;
//             }
//         }
//         return nullptr;
//     }
// }

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

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
                if (move == curr)
                {
                    return move;
                }
                else
                {
                    while (move != curr)
                    {
                        move = move->next;
                        curr = curr->next;
                        if (move == curr)
                        {
                            return move;
                        }
                    }
                }
            }
            if (curr == nullptr || curr->next == nullptr)
            {
                return nullptr;
            }
        }

        return nullptr;
    }
}
int main()
{

    ListNode *d = new ListNode(-4);
    ListNode *c = new ListNode(0, d);
    ListNode *b = new ListNode(2, c);
    ListNode *a = new ListNode(3, b);

    d->next = b;

    detectCycle(a);

    free(a);
    free(b);
    free(c);
    free(d);
}
