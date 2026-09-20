#include <bits/stdc++.h>
using namespace std;


// ============================================================
// NODE CLASS
// ============================================================

class node
{
public:
    int data;
    node *back;
    node *next;

    node(int data1, node *next1, node *back1)
    {
        data = data1;
        next = next1;
        back = back1;
    }

    node(int data1)
    {
        data = data1;
        next = nullptr;
        back = nullptr;
    }
};


// ============================================================
// CONVERT ARRAY TO DOUBLY LINKED LIST
// ============================================================

node* convertArrayToDLL(vector<int>& arr)
{
    if (arr.empty())
        return nullptr;

    node *head = new node(arr[0]);
    node *previous = head;

    for (int i = 1; i < arr.size(); i++)
    {
        node *newNode = new node(arr[i], nullptr, previous);

        previous->next = newNode;
        previous = newNode;
    }

    return head;
}


// ============================================================
// PRINT DOUBLY LINKED LIST
// ============================================================

void printDLL(node *head)
{
    cout << "\nDisplay: ";

    node *current = head;

    while (current != nullptr)
    {
        cout << current->data << "\t";
        current = current->next;
    }

    cout << endl;
}


// ============================================================
// DELETE HEAD
// ============================================================

node* deleteHead(node *head)
{
    if (head == nullptr)
        return head;

    // Only one node
    if (head->next == nullptr)
    {
        delete head;
        return nullptr;
    }

    node *oldHead = head;

    head = head->next;
    head->back = nullptr;

    oldHead->next = nullptr;

    delete oldHead;

    return head;
}


// ============================================================
// DELETE TAIL
// ============================================================

node* deleteTail(node *head)
{
    if (head == nullptr)
        return head;

    // Only one node
    if (head->next == nullptr)
    {
        delete head;
        return nullptr;
    }

    node *current = head;

    // Reach the tail
    while (current->next->next != nullptr)
    {
        current = current->next;
    }

    node *oldTail = current->next;

    current->next = nullptr;
    oldTail->back = nullptr;

    delete oldTail;

    return head;
}


// ============================================================
// DELETE K-th ELEMENT
// ============================================================

node* deleteKthElement(node *head, int k)
{
    if (head == nullptr)
        return head;

    int count = 0;
    node *current = head;

    // Find the K-th node
    while (current != nullptr)
    {
        count++;

        if (count == k)
            break;

        current = current->next;
    }

    // K is greater than number of nodes
    if (current == nullptr)
        return head;

    node *previous = current->back;
    node *nextNode = current->next;

    // Only one node
    if (previous == nullptr && nextNode == nullptr)
    {
        delete current;
        return nullptr;
    }

    // K-th node is head
    if (previous == nullptr)
    {
        return deleteHead(head);
    }

    // K-th node is tail
    if (nextNode == nullptr)
    {
        return deleteTail(head);
    }

    // K-th node is in the middle
    previous->next = nextNode;
    nextNode->back = previous;

    current->next = nullptr;
    current->back = nullptr;

    delete current;

    return head;
}


// ============================================================
// DELETE A GIVEN NODE
// NOTE: node should not be the head
// ============================================================

void deleteNode(node *current)
{
    if (current == nullptr)
        return;

    node *previous = current->back;
    node *nextNode = current->next;

    // If current is the tail
    if (nextNode == nullptr)
    {
        previous->next = nullptr;
        current->back = nullptr;

        delete current;
        return;
    }

    // If current is a middle node
    previous->next = nextNode;
    nextNode->back = previous;

    current->next = nullptr;
    current->back = nullptr;

    delete current;
}


// ============================================================
// INSERT AT START
// ============================================================

node* insertAtStart(node *head, int value)
{
    if (head == nullptr)
    {
        return new node(value);
    }

    node *newNode = new node(value, head, nullptr);

    head->back = newNode;

    return newNode;
}


// ============================================================
// INSERT AT TAIL
// ============================================================

node* insertAtTail(node *head, int value)
{
    if (head == nullptr)
    {
        return new node(value);
    }

    node *current = head;

    // Reach the tail
    while (current->next != nullptr)
    {
        current = current->next;
    }

    node *newNode = new node(value, nullptr, current);

    current->next = newNode;

    return head;
}


// ============================================================
// INSERT BEFORE TAIL
// ============================================================

node* insertBeforeTail(node *head, int value)
{
    if (head == nullptr)
    {
        return new node(value);
    }

    // Only one node
    if (head->next == nullptr)
    {
        node *newNode = new node(value, head, nullptr);

        head->back = newNode;

        return newNode;
    }

    node *tail = head;

    // Reach the tail
    while (tail->next != nullptr)
    {
        tail = tail->next;
    }

    node *previous = tail->back;

    node *newNode = new node(value, tail, previous);

    previous->next = newNode;
    tail->back = newNode;

    return head;
}


// ============================================================
// INSERT BEFORE K-th ELEMENT
// ============================================================

node* insertBeforeKthElement(node *head, int value, int k)
{
    // Insert before first element
    if (k == 1)
    {
        return insertAtStart(head, value);
    }

    if (head == nullptr)
        return head;

    node *current = head;
    int count = 1;

    // Find K-th element
    while (current != nullptr)
    {
        if (count == k)
            break;

        count++;
        current = current->next;
    }

    // K is invalid
    if (current == nullptr)
        return head;

    node *previous = current->back;

    node *newNode = new node(value, current, previous);

    previous->next = newNode;
    current->back = newNode;

    return head;
}


// ============================================================
// INSERT BEFORE A GIVEN NODE
// NOTE: node should not be the head
// ============================================================

void insertBeforeNode(node *current, int value)
{
    if (current == nullptr || current->back == nullptr)
        return;

    node *previous = current->back;

    node *newNode = new node(value, current, previous);

    previous->next = newNode;
    current->back = newNode;
}


// ============================================================
// MAIN FUNCTION
// ============================================================

int main()
{
    vector<int> arr = {12, 3, 45, 6, 78, 9, 10};

    node *head = convertArrayToDLL(arr);


    // --------------------------------------------------------
    // DELETE OPERATIONS
    // --------------------------------------------------------

    printDLL(head);

    head = deleteHead(head);
    printDLL(head);

    head = deleteTail(head);
    printDLL(head);

    head = deleteKthElement(head, 4);
    printDLL(head);

    deleteNode(head->next->next);
    printDLL(head);


    // --------------------------------------------------------
    // INSERT OPERATIONS
    // --------------------------------------------------------

    head = insertAtStart(head, 1000);
    printDLL(head);

    head = insertAtTail(head, 42);
    printDLL(head);

    head = insertBeforeTail(head, 500);
    printDLL(head);

    head = insertBeforeKthElement(head, 2000, 6);
    printDLL(head);

    insertBeforeNode(head->next->next, 3000);
    printDLL(head);


    return 0;
}
