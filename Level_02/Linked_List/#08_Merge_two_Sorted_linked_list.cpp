// 1. Merge two sorted linkedlists and return head of a sorted linkedlist. The
// list should be made by splicing together the nodes of the first two lists
// 2. Both list are sorted in increasing order.

#include <bits/stdc++.h>
using namespace std;

class Node {
  public:
    int data;
    Node *next;
    Node() { this->next = NULL; }
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

Node *addLast(Node *head, int val) {
    Node *newNode = new Node(val);
    if (head == NULL) {
        head = newNode;
    } else if (head->next == NULL) {
        head->next = newNode;
    } else {
        Node *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    return head;
}

void display(Node *head) {
    Node *temp = head;
    while (temp != NULL) {
        cout << temp->data << "->";
        temp = temp->next;
    }

    cout << "null" << endl;
}

Node *mergeTwoSortedList(Node *head1, Node *head2) {
    // Handling edge cases
    if (head1 == NULL || head2 == NULL) {
        return head1 == NULL ? head2 : head1;
    }

    Node *c1 = head1, *c2 = head2;

    Node *dummy = new Node();
    cout << "dummy node data = (Garbage Value)" << dummy->data << endl;
    Node *p = dummy;
    while (c1 != NULL && c2 != NULL) {
        if (c1->data <= c2->data) {
            p->next = c1;
            c1 = c1->next;
        } else {
            p->next = c2;
            c2 = c2->next;
        }
        p = p->next;
    }

    if (c1 != NULL) {
        p->next = c1;
    }

    if (c2 != NULL) {
        p->next = c2;
    }

    return dummy->next;
}

int main() {
    int n1;
    cin >> n1;
    Node *head1 = NULL;
    for (int i = 1; i <= n1; i++) {
        int val;
        cin >> val;
        head1 = addLast(head1, val);
    }

    display(head1);

    int n2;
    cin >> n2;
    Node *head2 = NULL;
    for (int i = 1; i <= n2; i++) {
        int val;
        cin >> val;
        head2 = addLast(head2, val);
    }

    display(head2);

    Node *newList = mergeTwoSortedList(head1, head2);

    display(newList);

    return 0;
}

// INPUT
// 2
// 1 5
// 4
// 1 3 6 10

// OUTPUT
// 1->1->3->5->6->10->null