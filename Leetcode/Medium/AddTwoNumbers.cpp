#include <iostream>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    void print(ListNode *head);
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {

        ListNode *head = nullptr;
        ListNode *temp = nullptr;
        int carry = 0;
        while (l1 != nullptr || l2 != nullptr)
        {
            int sum = 0;
            if (l1 != nullptr)
            {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2 != nullptr)
            {
                sum += l2->val;
                l2 = l2->next;
            }
            sum += carry;
            carry = sum / 10;
            if (head == nullptr)
            {
                head = new ListNode(sum % 10);
                temp = head;
            }
            else
            {
                temp->next = new ListNode(sum % 10);
                temp = temp->next;
            }
        }
        if (carry > 0)
        {
            temp->next = new ListNode(carry);
        }
        return head;
    }
};

void Solution::print(ListNode *head)
{
    if (head == nullptr)
    {
        cout << "List is empty" << endl;
        return;
    }
    while (head != nullptr)
    {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    Solution s;
    ListNode *head1 = nullptr;
    ListNode *head2 = nullptr;
    int n1, n2;
    cout << "Enter the number of elements in first list: ";
    cin >> n1;
    cout << "Enter the number of elements in second list: ";
    cin >> n2;
    cout << "Enter the elements of first list: ";
    for (int i = 0; i < n1; i++)
    {
        int x;
        cin >> x;
        if (head1 == nullptr)
        {
            head1 = new ListNode(x);
        }
        else
        {
            while (head1->next != nullptr)
            {
                head1 = head1->next;
            }
            head1->next = new ListNode(x, head1->next);
        }
    }
    cout << "Enter the elements of second list: ";
    for (int i = 0; i < n2; i++)
    {
        int x;
        cin >> x;
        if (head2 == nullptr)
        {
            head2 = new ListNode(x);
        }
        else
        {
            while (head2->next != nullptr)
            {
                head2 = head2->next;
            }
            head2->next = new ListNode(x, head2->next);
        }
    }
    s.addTwoNumbers(head1, head2);
    return 0;
}