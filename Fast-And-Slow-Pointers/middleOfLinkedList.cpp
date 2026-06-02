***************************************************************************Brute Solution***************************************************************************

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        // Store all linked list nodes inside a vector
        vector<ListNode*> nodes;

        ListNode* temp = head;

        // Traverse the linked list and push every node into vector
        while (temp != nullptr) {
            nodes.push_back(temp);
            temp = temp->next;
        }

        // Middle index is size / 2
        // Odd length: exact middle
        // Even length: second middle
        int middleIndex = nodes.size() / 2;

        return nodes[middleIndex];
    }
};
**********************************************************************Better Solution********************************************************************************

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        int length = 0;

        ListNode* temp = head;

        // Step 1: Count the total number of nodes
        while (temp != nullptr) {
            length++;
            temp = temp->next;
        }

        // Step 2: Calculate middle index
        // For even length, this gives second middle
        int middleIndex = length / 2;

        // Step 3: Move from head to middle index
        temp = head;

        for (int i = 0; i < middleIndex; i++) {
            temp = temp->next;
        }

        return temp;
    }
};
    
********************************************************************optimal Solution**********************************************************************************
class Solution
{
public:
    ListNode *middleNode(ListNode *head)
    {

        // Initialize slow pointer at the head of the linked list
        ListNode *slow = head;

        // Initialize fast pointer at the head of the linked list
        ListNode *fast = head;

        // Traverse the list while fast pointer can move ahead safely
        // fast moves two steps, slow moves one step
        while (fast != nullptr && fast->next != nullptr)
        {

            // Move slow pointer one step forward
            slow = slow->next;

            // Move fast pointer two steps forward
            fast = fast->next->next;
        }

        // When fast reaches the end,
        // slow will be at the middle of the linked list
        // (for even length, it returns the second middle node)
        return slow;
    }
};
