#include <bits/stdc++.h>
using namespace std;

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
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        ListNode *head = nullptr;
        ListNode *tail = nullptr;
        while (list1 != nullptr && list2 != nullptr)
        {
            if (list1->val < list2->val)
            {
                cerr << "took l1" << endl;
                if (!head)
                {
                    head = list1;
                    tail = list1;
                }
                else
                {
                    tail->next = list1;
                    tail = list1;
                }
                list1 = list1->next;
            }
            else
            {
                cerr << "took l2" << endl;
                if (!head)
                {
                    head = list2;
                    tail = list2;
                }
                else
                {
                    tail->next = list2;
                    tail = list2;
                }
                list2 = list2->next;
            }
        }
        while (list1 != nullptr)
        {
            cerr << "rem: took l1" << endl;
            if (!head)
            {
                head = list1;
                tail = list1;
            }
            else
            {
                tail->next = list1;
                tail = list1;
            }
            list1 = list1->next;
        }
        while (list2 != nullptr)
        {
            cerr << "rem: took l2" << endl;
            if (!head)
            {
                head = list2;
                tail = list2;
            }
            else
            {
                tail->next = list2;
                tail = list2;
            }
            list2 = list2->next;
        }
        return head;
    }
};

ListNode *createListNode(int n)
{
    ListNode *head = nullptr, *tail = nullptr;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        ListNode *newNode = new ListNode(x);
        if (!head)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }
    return head;
}

void printList(ListNode *head)
{
    ListNode *current = head;
    while (current)
    {
        cout << current->val << " ";
        current = current->next;
    }
    cout << endl;
}

int main()
{
    Solution sol;
    int n1, n2;
    cin >> n1 >> n2;
    ListNode *list1 = createListNode(n1);
    ListNode *list2 = createListNode(n2);
    ListNode *mergedList = sol.mergeTwoLists(list1, list2);
    printList(mergedList);
}