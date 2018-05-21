#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
            val(x), next(NULL) {
    }
};

/*输入两个单调递增的链表，输出两个链表合成后的链表，当然我们需要合成后的链表满足单调不减规则。*/

/*思路：
首先确定输出链表的头result为两个链表头中较小的一个，然后不断比较，把输入两个链表中较小的依次插入输出链表尾部
故需要一个结点指针end指向输出链表的尾结点*/

ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
{
    ListNode *result, *end;     //result为输出链表头，end为输出链表尾
    if (pHead1 == NULL)
        return pHead2;
    if (pHead2 == NULL)
        return pHead1;
    
    /*确定链表头*/
    if (pHead1->val <= pHead2->val)
    {
        result = pHead1;
        pHead1 = pHead1->next;
    }
    else
    {
        result = pHead2;
        pHead2 = pHead2->next;
    }
    end = result;
    
    /*遍历两个链表，直到两个链表中有一个为空*/
    while (pHead1!=NULL && pHead2!=NULL)
    {
        /*将较小的元素插入输出链表的尾部*/
        if (pHead1->val <= pHead2->val)
        {
            end->next = pHead1;
            pHead1 = pHead1->next;
            end = end->next;
        }
        else
        {
            end->next = pHead2;
            pHead2 = pHead2->next;
            end = end->next;
        }
    }
    
    /*两个链表中不为空的那一个直接将值加入尾部*/
    if (pHead1 == NULL)
        end->next = pHead2;
    else
        end->next = pHead1;
    return result;
}

int main()
{
    
}