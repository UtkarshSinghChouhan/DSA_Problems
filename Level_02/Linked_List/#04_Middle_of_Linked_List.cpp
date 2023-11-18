// given a singly linked list with head node head, return a middle node of
// linked list. if there is 2 mid node then return first mid node.

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

int size(Node *head) {
    int count = 0;
    Node *temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

Node *getNodeAt(Node *head, int idx) {

    Node *temp = head;
    for (int i = 0; i < idx; i++) {
        temp = temp->next;
    }

    return temp;
}

Node *middleOfLinkedList(Node *head) {
    Node *s = head, *f = head;

    while (f->next != NULL && f->next->next != NULL) {
        f = f->next->next;
        s = s->next;
    }

    return s;
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

    Node *node = middleOfLinkedList(head);
    cout << "Middle of the list is -> " << node->data << "." << endl;

    return 0;
}

// INPUT
// 7   //Odd lrngth List
// 1 2 3 4 5 6 7

// OUTPUT
// Middle of the list is -> 4.

// 6   //Even lrngth List
// 1 2 3 4 5 6

// OUTPUT
// Middle of the list is -> 3.