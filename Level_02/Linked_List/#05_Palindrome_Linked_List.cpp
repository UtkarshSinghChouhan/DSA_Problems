// Given a singly linked list of Integers,
//     determine it is a palindrome or not .

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

// Pointer Iterative
Node *reversePointerIterative(Node *head) {
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

// Palindrome function
bool isPalindrome(Node *head) {
    // Handling the edge cases
    if (head == NULL || head->next == NULL) {
        return true;
    }

    // At First find the middle of the linked list
    Node *midNode = middleOfLinkedList(head);

    // break the linked list into two
    Node *halfList = midNode->next;
    midNode->next = NULL;

    // Now reverse only the second half of the linked list
    halfList = reversePointerIterative(halfList);

    // At last check for palindrome
    Node *lo = head, *hi = halfList;

    bool res =
        true; // initially we are considering that the list is palindromic
    while (hi != NULL) {
        if (lo->data != hi->data) {
            res = false;
            break;
        }
        lo = lo->next;
        hi = hi->next;
    }

    // Now before returning the answer we need to fix the list to what it was
    halfList = reversePointerIterative(halfList);
    midNode->next = halfList;

    return res;
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

    if (isPalindrome(head)) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }

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
// true