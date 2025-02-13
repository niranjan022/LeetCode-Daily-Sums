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
    int GCD(int a,int b){
        int a1=a,b1=b;
        while(b1!=0){
            int temp=a1%b1;
            a1=b1;
            b1=temp;
        }
        return a1;
    }
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(head->next==NULL){
            return head;
        }
        ListNode* cur=head;
        ListNode* prev= nullptr;
        while(cur->next){
            prev=cur;
            cur=cur->next;
            int gcd=GCD(prev->val,cur->val);
            ListNode* newnode=new ListNode(gcd);
            newnode->next=prev->next;
            prev->next=newnode;
            prev=newnode;
        }
        return head;
    }
};