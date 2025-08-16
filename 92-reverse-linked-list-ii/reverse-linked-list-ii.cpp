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
    ListNode* reverseBetween(ListNode* head, int left, int right){
        //Base Cases: if head or its next is NULL and if both left and right index are same we do not need to reverse anything, we will simply return the head as it is
        if(head == NULL || head->next == NULL || left == right)
            return head;
        //Make a prev and curr pointer to iterate over the list
        ListNode* prev = NULL;
        ListNode* curr = head;
        //Make a i variable to count the index starting from 1
        int i = 1;
        //Set curr pointer to left index by iterating nodes one by one
        while(curr != NULL && i != left){
            prev = curr;
            curr = curr->next;
            i++;
        }
        //Make a new pointer  which will keep track the element of the list just before the ;eft index, we have all data in prev so make ptrToStart to prev, and prev to NULL as we need it further in our code to reverse the list
        ListNode* ptrToStart = prev;
        //make a start pointer for the end of reversed list so that we can access it and link remains and does not break
        ListNode* st = curr;
        prev = NULL;
        //Iterate until we set curr to right + 1 also reverse the list until this condition
        while(curr != NULL && i != right + 1){
            ListNode* nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
            i++;
        }
        //make a link between the left index(after reverse) and the list remaining after that
        st->next = curr;
        //Check if ptrTostart is null or not, if no, make its link with the prev(containing the whole reversed list), otherwise return prev only
        if(ptrToStart != NULL)
            ptrToStart->next = prev;            
        else
            return prev;
        //return the modified head of the list
        return head;
    }
};