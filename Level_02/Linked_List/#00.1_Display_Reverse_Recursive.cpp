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

void displayReverseRecursive(Node *head)
{
    if (head == NULL)
    {
        return;
    }
    displayReverseRecursive(head->next);
    cout << head->data << "->";

    return;
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

    displayReverseRecursive(head);

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
// 7->6->5->4->3->2->1->