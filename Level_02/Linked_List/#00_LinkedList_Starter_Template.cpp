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

class LinkedList
{
public:
    Node *head;
    Node *tail;
    int size;

    LinkedList()
    {
        this->head = NULL;
        this->tail = NULL;
        this->size = 0;
    }

    void addLast(int data)
    {
        Node *temp = new Node(data);

        if (this->size == 0)
        {

            this->head = temp;
            this->tail = temp;
        }
        else
        {

            this->tail->next = temp;
            this->tail = temp;
        }
        this->size++;
    }

    void display()
    {
        Node *temp = head;

        while (temp != NULL)
        {
            cout << temp->data << "->";
            temp = temp->next;
        }

        cout << "null" << endl;
    }

    int getFirst()
    {
        if (this->size == 0)
        {
            return -1;
        }

        return head->data;
    }

    int getlast()
    {
        if (this->size == 0)
        {
            return -1;
        }

        Node *temp = head;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        return temp->data;
    }

    Node *getAt(int pos)
    {
        if (this->size == 0)
        {
            return NULL;
        }

        Node *temp = head;

        for (int i = 0; i < pos; i++)
        {
            temp = temp->next;
        }

        return temp;
    }

    void addFirst(int data)
    {
        Node *temp;

        temp->data = data;
        temp->next = head;

        head = temp;

        if (this->size == 0)
        {
            this->tail = temp;
        }

        this->size++;
    }

    void addAt(int idx, int data)
    {
        if (idx < 0 || idx > size)
        {
            cout << "Index out of bound" << endl;
        }
        else if (idx == 0)
        {
            addFirst(data);
        }
        else if (idx == size)
        {
            addLast(data);
        }
        else
        {
            Node *newNode;
            newNode->data = data;

            Node *temp = head;
            for (int i = 0; i < idx - 1; i++)
            {
                temp = temp->next;
            }

            newNode->next = temp->next;
            temp->next = newNode;

            this->size++;
        }
    }

    void removeFirst()
    {
        if (this->size == 0)
        {
            cout << "List is empty" << endl;
        }
        else if (this->size == 1)
        {
            this->head = NULL;
            this->tail = NULL;

            this->size = 0;
        }
        else
        {

            this->head = head->next;
            this->size--;
        }
    }

    void removeLast()
    {
        if (this->size == 0)
        {
            cout << "List is empty" << endl;
        }
        else if (this->size == 1)
        {
            this->head = NULL;
            this->tail = NULL;
            this->size = 0;
        }
        else
        {
            Node *temp = head;
            for (int i = 0; i < this->size - 2; i++)
            {
                temp = temp->next;
            }

            this->tail = temp;
            temp->next = NULL;

            this->size--;
        }
    }

    void removeAtIdx(int idx)
    {
        if (idx == 0)
        {
            removeFirst();
        }
        else if (idx == this->size)
        {
            removeLast();
        }
        else
        {
            Node *temp = this->head;
            for (int i = 0; i < idx - 1; i++)
            {
                temp = temp->next;
            }

            temp->next = temp->next->next;
            this->size--;
        }
    }

    // void testList()
    // {
    //     for (Node *temp = head; temp != NULL; temp = temp->next)
    //     {
    //         cout << temp->data << endl;
    //     }
    //     cout << size << endl;

    //     if (size > 0)
    //     {
    //         cout << tail->data << endl;
    //     }
    // }
};

int main()
{
    LinkedList l;

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        int val;
        cin >> val;
        l.addLast(val);
    }

    // cout << l.getFirst() << endl;
    // cout << l.getlast() << endl;
    //  cout << l.getAt(3) << endl;

    //  l.addFirst(22);

    //  l.testList();

    l.display();
}
