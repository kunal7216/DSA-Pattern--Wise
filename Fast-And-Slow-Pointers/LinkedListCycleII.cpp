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
