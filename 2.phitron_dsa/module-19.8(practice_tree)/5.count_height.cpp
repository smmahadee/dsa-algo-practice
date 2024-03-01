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

void level_order_traverse(Node* root) {
    if (root == NULL) {
        cout << "Empty tree";
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

int count_height(Node* root) {
    if(root == NULL) return 0;

    int leftHeight = count_height(root->left);
    int rightHeight = count_height(root->right);

    return 1 + max(leftHeight, rightHeight);
}

int main() {
    Node* root = create_tree();
    // level_order_traverse(root);

    cout<<count_height(root);

    return 0;
}