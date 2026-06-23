#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class compare {
public:
    bool operator()(ListNode* a, ListNode* b) {
        return a->val > b->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        priority_queue<
            ListNode*,
            vector<ListNode*>,
            compare
        > pq;

        for(auto node : lists) {
            if(node)
                pq.push(node);
        }

        ListNode dummy(0);
        ListNode* tail = &dummy;

        while(!pq.empty()) {

            ListNode* curr = pq.top();
            pq.pop();

            tail->next = curr;
            tail = curr;

            if(curr->next)
                pq.push(curr->next);
        }

        return dummy.next;
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