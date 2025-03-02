#pragma once
#include <vector>
struct Node {
    int val;
    Node *next;
    Node():val(-1), next(nullptr) {}
    Node(int val) : val(val), next(nullptr) {
    }

    static Node * create_list(const std::vector<int> &elems) {
        Node dummy;
        Node *p = &dummy;
        for (auto n : elems) {
            Node *node = new Node(n);
            p->next = node;
            p = p->next;
        }
        return dummy.next;
    }
    
    static void print_list(Node *head) {
        Node *p = head;
        while (p) {
            std::cout << p->val << " ";
            p = p->next;
        }
        std::cout << std::endl;
    }
};
