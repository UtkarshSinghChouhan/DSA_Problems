// Given a singly linkedlist : l0 -> l1 -> l2 -> l3 -> l4 -> l5 -> l6 ..... ->
// ln-1 -> ln reorder it : l0 -> ln -> l1 -> ln-1 -> l2 -> ln-2 -> l3 -> ln-3 ->
// and again unfold the redordered-list to the original state

#include <bits/stdc++.h>
using namespace std;

class Node {
  public:
    int data;
    Node *next;
    Node() {}
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

// Middle of the Linked-List
Node *middleOfLinkedList(Node *head) {
    Node *s = head, *f = head;

    while (f->next != NULL && f->next->next != NULL) {
        f = f->next->next;
        s = s->next;
    }

    return s;
}

// reverse of Linked List
Node *reverseOfLinkedList(Node *head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }
    Node *pre = NULL;
    Node *curr = head;

    Node *temp = NULL;
    while (curr != NULL) {
        temp = curr->next;
        curr->next = pre;
        pre = curr;
        curr = temp;
    }

    return pre;
}

void foldLinkedList(Node *head) {
    if (head == NULL || head->next == NULL) {
        return;
    }

    // finding the middle node
    Node *mid = middleOfLinkedList(head);
    Node *newHead = mid->next;
    mid->next = NULL;

    // reverse the second-half of the list
    newHead = reverseOfLinkedList(newHead);

    Node *c1 = head;
    Node *f1 = NULL;

    Node *c2 = newHead;
    Node *f2 = NULL;

    while (c2 != NULL) {
        f1 = c1->next;
        f2 = c2->next;

        c1->next = c2;
        c2->next = f1;

        c1 = f1;
        c2 = f2;
    }
}

void unFoldLinkedList(Node *head) {}
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

    foldLinkedList(head);

    display(head);

    return 0;
}

// INPUT
// 10
// 5
// 1
// 4
// 6
// 9
// 9
// 6
// 4
// 1
// 5

// OUTPUT
// 5->1->4->6->9->9->6->4->1->5->null