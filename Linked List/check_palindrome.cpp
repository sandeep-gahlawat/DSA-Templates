#include<bits/stdc++.h>
using namespace std;


//  * Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
class Solution {
public:
    ListNode* reverse(ListNode* head){
        ListNode* current = head;
        ListNode* prev = NULL;
        ListNode* next = NULL;
        
        while(current){
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        
        return prev;
    }
    
    bool isPalindrome(ListNode* head) {
        
        if(head==NULL || head->next==NULL) return true; 
        if(head->next->next==NULL) {
            if(head->val == head->next->val) return true; 
            else return false;
        }
        
        ListNode* slow = head;
        ListNode* fast = head;
        
        while(fast->next && fast->next->next) //finding middile node of linkedlist
        {
            slow = slow->next;
            fast = fast->next->next;   
        }
        
        ListNode* temp = reverse(slow->next);
        
         while(head!=NULL && temp!=NULL){   
            if(head->val != temp->val) return false;  
            head = head->next;
            temp = temp->next;
        }
         return true;
    }
   
};