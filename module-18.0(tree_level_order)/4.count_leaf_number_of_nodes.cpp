#include <iostream>
#include <queue>

using namespace std;

class Node {
   public:
    int val;
    Node* left;
    Node* right;

    Node(int val) {
        this->val = val;
        left = NULL;
        right = NULL;
    }
};

Node* input_binary_tree() {
    int val;
    cin >> val;
    Node* root;
    if (val != -1) {
        root = new Node(val);
    } else {
        root = NULL;
    }

    queue<Node*> q;
    if (root) q.push(root);

    while (!q.empty()) {
        Node* f = q.front();
        q.pop();

        int l, r;
        cin >> l >> r;

        Node* left;
        Node* right;
        if (l == -1) {
            left = NULL;
        } else {
            left = new Node(l);
        }

        if (r == -1) {
            right = NULL;
        } else {
            right = new Node(r);
        }

        if (left) q.push(left);
        if (right) q.push(right);

        f->left = left;
        f->right = right;
    }

    return root;
}

void print_node(Node* root) {
    if (!root) {
        cout << "no element found" << endl;
        return;
    }

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* f = q.front();
        q.pop();

        cout << f->val << " ";

        if (f->left) q.push(f->left);
        if (f->right) q.push(f->right);
    }
}

// 10 20 30 -1 -1 -1 -1

int count_leaf(Node* root) {
    if (root == NULL) return 0;

    int leftTotal = count_leaf(root->left);
    int rightTotal = count_leaf(root->right);

    if (leftTotal == 0 && rightTotal == 0) {
        return 1;
    } else {
        return leftTotal + rightTotal;
    }
}

int main() {
    Node* root = input_binary_tree();
    print_node(root);
    cout << endl << count_leaf(root);

    return 0;
}