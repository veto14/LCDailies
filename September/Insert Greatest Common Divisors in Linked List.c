#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};

// Helper function to calculate GCD
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Function to insert GCD nodes
struct ListNode* insertGreatestCommonDivisors(struct ListNode* head) {
    if (!head || !head->next) {
        return head;  // If the list has 0 or 1 node, no insertion needed
    }

    struct ListNode* current = head;
    
    while (current && current->next) {
        int gcdValue = gcd(current->val, current->next->val);
        
        // Create a new node for the GCD value
        struct ListNode* gcdNode = (struct ListNode*)malloc(sizeof(struct ListNode));
        gcdNode->val = gcdValue;
        gcdNode->next = current->next;
        
        // Insert the GCD node between current and next node
        current->next = gcdNode;
        
        // Move to the next pair
        current = gcdNode->next;
    }

    return head;
}

// Function to create a new ListNode
struct ListNode* createNode(int val) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

// Helper function to print the list
void printList(struct ListNode* head) {
    struct ListNode* temp = head;
    while (temp) {
        printf("%d ", temp->val);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    // Creating the linked list: 18 -> 6 -> 10 -> 3
    struct ListNode* head = createNode(18);
    head->next = createNode(6);
    head->next->next = createNode(10);
    head->next->next->next = createNode(3);

    printf("Original list: ");
    printList(head);

    // Insert GCD nodes
    head = insertGreatestCommonDivisors(head);

    printf("Modified list: ");
    printList(head);

    return 0;
}
