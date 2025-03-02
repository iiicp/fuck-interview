#include <iostream>
#include "list_common.h"

Node *find_middle_node(Node *head) {
    Node *slow = head, *fast = head;
    while (fast && fast->next) {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

int main() {
    {
        std::vector<int> v{1,2,3,4,5};
        Node *head = Node::create_list(v);
        Node::print_list(head);
        Node *p = find_middle_node(head);
        std::cout << p->val << std::endl;
    }

    {
        std::vector<int> v{1,2,3,4};
        Node *head = Node::create_list(v);
        Node::print_list(head);
        Node *p = find_middle_node(head);
        std::cout << p->val << std::endl;
    }

    return 0;
}