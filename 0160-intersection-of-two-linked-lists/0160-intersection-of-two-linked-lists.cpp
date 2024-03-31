/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *collisionHead(ListNode *&head1 , ListNode *&head2 , int n){
        ListNode *temp1 = head1 ;
        ListNode *temp2 = head2 ;
        while(n--){
            temp1 = temp1 -> next;
        }
        while(temp1 != NULL){
            if(temp1 == temp2) return temp1;
            temp1 = temp1 -> next;
            temp2 = temp2 -> next;
        }
        return NULL;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    //    unordered_map <ListNode* , int> mpp;
    //    ListNode *temp = headA;
    //    while(temp != NULL){
    //     mpp[temp]++;
    //     temp = temp -> next;
    //    }
    //    temp = headB;
    //    while(temp != NULL){
    //     if(mpp.find(temp) != mpp.end()){
    //         return temp;
    //     }
    //     temp = temp -> next;
    //    }
    //    return NULL;

    // 2) Method  
    int cnt1 = 0, cnt2 = 0 ;
    ListNode *temp = headA;
    while(temp != NULL){
        cnt1++;
        temp = temp -> next;
    }
    temp = headB;
    while(temp != NULL){
        cnt2++;
        temp = temp -> next;
    }
    if(cnt1 == cnt2 ){
        return collisionHead(headA , headB , 0);
    }
    if(cnt1 > cnt2){
        return collisionHead(headA , headB , cnt1 - cnt2);
    }
    else{
        return collisionHead(headB , headA , cnt2 - cnt1);
    }

    }
};