#include <iostream>
#include "list_common.h"

/// 技巧是两个链表拼接访问
/// 访问的长度就是一致了，一定能结束
Node *get_intersection_node(Node *headA, Node *headB) {
    Node *p1 = headA, *p2 = headB;

    if (p1 == nullptr || p2 == nullptr) {
        return nullptr;
    }

    while (p1 != p2) {
        p1 = p1->next;
        if (p1 == nullptr) {
            p1 = headB;
        }
        p2 = p2->next;
        if (p2 == nullptr) {
            p2 = headA;
        }
    }
    return p1;
}

int main() {

    std::vector<int> c{4,5};
    Node *common = Node::create_list(c);
    // Node::print_list(common);

    std::vector<int> v1{1,2,3};
    Node *head1 = Node::create_list(v1);
    Node *p1 = head1;
    while (p1->next) {
        p1 = p1->next;
    }
    p1->next = common;
    Node::print_list(head1);


    std::vector<int> v2{7,8};
    Node *head2 = Node::create_list(v2);
    Node *p2 = head2;
    while (p2->next) {
        p2 = p2->next;
    }
    p2->next = common;
    Node::print_list(head2);


    Node *newNode = get_intersection_node(head1, head2);
    std::cout << newNode->val << std::endl;

    return 0;
}