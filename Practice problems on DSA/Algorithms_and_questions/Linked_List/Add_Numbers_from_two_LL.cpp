//https://leetcode.com/problems/add-two-numbers/
  
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
 
      ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 
#include <iostream>
using namespace std;



class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode*Head = new ListNode(-1);
        ListNode*head = Head;
        int remainder = 0;
        int insert = 0;
        int Total = 0;
        while(l1 != NULL || l2 != NULL){
            if(l2 ==NULL){
                Total = remainder + l1->val;
                insert = Total%10;
                remainder = Total/10;
                l1 = l1->next;
                ListNode* N = new ListNode(insert);
                head->next = N;
                head = N;
            }
            else if(l1 == NULL){
                Total = remainder + l2->val;
                insert = Total%10;
                remainder = Total/10;
                l2 = l2->next;
                ListNode* N = new ListNode(insert);
                head->next = N;
                head = N;
            }
            else{
                Total = remainder + l1->val + l2->val;
                insert = Total%10;
                remainder = Total/10;
                l1 = l1->next;
                l2 = l2->next;
                ListNode* N = new ListNode(insert);
                head->next = N;
                head = N;
            }
            
        }
        if(remainder != 0){
                Total = remainder ;
                insert = Total%10;
                remainder = Total/10;
                ListNode* N = new ListNode(insert);
                head->next = N;
                head = N;
            }
        return Head->next;
    }
};


int main() {
    return 0;
}