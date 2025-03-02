#include <iostream>
#include "list_common.h"

/// 倒数第 k个节点，表示顺序前进 n-k步
Node *find_from_end(Node *head, int k) {

    /// p1先前进 k步
    Node *p1 = head;
    for (int i = 0; i < k; ++i) {
        p1 = p1->next;
    }

    /// 让p2前进n-k步，p2即为倒数第 k个节点
    Node *p2 = head;
    while (p1) {
        p1 = p1->next;
        p2 = p2->next;
    }

    return p2;
}

int main() {

    std::vector<int> v{1,2,3,4,5};
    Node *p = Node::create_list(v);
    Node::print_list(p);

    Node *k = find_from_end(p, 2);
    std::cout << k->val << std::endl;


    return 0;
}