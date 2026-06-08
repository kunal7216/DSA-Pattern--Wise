// merge k sorted linked lists and return it as one sorted linked list.
// leetcode problem link: https://leetcode.com/problems/merge-k-sorted-lists/

// Custom comparator class for priority_queue
// This makes the priority_queue behave like a MIN-HEAP
class mycompare
{
public:
    bool operator()(const ListNode *a, const ListNode *b)
    {
        // Return true if a should come AFTER b
        // Smaller value gets higher priority
        return a->val > b->val;
    }
};

class Solution
{
public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {

        // Dummy head node to simplify list construction
        ListNode *head = new ListNode(0);
        ListNode *temp = head;

        // Min-heap storing ListNode pointers
        priority_queue<ListNode *, vector<ListNode *>, mycompare> pq;

        // Push the head of each non-empty linked list into the heap
        for (int i = 0; i < lists.size(); i++)
        {
            if (lists[i] != NULL)
                pq.push(lists[i]);
        }

        // Extract the minimum element and build the merged list
        while (!pq.empty())
        {
            // Get the node with the smallest value
            ListNode *least = pq.top();
            pq.pop();

            // Attach it to the result list
            temp->next = least;
            temp = temp->next;

            // If the extracted node has a next node,
            // push it into the heap
            if (least->next)
                pq.push(least->next);
        }

        // Return the merged list (skip dummy node)
        return head->next;
    }
};

*****************************************************************Brute Solution********************************************************************************
  

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int> values;

        // Step 1: Store all values from all linked lists
        for (int i = 0; i < lists.size(); i++) {
            ListNode* temp = lists[i];

            while (temp != nullptr) {
                values.push_back(temp->val);
                temp = temp->next;
            }
        }

        // Step 2: Sort all values
        sort(values.begin(), values.end());

        // Step 3: Build new linked list
        ListNode* dummy = new ListNode(-1);
        ListNode* tail = dummy;

        for (int val : values) {
            tail->next = new ListNode(val);
            tail = tail->next;
        }

        return dummy->next;
    }
};
*****************************************************************Better Solution********************************************************************************


class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummy = new ListNode(-1);
        ListNode* tail = dummy;

        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val <= list2->val) {
                tail->next = list1;
                list1 = list1->next;
            } else {
                tail->next = list2;
                list2 = list2->next;
            }

            tail = tail->next;
        }

        if (list1 != nullptr) {
            tail->next = list1;
        }

        if (list2 != nullptr) {
            tail->next = list2;
        }

        return dummy->next;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) {
            return nullptr;
        }

        ListNode* result = nullptr;

        for (int i = 0; i < lists.size(); i++) {
            result = mergeTwoLists(result, lists[i]);
        }

        return result;
    }
};
*****************************************************************Optimal Solution********************************************************************************
 

class Solution {
public:
    struct Compare {
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, Compare> minHeap;

        // Step 1: Push head of every non-empty list
        for (ListNode* head : lists) {
            if (head != nullptr) {
                minHeap.push(head);
            }
        }

        ListNode* dummy = new ListNode(-1);
        ListNode* tail = dummy;

        // Step 2: Always take the smallest node
        while (!minHeap.empty()) {
            ListNode* smallest = minHeap.top();
            minHeap.pop();

            tail->next = smallest;
            tail = tail->next;

            if (smallest->next != nullptr) {
                minHeap.push(smallest->next);
            }
        }

        return dummy->next;
    }
};
