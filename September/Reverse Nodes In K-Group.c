#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* createNode(int val) {
    struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
    node->val = val;
    node->next = NULL;
    return node;
}

void freeList(struct ListNode* head) {
    struct ListNode* tmp;
    while (head != NULL) {
        tmp = head;
        head = head->next;
        free(tmp);
    }
}

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode dummy;
    struct ListNode* tail = &dummy;
    dummy.next = NULL;
    
    while (l1 != NULL && l2 != NULL) {
        if (l1->val <= l2->val) {
            tail->next = l1;
            l1 = l1->next;
        } else {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }
    
    if (l1 != NULL) {
        tail->next = l1;
    } else {
        tail->next = l2;
    }
    
    return dummy.next;
}

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
    if (listsSize == 0) return NULL;
    
    int interval = 1;
    while (interval < listsSize) {
        for (int i = 0; i + interval < listsSize; i += interval * 2) {
            lists[i] = mergeTwoLists(lists[i], lists[i + interval]);
        }
        interval *= 2;
    }
    
    return lists[0];
}

void printList(struct ListNode* head) {
    while (head != NULL) {
        printf("%d ", head->val);
        head = head->next;
    }
    printf("\n");
}

int main() {
    struct ListNode* l1 = createNode(1);
    l1->next = createNode(4);
    l1->next->next = createNode(5);

    struct ListNode* l2 = createNode(1);
    l2->next = createNode(3);
    l2->next->next = createNode(4);

    struct ListNode* l3 = createNode(2);
    l3->next = createNode(6);

    struct ListNode* lists[] = {l1, l2, l3};
    struct ListNode* mergedHead = mergeKLists(lists, 3);

    printf("Merged List: ");
    printList(mergedHead);

    freeList(mergedHead);

    return 0;
}