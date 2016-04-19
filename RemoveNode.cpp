
//题目描述：
//实现一个算法，删除单向链表中间的某个结点，假定你只能访问该结点。
//给定带删除的节点，请执行删除操作，若该节点为尾节点，返回false，否则返回true。


//解题思路：给定中间节点，无法知道前一个节点；想要删除该节点，可以先将后一个节点的value给当前节点的value；
//把后一个节点的next给当前节点的next；然后删除后一个节点即可。

/*
struct ListNode
{
    int val;
    struct ListNode *next;
    
    ListNode(int x)
      : val(x)
      ,next(NULL)
    {}
};*/

class Remove
{
public:
    bool removeNode(ListNode* pNode)
    {
        if(NULL == pNode->next)
            return false;
        else
        {
            ListNode* tmp = pNode->next;
            pNode->next = tmp->next;
            pNode->val = tmp->val;
         
            delete tmp;
         
            return true;
        }
    }
};



