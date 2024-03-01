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

Node* create_tree() {
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

        f->left = left;
        f->right = right;
    }

    return root;
}

void pre_order_traverse(Node* root) {
    if (root == NULL) return;

    cout << root->val << " ";

    pre_order_traverse(root->left);
    pre_order_traverse(root->right);
}

void post_order_traverse(Node* root) {
    if (root == NULL) return;


    pre_order_traverse(root->left);
    pre_order_traverse(root->right);

    cout << root->val << " ";
}

void in_order_traverse(Node* root) {
    if (root == NULL) return;


    pre_order_traverse(root->left);
    cout << root->val << " ";
    pre_order_traverse(root->right);
}

int main() {
    Node* root = create_tree();
    // pre_order_traverse(root);
    post_order_traverse(root);
    in_order_traverse(root);

    return 0;
}