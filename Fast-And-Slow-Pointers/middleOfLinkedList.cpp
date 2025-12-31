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
