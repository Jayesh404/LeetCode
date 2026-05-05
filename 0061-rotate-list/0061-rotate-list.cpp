/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(k==0) return head;
        if(head==NULL) return NULL;
        int n=1;
        ListNode* temp=head;
        while(temp->next!=NULL){
            n++;
            temp=temp->next;
        }
        temp->next=head;
        temp=head;
        k=k%n;
        ListNode* newhead=NULL;

        for(int i=1;i<n-k;i++){
            temp=temp->next;
        }
        newhead=temp->next;
        temp->next=NULL;
        return newhead;
    }
};