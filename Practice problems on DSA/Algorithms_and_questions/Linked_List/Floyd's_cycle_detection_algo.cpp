//https://leetcode.com/problems/linked-list-cycle-ii/
#include <iostream>
using namespace std;



  struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode*tort = head;
        ListNode*hare = head;

        while(hare != NULL && hare->next != NULL){
            hare = hare->next->next;
            tort = tort->next;
            
            if(hare == tort){
                hare = head;
                while(hare != tort){
                    hare = hare->next;
                    tort = tort-> next;
                
            }
            return hare;
           

        }
        

    }
        return NULL;
    
    }
};

int main() {
    return 0;
}

/*to remove the cycle from the given LL, just take the intersection point of the
from the above code and use it as reference to feed into a while loop
which has an iterator start from the intersection point and iterate it till
iterator->next != intersection. When the loop breaks the iterator would lie on
the node before the intersection and just set iterator->next == NULL, thus 
removing the cycle from the LL*/
