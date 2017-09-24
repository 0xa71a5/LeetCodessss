ListNode* removeNthFromEnd(ListNode *head, int n) {
    ListNode *kth=new ListNode (0);
    kth -> next =head; 
    ListNode *pHead=kth;

    while(head!=NULL)
    {
        if(n!=0)n--;
        else kth=kth->next;
        head=head->next;
    }
    if(kth!=NULL)
    {
        if(kth->next!=NULL)
            kth->next = kth->next->next;
    }   
    return pHead!=NULL?pHead->next:NULL;
}