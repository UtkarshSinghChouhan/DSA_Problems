// Given a singly linklist, modify the list such that all the even numbers
// appear before all the odd numbers in the modified list. The order of
// appearance of numbers within each segregation should be same as that in the
// original list.

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

Node *SegEvenOdd(Node *head) {
    // handling edge cases
    if (head == NULL || head->next == NULL) {
        return head;
    }

    Node *eH = new Node();
    Node *eT = eH;
    Node *oH = new Node();
    Node *oT = oH;

    Node *curr = head;

    while (curr != NULL) {
        if (curr->data % 2 == 0) {
            eT->next = curr;
            eT = eT->next;
        } else {
            oT->next = curr;
            oT = oT->next;
        }

        curr = curr->next;
    }

    oT->next = NULL;
    eT->next = oH->next;

    return eH->next;
}

int main() {
    int n;
    cin >> n;
    Node *head = NULL;
    for (int i = 1; i <= n; i++) {
        int val;
        cin >> val;
        head = addLast(head, val);
    }

    display(head);

    Node *newHead = SegEvenOdd(head);

    display(newHead);

    return 0;
}

// INPUT
// 1->7->2->6->3->5->4->null

// 10
// 1
// 3
// 2
// 4
// 5
// 6
// 7
// 18
// 19
// 20

// OUTPUT
// 2->6->4->1->7->3->5->null

// 1->3->2->4->5->6->7->18->19->20->null
// 2->4->6->18->20->1->3->5->7->19->null