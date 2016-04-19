
//题目描述：
//输入一个链表，输出该链表中倒数第k个结点

/*
struct ListNode
{
    int val;
    struct ListNode *next;
    
    ListNode(int x)
        :val(x)
        ,next(NULL)
    {}
};*/

class Solution
{
public:
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k)
    {
        ListNode* slow = pListHead;
        ListNode* fast = pListHead;
         
        while(fast && --k)
        {
            fast=fast->next;
        }
         
        if(k>0)
            return NULL;
         
        while(fast->next)
        {
            fast=fast->next;
            slow=slow->next;
        }
         
        return slow;
    }
};


