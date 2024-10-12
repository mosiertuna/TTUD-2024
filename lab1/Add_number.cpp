#include <bits/stdc++.h>

using namespace std;

// Định nghĩa cấu trúc ListNode
typedef struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
} ListNode;

class Solution {
public:
    ListNode* Add_Two_Numbers(ListNode* l1, ListNode* l2) {
        ListNode dummy;
        ListNode* current = &dummy;
        int carry = 0;

        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            int sum = carry;
            if (l1 != nullptr) {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2 != nullptr) {
                sum += l2->val;
                l2 = l2->next;
            }
            carry = sum / 10;
            current->next = new ListNode(sum % 10);
            current = current->next;
        }

        return dummy.next;
    }
};

ListNode* create_list(const int arr[], int n) {
    if (n == 0) return nullptr;
    ListNode* head = new ListNode(arr[0]);
    ListNode* current = head;
    for (int i = 1; i < n; i++) {
        current->next = new ListNode(arr[i]);
        current = current->next;
    }
    return head;
}

void print_list(ListNode* head) {
    while (head != nullptr) {
        cout << head->val;
        head = head->next;
    }
    cout << endl;
}

int main() {
    int arr1[] = {0};
    int arr2[] = {0};

    ListNode* l1 = create_list(arr1, 1);
    ListNode* l2 = create_list(arr2, 1);

    Solution sol;
    ListNode* result = sol.Add_Two_Numbers(l1, l2);

    print_list(result);

    return 0;
}