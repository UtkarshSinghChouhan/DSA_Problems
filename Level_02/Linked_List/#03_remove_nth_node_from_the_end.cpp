// 1. You are given a partially written LinkedList class.
// 2. Here is a list of existing functions:
//      2.1 addLast - adds a new element with given value to the end of Linked
//      List 2.2. display - Prints the elements of linked list from front to end
//      in a single line. All elements are separated by space.
//     2.3. size - Returns the number of elements in the linked list.
//     2.4. removeFirst - Removes the first element from Linked List.
//     2.5. getFirst - Returns the data of first element.
//     2.6. getLast - Returns the data of last element.
//     2.7. getAt - Returns the data of element available at the index passed.
//     2.8. addFirst - adds a new element with given value in front of linked
//     list. 2.9. addAt - adds a new element at a given index. 2.10. removeLast
//     - removes the last element of linked list. 2.11. removeAt - remove an
//     element at a given index
// 3. You are required to complete the body of kthFromLast function. The
// function should be an iterative function and should return the kth node from
// end of linked list. Also, make sure to not use size data member directly or
// indirectly (by calculating size via making a traversal). k is a 0-based
// index. Assume that valid values of k will be passed.
// 4. Input and Output is managed for you.

// You have given a pointer to the head node of a linked list, the task is to
// reverse the linked list. We need to reverse the list by changing the links
// between nodes.

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

void removenthNodeFromEnd(Node *head, int k) {
    Node *s = head, *f = head;
    for (int i = 0; i <= k; i++) {
        f = f->next;
    }

    while (f != NULL) {
        s = s->next;
        f = f->next;
    }

    s->next = s->next->next;
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

    int k;
    cin >> k;

    display(head);
    removenthNodeFromEnd(head, k);
    display(head);

    return 0;
}

// INPUT
// 3

// OUTPUT
// 3th node from the end is -> 5