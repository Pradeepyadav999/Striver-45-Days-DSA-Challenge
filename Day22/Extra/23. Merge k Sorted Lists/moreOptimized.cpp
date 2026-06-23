// Divide and Conquer (Best)
#include <iostream>
#include <vector>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:

    ListNode* mergeTwo(ListNode* l1, ListNode* l2) {

        ListNode dummy(0);
        ListNode* tail = &dummy;

        while(l1 && l2) {

            if(l1->val < l2->val) {
                tail->next = l1;
                l1 = l1->next;
            }
            else {
                tail->next = l2;
                l2 = l2->next;
            }

            tail = tail->next;
        }

        if(l1) tail->next = l1;
        if(l2) tail->next = l2;

        return dummy.next;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {

        if(lists.empty())
            return NULL;

        int interval = 1;

        while(interval < lists.size()) {

            for(int i = 0;
                i + interval < lists.size();
                i += interval * 2) {

                lists[i] =
                mergeTwo(
                    lists[i],
                    lists[i + interval]
                );
            }

            interval *= 2;
        }

        return lists[0];
    }
};

int main() {
    Solution sol;
    vector<ListNode*> lists;
    // Create some linked lists and add them to 'lists'
    // For example:
    ListNode* list1 = new ListNode(1);
    list1->next = new ListNode(4);
    list1->next->next = new ListNode(5);

    ListNode* list2 = new ListNode(1);
    list2->next = new ListNode(3);
    list2->next->next = new ListNode(4);

    ListNode* list3 = new ListNode(2);
    list3->next = new ListNode(6);

    lists.push_back(list1);
    lists.push_back(list2);
    lists.push_back(list3);

    ListNode* mergedHead = sol.mergeKLists(lists);

    // Print the merged linked list
    while (mergedHead) {
        cout << mergedHead->val << " ";
        mergedHead = mergedHead->next;
    }
    cout << endl;

    return 0;
}