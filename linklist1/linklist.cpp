#include <iostream>
#include "node.cpp"
class Pair
{
public:
    Node *head = NULL;
    Node *tail = NULL;
};

using namespace std;

Node *insertNode(Node *head, int pos, int data)
{
    Node *newNode = new Node(data);
    if (pos == 0)
    {
        newNode->next = head;
        return newNode;
    }
    Node *temp = head;
    int count = 0;
    while (temp != NULL && count < pos - 1)
    {
        temp = temp->next;
        count++;
    }
    if (temp != NULL)
    {
        newNode->next = temp->next;
        temp->next = newNode;
    }
    return head;
}
Node *delNode(Node *head, int pos)
{
    if (pos == 0)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
        return head;
    }
    int count = 0;
    Node *temp = head;
    while (temp != NULL && count < pos - 1)
    {
        temp = temp->next;
        count++;
    }
    if (temp != NULL)
    {
        Node *toDel = temp->next;
        temp->next = temp->next->next;
        delete toDel;
    }
    return head;
}

Node *delNode_rec(Node *head, int pos)
{
    if (pos < 0)
    {
        return head;
    }
    if (head == NULL)
    {
        return head;
    }
    if (pos == 0)
    {
        Node *temp = head->next;
        delete head;
        return temp;
    }
    Node *samllAns = delNode_rec(head->next, pos - 1);
    head->next = samllAns;
    return head;
}

Node *takeInput()
{
    int data;
    cin >> data;
    Node *root = NULL;
    while (data != -1)
    {
        Node *newNode = new Node(data);
        if (root == NULL)
        {
            root = newNode;
        }
        else
        {
            Node *temp = root;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newNode;
        }

        cin >> data;
    }
    return root;
}
Node *takeInput_better()
{
    int data;
    cin >> data;
    Node *head = NULL;
    Node *tail = NULL;
    while (data != -1)
    {
        Node *newnode = new Node(data);
        if (head == NULL)
        {
            head = newnode;
            tail = newnode;
        }
        else
        {
            tail->next = newnode;
            tail = newnode;
        }
        cin >> data;
    }
    return head;
}
void print(Node *root)
{
    Node *temp = root;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
int len(Node *head)
{
    if (head == NULL)
    {
        return 0;
    }
    return 1 + len(head->next);
}
int len_it(Node *head)
{
    Node *temp = head;
    int count = 0;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}
Node *insertNode_rec(Node *head, int pos, int data)
{
    if (head == NULL)
    {
        return head;
    }
    if (pos == 0)
    {
        Node *newNode = new Node(data);
        newNode->next = head;
        head = newNode;
        return head;
    }
    Node *smallAns = insertNode_rec(head->next, pos - 1, data);
    head->next = smallAns;
    return head;
}
void printIth(Node *head, int pos)
{
    int length = len(head);
    if (pos > length || pos < 0)
    {
        return;
    }
    int count = 0;
    while (count < pos)
    {
        head = head->next;
        count++;
    }
    cout << head->data << endl;
}
void printMid(Node *head)
{
    int size = len(head);
    int mid = (size - 1) / 2;
    printIth(head, mid);
}

void printMidWithoutLen_even(Node *head)
{
    Node *slow = head;
    Node *fast = head->next;
    while (fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    cout << slow->data << endl;
}
void printMidWithoutLen_odd(Node *head)
{
    Node *slow = head;
    Node *fast = head->next;
    while (fast != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    cout << slow->data << endl;
}
void printMidWithoutLen(Node *head)
{
    Node *slow = head;
    Node *fast = head->next;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    cout << slow->data;
}
Node *mergeTwoSortedLinkList(Node *h1, Node *h2)
{
    Node *fh, *ft = NULL;
    if (h1->data < h2->data)
    {
        fh = h1;
        ft = h1;
        h1 = h1->next;
    }
    else
    {
        fh = h2;
        ft = h2;
        h2 = h2->next;
    }

    while (h1 != NULL && h2 != NULL)
    {
        if (h1->data < h2->data)
        {
            ft->next = h1;
            ft = h1;
            h1 = h1->next;
        }
        else
        {
            ft->next = h2;
            ft = h2;
            h2 = h2->next;
        }
    }
    if (h1 != NULL)
    {
        ft->next = h1;
    }
    if (h2 != NULL)
    {
        ft->next = h2;
    }
    return fh;
}
Node *addOfMid(Node *head)
{
    Node *slow = head;
    Node *fast = head->next;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
Node *mergeSort(Node *head)
{ //basecae
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    Node *mid = addOfMid(head);
    Node *firstHalf = head;
    Node *secondHalf = mid->next;
    //this will break the linklist
    mid->next = NULL;
    Node *h1 = mergeSort(firstHalf);
    Node *h2 = mergeSort(secondHalf);
    return mergeTwoSortedLinkList(h1, h2);
}
Node *reverseLL(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    Node *smallAns = reverseLL(head->next);
    Node *temp = smallAns;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = head;
    head->next = NULL;
    return smallAns;
}
Pair reverse_improved(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        Pair ans;
        ans.head = head;
        ans.tail = head;
        return ans;
    }
    Pair smallAns = reverse_improved(head->next);
    smallAns.tail->next = head;
    head->next = NULL;
    Pair ans;
    ans.head = smallAns.head;
    ans.tail = head;
    return ans;
}
Node *reverseLL_better(Node *head)
{
    return reverse_improved(head).head;
}

//godlevel reverse link list
Node *reverseLL_godLevel(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    Node *smallAns = reverseLL_godLevel(head->next);
    //we have the address of last node that recursion brought to us in out head->next
    head->next->next = head;
    /*
    we can also do this 
    address of our tail is 
    Node* tail=head->next;
    tail->next=head;
    head->next=NULL;
    */

    head->next = NULL;
    return smallAns;
}
Node *reverse_iterative(Node *head)
{
    //initilize prev current and next
    Node *prev = NULL, *current = head, *next = NULL;
    while (current != NULL)
    {   
        //save next node 
        next = current->next;
        //reverse current node to point to previous
        current->next = prev;
        //move pointers one point ahead
        prev = current;
        current = next;
    }
    return prev;

    //we can also directly change head  to prev without returning anything
}
int main()
{
    /*
    //static creation
    Node n1(1);
    Node *head = &n1;

    Node n2(2);
    n1.next = &n2;

    // cout << n1.data << "  " << n2.data << " " << endl;

    //print data of both node using head
    cout << head->data << endl;
    //dynmic allocation
    Node *n3 = new Node(3);
    Node *dRoot = n3;
    Node *n4 = new Node(4);
    n3->next = n4;

    print(head);
    print(dRoot);1
    */
    // Node *head = takeInput_better();
    // print(head);

    // int pos;
    // cin >> pos;

    // printMidWithoutLen_even(head);

    // printMid(head);
    // printIth(head, pos);
    //head = delNode_rec(head, pos);
    //head = insertNode_rec(head, pos, data);
    // head = insertNode(head, pos, data);
    //head = delNode(head, 10);
    // print(head);
    //cout << len_it(head);

    Node *head = takeInput_better();
    print(head);

    // head = mergeSort(head);
    // head = reverseLL_godLevel(head);
    head=reverse_iterative(head);
    print(head);
    return 0;
}
