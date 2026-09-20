#include <iostream>
#include<stack>
#include<vector>
using namespace std;



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


node* convertArrayToDLL(vector<int>& a)
{
    if (a.empty())
        return nullptr;

    node *head = new node(a[0]);
    node *previous = head;

    for (int i = 1; i < a.size(); i++)
    {
        node *newNode = new node(a[i], nullptr, previous);

        previous->next = newNode;
        previous = newNode;
    }

    return head;
}



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

node *reverseDLL_stack(node *head)
{
    if(head==NULL || head->next==NULL)return head;
    stack<int>st;
  node *temp=head;
    while(temp!=NULL)
        {
            st.push(temp->data);
            temp=temp->next;
        }
    temp=head;
    while(temp!=NULL)
        {
            temp->data=st.top();
            st.pop();
            temp=temp->next;
        }
    return head;
}

node* reverse_DLL_optimal(node *head)
{
    if(head==NULL|| head->next == NULL)
    {
        return head;
    }
    node * current=head;
    node *last=nullptr;

    while(current!=NULL)
    {
        last=current->back;
        current->back=current->next;
        current->next=last;
        current=current->back;
    }
    return last->back;
}


int main()
{
    vector<int> a = {12, 3, 45, 6, 78, 9, 10};

    node *head = convertArrayToDLL(a);

    printDLL(head);

    head=reverse_DLL_optimal(head);

    printDLL(head);

    return 0;
}