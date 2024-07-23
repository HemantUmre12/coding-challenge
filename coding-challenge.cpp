/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */


// 1. Implement a function to reverse a singly linked list.
// Reversing a linked list using iteration
// Time Complexity: O(n)
// Space Complexity: O(1)
class ReverseListUsingIteration
{
public:
    ListNode *reverseLL(ListNode *head)
    {
        ListNode *curr{head};
        ListNode *prev{NULL};

        // Point the current node's next ptr to previous node
        // keep going until reach the end
        while (curr)
        {
            ListNode *next{curr->next};
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }
};


// Reversing a linked list using recursion
// Time Complexity: O(n)
// Space Complexity: O(n) [space for recursion stack]
class reverseListUsingRecursion
{
private:
    // Created a variable to keep track of new head of the linkedlist
    ListNode *newHead{};
    ListNode *reverse(ListNode *head)
    {
        // If the current node is the last node of the linkedlist
        // It will be new head of the linked list
        if (!head || !head->next)
        {
            newHead = head;
            return head;
        }

        // Get the reversed linkedlist and append the current node
        // at the end of the list
        ListNode *node = reverse(head->next);
        node->next = head;
        return head;
    }

public:
    ListNode *reverseLL(ListNode *head)
    {
        // Using a helper function to reverse a linked list
        reverse(head);

        return newHead;
    }
};

// 2. Implement a function to detect a cycle in a linked list
// Time Complexity: O(n)
// Space Complexity: O(1)
class DetectCycle
{
public:
    bool hasCycle(ListNode *head)
    {
        if (!head || !head->next)
        {
            return false;
        }

        ListNode *fast{head->next};
        ListNode *slow{head};

        // We are having two pointers one is moving one node at a time [slow]
        // other is moving two node at a time [fast]
        // if the fast one reaches the end -> there is not cycle
        while (fast && fast->next)
        {
            // Incase if fast and slow pointer are pointing at the same node
            // there is a cycle
            if (fast == slow)
            {
                return true;
            }

            fast = fast->next->next;
            slow = slow->next;
        }

        return false;
    }
};
