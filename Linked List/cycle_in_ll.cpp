#include<bits/stdc++.h>
using namespace std;

//aproach1 => connect every node with dummy node if any node repeats that is connected with dummy node it means it coantain cycle

//approach 2 using hashing
//  * Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
 
 //approach 3 using 2 pointers
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head==NULL)
            return false;
        ListNode *slow = head,*fast = head;
        while(fast->next!=NULL && fast->next->next!=NULL)
        {
           slow = slow->next;
            fast = fast->next->next;
            if(slow==fast)
                return true;
        }
        return false;
        
    }
};