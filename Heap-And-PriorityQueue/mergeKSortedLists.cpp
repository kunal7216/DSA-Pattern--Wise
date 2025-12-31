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
