#include<bits/stdc++.h>
using namespace std;
struct ListNode
{
    int val;
    ListNode*next;
};

class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*>res;
        float length = 0;
        ListNode*ptr = head;
        while(ptr!=NULL)
        {
           length++;
           ptr = ptr->next;
        }
        ptr = head;
        while(length>0)
        {
            
            int count = ceil(length/k);
            length -= count;
            k--;
            ListNode*temp = NULL;
            if(ptr == head)
            temp = ptr;
            count--;
             while(count--)
             {
                ptr = ptr->next;
             }
             head = ptr->next;
             ptr->next = NULL;
             res.push_back(temp);
             ptr = head;
             
        }
        while(k--)
        {
            res.push_back(NULL);
        }
        return res;
    }
};