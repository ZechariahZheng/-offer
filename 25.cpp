//第一步，复制复杂指针的label和next
void CloneNodes(RandomListNode* pHead)
{
    RandomListNode* pNode = pHead;
    while (pNode != NULL)
    {
        RandomListNode* pCloned = new RandomListNode(0);
        pCloned->label = pNode->label;
        pCloned->next = pNode->next;
        pCloned->random = NULL;
        
        pNode->next = pCloned;
        pNode = pCloned->next;
    }
}

//第二步，处理复杂指针的random
void ConnectSiblingNodes(RandomListNode* pHead)
{
    RandomListNode* pNode = pHead;
    while (pNode != NULL)
    {
        RandomListNode* pCloned = pNode->next;
        if (pNode->random != NULL)
        {
            pCloned->random = pNode->random->next;
        }
        pNode = pCloned->next;
    }
}

/*第三步，拆分复杂指针*/
RandomListNode* ReconnectNodes(RandomListNode* pHead)
{
    RandomListNode* pNode = pHead;
    RandomListNode* pClonedHead = NULL;
    RandomListNode* pClonedNode = NULL;
    
    if (pNode != NULL)
    {
        pClonedHead = pClonedNode = pNode->next;
        pNode->next = pClonedHead->next;
        pNode = pNode->next;
    }
    
    while (pNode != NULL)
    {
        pClonedNode->next = pNode->next;
        pClonedNode = pClonedNode->next;
        pNode->next = pClonedNode->next;
        pNode = pNode->next;
    }
    return pClonedHead;
}

RandomListNode* Clone(RandomListNode* pHead)
{
    CloneNodes(pHead);
    ConnectSiblingNodes(pHead);
    return ReconnectNodes(pHead);
}