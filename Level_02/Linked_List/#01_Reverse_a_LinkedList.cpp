// You have given a pointer to the head node of a linked list, the task is to reverse the linked list.
// We need to reverse the list by changing the links between nodes.

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

Node *addLast(Node *head, int val)
{
    Node *newNode = new Node(val);
    if (head == NULL)
    {
        head = newNode;
    }
    else if (head->next == NULL)
    {
        head->next = newNode;
    }
    else
    {
        Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    return head;
}

void display(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }

    cout << "null" << endl;
}

int size(Node *head)
{
    int count = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

Node *getNodeAt(Node *head, int idx)
{

    Node *temp = head;
    for (int i = 0; i < idx; i++)
    {
        temp = temp->next;
    }

    return temp;
}

// Data Iterative
Node *reverseDataIterative(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    int lo = 0, hi = size(head) - 1;
    Node *left = NULL;
    Node *right = NULL;
    while (lo <= hi)
    {
        left = getNodeAt(head, lo);
        right = getNodeAt(head, hi);

        int temp = left->data;
        left->data = right->data;
        right->data = temp;

        lo++;
        hi--;
    }

    return head;
}

// Pointer Iterative
Node *reversePointerIterative(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    Node *pre = NULL;
    Node *curr = head;

    Node *temp = NULL;
    while (curr != NULL)
    {
        temp = curr->next;
        curr->next = pre;
        pre = curr;
        curr = temp;
    }

    return pre;
}

void utils(Node *head)
{
    if (head->next == NULL)
    {
        return;
    }
    utils(head->next);

    // post part
    head->next->next = head;

    return;
}

// Pointer Recursive
Node *reversePointerRecursive(Node *head)
{
    Node *tail = getNodeAt(head, size(head) - 1);
    utils(head);
    head->next = NULL;
    head = tail;
    return head;
}

int main()
{
    int n;
    cin >> n;
    Node *head = NULL;
    for (int i = 1; i <= n; i++)
    {
        int val;
        cin >> val;
        head = addLast(head, val);
    }

    display(head);

    head = reversePointerRecursive(head);

    display(head);

    return 0;
}

// INPUT
// 7
// 1 2 3 4 5 6 7

// INPUT FORMAT
// 1->2->3->4->5->6->7->null

// OUTPUT
// 7 6 5 4 3 2 1

// OUTPUT FORMAT
// 7->6->5->4->3->2->1->null