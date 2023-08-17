#include <bits/stdc++.h>
using namespace std;

// leetcode link : https://leetcode.com/problems/sort-list/
//   Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *merge(ListNode *l1, ListNode *l2)
    {
        if (l1 == NULL)
            return l2;
        if (l2 == NULL)
            return l1;
        ListNode *root = NULL, *curr = NULL;
        if (l1->val <= l2->val)
        {
            root = l1;
            l1 = l1->next;
        }
        else
        {
            root = l2;
            l2 = l2->next;
        }
        curr = root;
        while (l1 != NULL && l2 != NULL)
        {
            if (l1->val <= l2->val)
            {
                curr->next = l1;
                l1 = l1->next;
                curr = curr->next;
            }
            else
            {
                curr->next = l2;
                l2 = l2->next;
                curr = curr->next;
            }
        }
        if (l1 != NULL)
        {
            curr->next = l1;
        }
        if (l2 != NULL)
        {
            curr->next = l2;
        }

        return root;
    }

    ListNode *middle(ListNode *head, ListNode *tail)
    {
        if (head == tail)
            return head;
        ListNode *s = head, *f = head;
        while (f != tail && f->next != tail)
        {
            f = f->next->next;
            s = s->next;
        }
        return s;
    }

    ListNode *mergeSort(ListNode *head, ListNode *tail)
    {
        if (head == tail)
        {
            return new ListNode(head->val);
        }

        ListNode *mid = middle(head, tail);
        ListNode *sfh = mergeSort(head, mid);
        ListNode *ssh = mergeSort(mid->next, tail);
        ListNode *sorted = merge(sfh, ssh);
        return sorted;
    }

    ListNode *sortList(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
            return head;
        ListNode *tail = NULL, *curr = head;
        while (curr != NULL)
        {
            tail = curr;
            curr = curr->next;
        }
        return mergeSort(head, tail);
    }
};