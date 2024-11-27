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

    ListNode* Reverse (ListNode*&head){
        ListNode* curr = head;
        ListNode* prev = NULL;
     

        while(curr != NULL){
        ListNode* forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
        return prev;
    }

    bool isPalindrome(ListNode* head) {
        ListNode* mid = head;
        ListNode* fast = head;
        if (head == NULL){
            return true;
        }
        while(fast!= NULL && fast->next != NULL){
            fast = fast->next->next;
            mid = mid->next;
        }

        mid = Reverse(mid);

        ListNode* firstHalf = head;
while (mid != NULL) {
    if (firstHalf->val != mid->val) {
        return false;
    }
    firstHalf = firstHalf->next;
    mid = mid->next;
}

        return true;

    }
};

int main() {
    return 0;
}