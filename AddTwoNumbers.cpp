#include <iostream>

struct ListNode {
  int val;
  ListNode *next = nullptr;
  ListNode(int x) : val(x) {}
};

class Solution {
public:
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    ListNode *result = nullptr;
    ListNode *p = nullptr;
    if (l1 != nullptr && l2 != nullptr) {
      p = result = new ListNode(l1->val + l2->val);
      l1 = l1->next;
      l2 = l2->next;
      //      p = result;
    }
    while (l1 != nullptr && l2 != nullptr) {
      p->next = new ListNode(l1->val + l2->val);
      p = p->next;
      l1 = l1->next;
      l2 = l2->next;
    }
    return result;
  }

  ListNode *creatLinkList() {
    int value;
    ListNode *l;
    ListNode *p = nullptr;
    if (std::cin >> value) {
      p = l = new ListNode(value);
    }
    char c;
    while ((c = getc(stdin) != '\n')) {
      std::cin >> value;
      p->next = new ListNode(value);
      p = p->next;
    }
    return l;
  }
};

int main() {
  ListNode *l1;
  ListNode *l2;
  ListNode *result;
  Solution sol;
  std::cout << "l1 input: ";
  l1 = sol.creatLinkList();
  std::cout << "l2 input: ";
  l2 = sol.creatLinkList();
  result = sol.addTwoNumbers(l1, l2);
  ListNode *p = result;
  while (p != nullptr) {
    std::cout << p->val << " ";
    p = p->next;
  }
  std::cout << std::endl;
}
