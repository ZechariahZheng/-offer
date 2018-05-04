#include <iostream>
#include <list>

using namespace std;

/*在一个排序的链表中，存在重复的结点，请删除该链表中重复的结点，重复的结点不保留，返回链表头指针。 
例如，链表1->2->3->3->4->4->5 处理后为 1->2->5*/

/*思路：
使用list存下所有不相同的变量，
之后遍历一次重新指向新的地址*/

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};

ListNode* deleteDuplication(ListNode* pHead)
{
    if (pHead == NULL)
        return pHead;
    
    list<ListNode*> tmp;      //保存仅出现一次的结点
    list<ListNode*>::iterator it;
    bool Exist = false;
    int tmpVal = 0;
    
    while (pHead != NULL)
    {
        Exist = false;
        tmpVal = pHead->val;
        for (it = tmp.begin(); it != tmp.end(); it++)
        {
            /*如果存在，删除该节点*/
            if (tmpVal == (*it)->val)
            {
                it = tmp.erase(it);
                Exist = true;
                break;
            }
        }
        if (Exist == false)
            tmp.push_back(pHead);
        pHead = pHead->next;
    }
    /*重新将所有节点指向新的地址*/
    ListNode *pre = NULL;
    if (tmp.size() != 0)
    {
        for (it = tmp.begin(); it != tmp.end(); it++)
        {
            if (pre != NULL)
                pre->next = *it;
            pre = *it;
        }
    }
    ListNode* result = NULL;
    if (tmp.size() != 0)
    {
        it = tmp.begin();
        result = *it;
    }
    
    return result;
}

int main()
{
    ListNode *tmp1 = new ListNode(1);
    ListNode *tmp2 = new ListNode(1);
    tmp1->next = tmp2;
    ListNode * pHead = deleteDuplication(tmp1);
    if (pHead == NULL)
		cout << "YES" << endl;
	system("pause");
    return 0;
}