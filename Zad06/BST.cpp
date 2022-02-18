#include <iostream>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;

    Node(int v, Node* l = NULL, Node* r = NULL) {
        val = v;
        left = l;
        right = r;
    }
};

struct BST {
    Node* head = NULL;

    void bst_inorder(Node* n) {
        if(n != NULL) {
            bst_inorder(n->left);
            cout << n->val << " - ";
            bst_inorder(n->right);
        }
    }

    bool bst_is_empty() {
        return head == NULL;
    }

    void bst_insert(int v) {
        if(bst_is_empty()) {
            head = new Node(v);
        } else {
            Node* tmp = head;
            while(true) {
                if(v < tmp->val) {
                    if(tmp->left == NULL) {
                        tmp->left = new Node(v);
                        break;
                    } else {
                        tmp = tmp->left;
                    }
                } else {
                    if(tmp->right == NULL) {
                        tmp->right = new Node(v);
                        break;
                    } else {
                        tmp = tmp->right;
                    }
                }
            }
        }
    }

    Node* bst_search(int v) {
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

    Node* bst_minVal(Node* n) {
        Node* curr = n;
        Node* prev = NULL;

        while(curr->left != NULL) {
            prev = curr;
            curr = curr->left;
        }

        if(prev!=NULL) {
            prev->left = NULL;
        }

        return curr;
    }

    void bst_delete(int v) {
        Node* tmp = head;
        Node* prev = NULL;

        if(tmp != NULL && tmp->val == v) {
            if(tmp->right == NULL && tmp->left == NULL) head = NULL;
            else if(tmp->left == NULL) head = tmp->right;
            else if(tmp->right == NULL) head = tmp->left;
            else {
                Node* replacement = bst_minVal(tmp->right);
                replacement->left = tmp->left;
                if(tmp->right != replacement) {
                    replacement->right = tmp->right;
                } else {
                    replacement->right = NULL;
                }
                head = replacement;
            }
            tmp = NULL;
        }

        while(tmp != NULL) {
            if(tmp->val < v) {
                prev = tmp;
                tmp = tmp->right;
            } else if(tmp->val > v) {
                prev = tmp;
                tmp = tmp->left;
            } else {
                if(tmp->left == NULL && tmp->right == NULL) {
                    if(tmp == prev->left) {
                        prev->left = NULL;
                    } else if(tmp == prev->right) {
                        prev->right = NULL;
                    }
                } else if(tmp->left == NULL) {
                    if(prev->left == tmp) {
                        prev->left = tmp->right;
                    } else if(prev->right == tmp) {
                        prev->right = tmp->right;
                    }
                } else if(tmp->right == NULL) {
                    if(prev->left == tmp) {
                        prev->left = tmp->left;
                    } else if(prev->right == tmp) {
                        prev->right = tmp->left;
                    }
                } else {
                    Node* replacement = bst_minVal(tmp->right);
                    replacement->left = tmp->left;
                    replacement->right = tmp->right;
                    if(prev->left == tmp) {
                        prev->left = replacement;
                    } else if(prev->right == tmp) {
                        prev->right = replacement;
                    }
                }
                tmp = NULL;
            }
        }
    }
};

int main() {
    BST b;

    if(b.bst_is_empty()) cout << "Empty\n";
    b.bst_insert(6);
    if(!b.bst_is_empty()) cout << "Not Empty\n";
    b.bst_inorder(b.head);
    cout << endl;
    b.bst_insert(3);
    b.bst_insert(7);
    b.bst_insert(5);
    b.bst_insert(4);
    b.bst_insert(1);
    b.bst_inorder(b.head);
    cout << endl;
    b.bst_delete(1);
    b.bst_inorder(b.head);
    cout << endl;
    b.bst_delete(5);
    b.bst_inorder(b.head);
    cout << endl;
    b.bst_delete(6);
    b.bst_inorder(b.head);
    cout << endl;

    return 0;
}