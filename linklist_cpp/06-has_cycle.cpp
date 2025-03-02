#include <iostream>
#include "list_common.h"

bool has_cycle(Node *head) {
    Node *slow = head, *fast = head;
    while (fast && fast->next) {
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow) {
            return true;
        }
    }
    return false;
}

int main() {
    return 0;
}