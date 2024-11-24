//https://leetcode.com/problems/reverse-nodes-in-k-group/
#include <iostream>
using namespace std;

struct ListNode {
    int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        //base call
    if(head == NULL) {
        return NULL;
    }
    ListNode* temp = head;
    int measure = 0;
    while (temp != NULL && measure < k) {
        temp = temp->next;
        measure++;
    }
    
    // If there are fewer than k nodes, return the list as is
    if (measure < k) {
        return head;
    }
    
    
    //step1: reverse first k nodes
    ListNode* next = NULL;
    ListNode* curr = head;
    ListNode* prev = NULL;
    int count= 0;
    
    


    while( curr != NULL && count < k ) {
        next = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = next;
        count++;
    }
    
    //step2: Recursion dekhlega aage ka 
    if(next != NULL) {
        head -> next = reverseKGroup(next,k);
    }
    
    //step3: return head of reversed list
    return prev;
    }
};