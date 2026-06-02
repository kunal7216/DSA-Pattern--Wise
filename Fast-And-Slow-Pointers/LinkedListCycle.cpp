
****************************************************************************Brute Solution**************************************************************************
    /**
 * Definition for singly-linked list.
 */
class ListNode {
public:
    int val;
    ListNode *next;

    ListNode(int x) {
        val = x;
        next = NULL;
    }
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* curr = head;

        // Pick each node one by one
        while (curr != NULL) {
            ListNode* temp = curr->next;

            // Check whether curr appears again later
            while (temp != NULL) {
                if (temp == curr) {
                    return true;
                }

                temp = temp->next;
            }

            curr = curr->next;
        }

        return false;
    }
};
****************************************************************************Better Solution**************************************************************************
    #include <unordered_set>
using namespace std;

/**
 * Definition for singly-linked list.
 */
class ListNode {
public:
    int val;
    ListNode *next;

    ListNode(int x) {
        val = x;
        next = NULL;
    }
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode*> visited;

        ListNode* curr = head;

        while (curr != NULL) {
            // If this node was already visited, cycle exists
            if (visited.find(curr) != visited.end()) {
                return true;
            }

            // Mark current node as visited
            visited.insert(curr);

            // Move to next node
            curr = curr->next;
        }

        // Reached NULL, so no cycle
        return false;
    }
};
******************************************************************************Optimal Solution************************************************************************

class Solution
{
public:
    bool hasCycle(ListNode *head)
    {

        // Initialize fast pointer at the head of the linked list
        ListNode *fast = head;

        // Initialize slow pointer at the head of the linked list
        ListNode *slow = head;

        // Traverse the list while fast pointer and its next node exist
        while (fast != nullptr && fast->next != nullptr)
        {

            // Move fast pointer two steps ahead
            fast = fast->next->next;

            // Move slow pointer one step ahead
            slow = slow->next;

            // If fast and slow meet at the same node,
            // a cycle exists in the linked list
            if (fast == slow)
            {
                return true;
            }
        }

        // If fast reaches the end of the list,
        // no cycle exists
        return false;
    }
};


// using flyod's Tortoise and Hare algorithm
