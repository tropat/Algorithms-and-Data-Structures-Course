#include <iostream>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    int height;

    Node(int v, Node* l = NULL, Node* r = NULL) {
        val = v;
        left = l;
        right = r;
        height = 1;
    }
};

struct AVL {
    Node* head = NULL;

    int avl_height(Node* n) {
        if(n == NULL) {
            return 0;
        }
        return n->height;
    }

    int avl_balance(Node* n) {
        if(n == NULL) {
            return 0;
        }
        return avl_height(n->left) - avl_height(n->right);
    }

    Node* avl_left_rotate(Node* x) {
        Node* y = x->right;
        Node* z = y->left;
        y->left = x;
        x->right = z;

        y->height = ((avl_height(y->left) > avl_height(y->right))?avl_height(y->left):avl_height(y->right)) + 1;
        x->height = ((avl_height(x->left) > avl_height(x->right))?avl_height(x->left):avl_height(x->right)) + 1;

        return y;
    }

    Node* avl_right_rotate(Node* y) {
        Node* x = y->left;
        Node* z = x->right;
        x->right = y;
        y->left = z;

        y->height = ((avl_height(y->left) > avl_height(y->right))?avl_height(y->left):avl_height(y->right)) + 1;
        x->height = ((avl_height(x->left) > avl_height(x->right))?avl_height(x->left):avl_height(x->right)) + 1;

        return x;
    }

    void avl_inorder(Node* n) {
        if(n != NULL) {
            avl_inorder(n->left);
            cout << n->val << " - ";
            avl_inorder(n->right);
        }
    }

    bool avl_is_empty() {
        return head == NULL;
    }

    Node* avl_insert(Node* node, int v) {
        if (node == NULL)
            return new Node(v);
        if (v < node->val)
            node->left = avl_insert(node->left, v);
        else if (v >= node->val)
            node->right = avl_insert(node->right, v);

        node->height = 1 + avl_height(node->left) > avl_height(node->right)?avl_height(node->left):avl_height(node->right);
        int balance = avl_balance(node);

        if (balance > 1 && v < node->left->val)
        return avl_right_rotate(node);
 
        if (balance < -1 && v > node->right->val)
            return avl_left_rotate(node);
    
        if (balance > 1 && v > node->left->val)
        {
            node->left = avl_left_rotate(node->left);
            return avl_right_rotate(node);
        }
    
        if (balance < -1 && v < node->right->val)
        {
            node->right = avl_right_rotate(node->right);
            return avl_left_rotate(node);
        }

        return node;
    }

    Node* avl_search(int v) {
        Node* tmp = head;
        while(tmp != NULL) {
            if(tmp->val == v) {
                return tmp;
            } else if(tmp->val < v) {
                tmp = tmp->left;
            } else {
                tmp = tmp->right;
            }
        }
        return NULL;
    }

    Node* avl_minVal(Node* n) {
        Node* curr = n;

        while(curr->left != NULL) {
            curr = curr->left;
        }
        return curr;
    }

Node* avl_delete(Node* node, int v)
{
    if (node == NULL)
        return node;

    if ( v < node->val )
        node->left = avl_delete(node->left, v);

    else if( v > node->val )
        node->right = avl_delete(node->right, v);
 
    else{
        if( (node->left == NULL) || (node->right == NULL) ) {
            Node *temp = node->left ? node->left : node->right;

            if (temp == NULL){
                temp = node;
                node = NULL;
            }
            else
            *node = *temp; 
            free(temp);
        }
        else{
            Node* temp = avl_minVal(node->right);
            node->val = temp->val;
            node->right = avl_delete(node->right, temp->val);
        }
    }
    if (node == NULL)
    return node;
 
    node->height = 1 + avl_height(node->left) > avl_height(node->right)?avl_height(node->left):avl_height(node->right);

    int balance = avl_balance(node);
 
    if (balance > 1 &&
        avl_balance(node->left) >= 0)
        return avl_right_rotate(node);
 
    if (balance > 1 && avl_balance(node->left) < 0){
        node->left = avl_left_rotate(node->left);
        return avl_right_rotate(node);
    }
 
    if (balance < -1 && avl_balance(node->right) <= 0)
        return avl_left_rotate(node);
 
    if (balance < -1 && avl_balance(node->right) > 0)
    {
        node->right = avl_right_rotate(node->right);
        return avl_left_rotate(node);
    }
 
    return node;
    }
};

int main() {
    AVL b;

    if(b.avl_is_empty()) cout << "Empty\n";
    b.head = b.avl_insert(b.head, 6);
    if(!b.avl_is_empty()) cout << "Not Empty\n";
    b.avl_inorder(b.head);
    cout << endl;
    b.head = b.avl_insert(b.head, 3);
    b.avl_inorder(b.head);
    cout << endl;
    b.head = b.avl_insert(b.head, 7);
    b.avl_inorder(b.head);
    cout << endl;
    b.head = b.avl_insert(b.head, 5);
    b.avl_inorder(b.head);
    cout << endl;
    b.head = b.avl_insert(b.head, 4);
    b.avl_inorder(b.head);
    cout << endl;
    b.head = b.avl_insert(b.head, 1);
    b.avl_inorder(b.head);
    cout << endl;
    b.avl_delete(b.head, 1);
    b.avl_inorder(b.head);
    cout << endl;
    b.avl_delete(b.head, 5);
    b.avl_inorder(b.head);
    cout << endl;
    b.avl_delete(b.head, 6);
    b.avl_inorder(b.head);
    cout << endl;

    return 0;
}