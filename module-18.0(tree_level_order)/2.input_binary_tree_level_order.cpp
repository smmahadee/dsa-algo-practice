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
    if (val == -1) {
        root = NULL;
    } else {
        root = new Node(val);
    }
    queue<Node*> q;
    if (root) q.push(root);

    while (!q.empty()) {
        Node* f = q.front();
        q.pop();

        int l, r;
        cin >> l >> r;

        if (l != -1) {
            f->left = new Node(l);
            q.push(f->left);
        } else {
            f->left = NULL;
        }

        if (r != -1) {
            f->right = new Node(r);
            q.push(f->right);
        } else {
            f->right = NULL;
        }
    }

    return root;
}

void print_node(Node* root) {
    if (root == NULL) {
        cout << "No element found" << endl;
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

int main() {
    Node* root = input_binary_tree();
    print_node(root);

    return 0;
}