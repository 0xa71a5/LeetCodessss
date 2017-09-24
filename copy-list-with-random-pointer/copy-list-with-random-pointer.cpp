/**
题目描述
A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.
Return a deep copy of the list.
*/

/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if(head==NULL) return NULL;
    RandomListNode *cur = head;
    while(cur!=NULL)
    {
        RandomListNode * newNextNode = new RandomListNode(cur->label);
        newNextNode ->next = cur->next;
        newNextNode ->random = cur->random;
        RandomListNode * tmp = cur->next;
        cur->next = newNextNode;
        newNextNode->next = tmp;
        cur = cur->next->next;
    }
    RandomListNode *oCur = head;
    cur = head->next;
    while(cur!=NULL)
    {
        cur->next = cur->next?cur->next->next:NULL;
        cur->random = cur->random?cur->random->next:NULL;
        cur=cur->next;
    }
    return head->next;
    }
};