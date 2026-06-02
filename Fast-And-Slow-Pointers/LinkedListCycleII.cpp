class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {

        // Initialize slow and fast pointers at the head of the linked list
        ListNode *slow = head;
        ListNode *fast = head;

        // Step 1: Detect whether a cycle exists using Floyd’s algorithm
        while (fast && fast->next)
        {

            // Move slow pointer one step at a time
            slow = slow->next;

            // Move fast pointer two steps at a time
            fast = fast->next->next;

            // If slow and fast meet, a cycle is detected
            if (slow == fast)
                break;
        }

        // If fast reaches NULL, no cycle exists
        if (!fast || !fast->next)
            return nullptr;

        // Step 2: Find the starting node of the cycle
        // Move fast pointer back to the head
        fast = head;

        // Move both pointers one step at a time
        // The node where they meet is the start of the cycle
        while (fast != slow)
        {
            fast = fast->next;
            slow = slow->next;
        }

        // Return the starting node of the cycle
        return slow;
    }
};

*****************************************************************************Brute Solution*********************************************************************
    /**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        vector<ListNode*> visited;

        ListNode* curr = head;

        while (curr != NULL) {
            // Check if current node was already visited
            for (int i = 0; i < visited.size(); i++) {
                if (visited[i] == curr) {
                    // First repeated node is the cycle starting point
                    return curr;
                }
            }

            // Store current node
            visited.push_back(curr);

            // Move to next node
            curr = curr->next;
        }

        // If we reach NULL, there is no cycle
        return NULL;
    }
};
******************************************************************************Better Solution*******************************************************************
   /**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        unordered_set<ListNode*> visited;

        ListNode* curr = head;

        while (curr != NULL) {
            // If current node is already visited,
            // then it is the starting point of the cycle
            if (visited.find(curr) != visited.end()) {
                return curr;
            }

            // Mark current node as visited
            visited.insert(curr);

            // Move forward
            curr = curr->next;
        }

        // No cycle found
        return NULL;
    }
};
*********************************************************************************Optimal Solution****************************************************************
    /**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;

        // Phase 1: Detect whether cycle exists
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;          // Move slow by 1 step
            fast = fast->next->next;    // Move fast by 2 steps

            // If slow and fast meet, cycle exists
            if (slow == fast) {
                // Phase 2: Find the starting point of cycle
                ListNode* start = head;

                // Move both pointers one step at a time
                while (start != slow) {
                    start = start->next;
                    slow = slow->next;
                }

                // This node is the cycle starting point
                return start;
            }
        }

        // If fast reaches NULL, there is no cycle
        return NULL;
    }
};
