#include <iostream>
#include <queue>
#include "list_common.h"

Node *merge_k_lists(std::vector<Node *> &lists) {
    Node dummy;
    Node *p = &dummy;

    /// 比较函数 大于 表示小顶堆
    auto cmp = [](Node *a, Node *b) -> bool {
        return a->val > b->val;
    };

    /// 构造函数，需要传入比较对象
    std::priority_queue<Node *, std::vector<Node *>, decltype(cmp)> pq(cmp);

    /// 容量为k的优先级队列
    for (Node *n : lists) {
        pq.push(n);
    }

    while (!pq.empty()) {
        Node *n = pq.top();
        pq.pop();

        /// 添加到链表中
        p->next = n;
        p = p->next;

        /// 队列添加新元素
        if (n->next) {
            pq.push(n->next);
        }
    }

    return dummy.next;
}

int main() {
    std::vector<std::vector<int>> lists{{1,4,5}, {1,3,4}, {2,6}};
    std::vector<Node *> plists;
    for (auto &v : lists) {
        plists.push_back(Node::create_list(v));
    }
    for (auto &p : plists) {
        Node::print_list(p);
    }

    Node *n = merge_k_lists(plists);
    Node::print_list(n);

    return 0;
}