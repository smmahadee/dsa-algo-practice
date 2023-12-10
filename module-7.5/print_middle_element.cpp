#include <iostream>

using namespace std;

class Node {
   public:
    int val;
    Node *next;

    Node(int val) {
        this->val = val;
        this->next = NULL;
    }
};

void insert(Node *&head, Node *&tail, int val) {
    Node *newNode = new Node(val);

    if (head == NULL) {
        head = newNode;
        tail = head;
        return;
    }

    tail->next = newNode;
    tail = newNode;
}

void display(Node *head) {
    while (head != NULL) {
        cout << head->val << " ";
        head = head->next;
    }
}

int count(Node *head) {
    int len = 0;
    while (head != NULL) {
        len++;
        head = head->next;
    }

    return len;
}

void reverse_by_value(Node *head) {
    int totalEl = count(head);
    int arr[totalEl];
    int i = 0;

    Node *p = head;

    while (p != NULL) {
        arr[i++] = p->val;
        p = p->next;
    }

    p = head;
    i--;

    while (p != NULL) {
        p->val = arr[i--];
        p = p->next;
    }
}

void printMiddleElement(Node *head) {
    Node *q = NULL;

    int totalCount = count(head) / 2 + 1;

    for (int i = 1; i < totalCount; i++) {
        q = head;
        head = head->next;
    }

    if (totalCount % 2 == 0) {
        cout << q->val << " " << head->val;
    } else {
        cout << head->val;
    }
}

int main() {
    Node *head = NULL;
    Node *tail = NULL;
    cout << "Enter first linked list element: ";
    int val;
    while (true) {
        cin >> val;
        if (val == -1) break;
        insert(head, tail, val);
    }

    // reverse_by_value(head);
    display(head);
    cout<<endl;
    printMiddleElement(head);

    return 0;
}