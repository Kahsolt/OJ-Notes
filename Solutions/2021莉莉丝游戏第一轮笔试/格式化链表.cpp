#include <iostream>
using namespace std;

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(nullptr) { }
};

void print(ListNode* p) {
    while (p) {
        cout << p->val << " ";
        p = p->next;
    }
    cout << endl;
}

class Solution {
public:
    ListNode* formatList(ListNode* head) {
        if (!head) return nullptr;

        // split odd / even
        bool odd = true;
        ListNode *oddList = nullptr, *evenList = nullptr, *p = head;
        while (p) {
            ListNode *r = p; p = p->next;
            if (odd) {
                r->next = oddList;
                oddList = r;
            } else {
                r->next = evenList;
                evenList = r;
            }
            odd = !odd;
        }
        //cout << "odd: " << endl; print(oddList);
        //cout << "even:" << endl; print(evenList);


        // reverse even
        ListNode *even_rev = nullptr;
        p = evenList;
        while (p) {
            ListNode *r = p; p = p->next;
            r->next = even_rev;
            even_rev = r;
        }
        
        // concat
        p = oddList;
        while (p->next) p = p->next;
        //cout << "now p = " << p->val << endl;
        p->next = even_rev;

        return oddList;
    }
};

int main() {
    ListNode n1(1), n2(2), n3(3), n4(4), n5(5);
    n1.next = &n2; n2.next = &n3; n3.next = &n4; n4.next = &n5;
    print(&n1);
    Solution sol;
    ListNode *r = sol.formatList(&n1);
    print(r);
}