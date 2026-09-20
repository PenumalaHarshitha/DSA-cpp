#include <bits/stdc++.h>
using namespace std;


// ============================================================
// NODE CLASS
// ============================================================

class Node
{
public:
    int data;
    Node *next;

    Node(int value)
    {
        data = value;
        next = nullptr;
    }

    Node(int value, Node *nextNode)
    {
        data = value;
        next = nextNode;
    }
};


// ============================================================
// INSERT AT START
// ============================================================

Node* insertStart(Node *head, int value)
{
    Node *newNode = new Node(value, head);

    return newNode;
}


// ============================================================
// INSERT AT TAIL
// ============================================================

Node* insertTail(Node *head, int value)
{
    Node *newNode = new Node(value);

    if (head == nullptr)
    {
        return newNode;
    }

    Node *current = head;

    while (current->next != nullptr)
    {
        current = current->next;
    }

    current->next = newNode;

    return head;
}


// ============================================================
// DELETE FROM START
// ============================================================

Node* deleteStart(Node *head)
{
    if (head == nullptr)
        return head;

    Node *oldHead = head;

    head = head->next;

    delete oldHead;

    return head;
}


// ============================================================
// DELETE FROM TAIL
// ============================================================

Node* deleteTail(Node *head)
{
    if (head == nullptr)
        return head;

    // Only one node
    if (head->next == nullptr)
    {
        delete head;
        return nullptr;
    }

    Node *current = head;

    while (current->next->next != nullptr)
    {
        current = current->next;
    }

    delete current->next;

    current->next = nullptr;

    return head;
}


// ============================================================
// INSERT AT ANY POSITION
// ============================================================

Node* insertAtPosition(Node *head,
                       int value,
                       int position)
{
    // Empty list
    if (head == nullptr)
    {
        if (position == 1)
            return new Node(value);

        return head;
    }

    // Insert at first position
    if (position == 1)
    {
        return insertStart(head, value);
    }

    Node *current = head;
    int count = 1;

    while (current != nullptr)
    {
        if (count == position - 1)
        {
            Node *newNode = new Node(value);

            newNode->next = current->next;
            current->next = newNode;

            return head;
        }

        count++;
        current = current->next;
    }

    return head;
}


// ============================================================
// DELETE FROM ANY POSITION
// ============================================================

Node* deleteAtPosition(Node *head, int position)
{
    if (head == nullptr)
        return head;

    if (position <= 0)
    {
        cout << "\nInvalid Position";
        return head;
    }

    // Delete first node
    if (position == 1)
    {
        return deleteStart(head);
    }

    Node *current = head;
    int count = 1;

    while (current != nullptr)
    {
        if (count == position - 1)
        {
            if (current->next == nullptr)
            {
                cout << "\nPosition not found";
                return head;
            }

            Node *deleteNode = current->next;

            current->next = deleteNode->next;

            delete deleteNode;

            return head;
        }

        count++;
        current = current->next;
    }

    cout << "\nPosition not found";

    return head;
}


// ============================================================
// INSERT BEFORE A GIVEN VALUE
// ============================================================

Node* insertBeforeValue(Node *head,
                        int newValue,
                        int targetValue)
{
    if (head == nullptr)
        return head;

    // Target is the first node
    if (head->data == targetValue)
    {
        return insertStart(head, newValue);
    }

    Node *current = head;

    while (current->next != nullptr)
    {
        if (current->next->data == targetValue)
        {
            Node *newNode = new Node(newValue);

            newNode->next = current->next;
            current->next = newNode;

            return head;
        }

        current = current->next;
    }

    cout << "\nValue not found";

    return head;
}


// ============================================================
// DELETE BY VALUE
// ============================================================

Node* deleteByValue(Node *head, int value)
{
    if (head == nullptr)
        return head;

    // Delete head
    if (head->data == value)
    {
        return deleteStart(head);
    }

    Node *current = head;

    while (current->next != nullptr)
    {
        if (current->next->data == value)
        {
            Node *deleteNode = current->next;

            current->next = deleteNode->next;

            delete deleteNode;

            return head;
        }

        current = current->next;
    }

    return head;
}


// ============================================================
// CONVERT ARRAY TO LINKED LIST
// ============================================================

Node* arrayToLL(vector<int>& arr)
{
    if (arr.empty())
        return nullptr;

    Node *head = new Node(arr[0]);

    Node *current = head;

    for (int i = 1; i < arr.size(); i++)
    {
        Node *newNode = new Node(arr[i]);

        current->next = newNode;
        current = newNode;
    }

    return head;
}


// ============================================================
// PRINT LINKED LIST
// ============================================================

void printLL(Node *head)
{
    cout << "\nDisplay: ";

    Node *current = head;

    while (current != nullptr)
    {
        cout << "\t" << current->data;
        current = current->next;
    }

    cout << endl;
}


// ============================================================
// SEARCH ELEMENT
// ============================================================

int searchElement(Node *head, int value)
{
    int position = 0;

    Node *current = head;

    while (current != nullptr)
    {
        position++;

        if (current->data == value)
            return position;

        current = current->next;
    }

    return -1;
}


// ============================================================
// FIND LENGTH
// ============================================================

int lengthOfLL(Node *head)
{
    int length = 0;

    Node *current = head;

    while (current != nullptr)
    {
        length++;

        current = current->next;
    }

    return length;
}


// ============================================================
// MAIN
// ============================================================

int main()
{
    Node *head = nullptr;

    vector<int> arr = {12, 3, 45, 6, 78, 89, 65, 9, 23, 4};


    // Convert array to linked list
    head = arrayToLL(arr);

    printLL(head);


    // Search
    int position = searchElement(head, 23);

    if (position == -1)
    {
        cout << "\nElement not found";
    }
    else
    {
        cout << "\nElement is found at position: "
             << position;
    }


    // Length
    int length = lengthOfLL(head);

    cout << "\nLength is: " << length;


    // Insert before value 13
    head = insertBeforeValue(head, 1000, 13);

    printLL(head);


    return 0;
}
