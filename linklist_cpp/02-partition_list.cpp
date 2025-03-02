#include <iostream>
#include "list_common.h"

Node *partition_list(Node *head, int x) {
    Node dummy1, dummy2;
    Node *p1 = &dummy1, *p2 = &dummy2;
    Node *p = head;
    while (p) {
        if (p->val < x) {
            p1->next = p;
            p1 = p1->next;
        }else {
            p2->next = p;
            p2 = p2->next;
        }
        p = p->next;
    }
    p1->next = dummy2.next;
    /// 拆分成两个链表，有一个链表的结尾，可能不为 null
    p2->next = nullptr;
    return dummy1.next;
}

int main() {
    std::vector<int> v{1,4,3,2,5,2};
    Node *head = Node::create_list(v);
    Node::print_list(head);

    Node *n = partition_list(head, 3);
    Node::print_list(n);
    return 0;
}