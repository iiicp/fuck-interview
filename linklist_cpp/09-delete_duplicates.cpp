#include <iostream>
#include "list_common.h"

Node *delete_duplicates(Node *head) {
    Node dummy1, dummy2;
    Node *p1 = &dummy1, *p2 = &dummy2;
    Node *p = head;

    while (p) {
        if (p->next && p->next->val == p->val || p->val == p2->val) {
            p2->next = p;
            p2 = p2->next;
        }else {
            p1->next = p;
            p1 = p1->next;
        }
        p = p->next;
    }

    p1->next = nullptr;

    return dummy1.next;
}

int main() {
    {
        std::vector<int> v{1,2,3,3,4,4,5};
        Node *head = Node::create_list(v);
        Node::print_list(head);

        Node *p = delete_duplicates(head);
        Node::print_list(p);
    }

    {
        std::vector<int> v{1,1,1,2,3};
        Node *head = Node::create_list(v);
        Node::print_list(head);

        Node *p = delete_duplicates(head);
        Node::print_list(p);
    }

    return 0;
}