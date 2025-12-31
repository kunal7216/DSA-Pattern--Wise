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