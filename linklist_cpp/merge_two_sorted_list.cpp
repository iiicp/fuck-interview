#include <iostream>
#include "list_common.h"

Node *merge_two_sorted_lists(Node *l1, Node *l2) {
    Node dummy;

    Node *p = &dummy;
    Node *p1 = l1, *p2 = l2;

    while (p1 && p2) {
        if (p1->val < p2->val) {
            p->next = p1;
            p1 = p1->next;
        }else {
            p->next = p2;
            p2 = p2->next;
        }
        p = p->next;
    }
    /// 注意遗漏的部分
    if (p1) {
        p->next = p1;
    }else if (p2) {
        p->next = p2;
    }
    return dummy.next;
}

int main() {

    std::vector<int> l1{1,2,4};
    std::vector<int> l2{1,3,4};

    Node *list1 = Node::create_list(l1);
    Node *list2 = Node::create_list(l2);

    Node::print_list(list1);
    Node::print_list(list2);

    Node *l3 = merge_two_sorted_lists(list1, list2);
    Node::print_list(l3);
    
    return 0;
}