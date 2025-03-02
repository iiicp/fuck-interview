#include <iostream>
#include "list_common.h"

Node *detect_cycle(Node *head) {
    Node *slow = head;
    Node *fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            break;
        }
    }
    /// 无环退出
    if (fast == nullptr || fast->next == nullptr) {
        return nullptr;
    }

    /// 将一个指针从头开始，会再次相遇
    slow = head;
    while (slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
}

int main() {
    return 0;
}