#include <iostream>

using namespace std;

class Node{
private:
    int data;
    Node *right;
    Node *left;
    Node *parent;
public:
    Node(int e){
        data = e;
        right = NULL;
        left = NULL;
        parent = NULL;
    }
    friend class BST;
};
class BST{
    private:
        Node * root;
        void insert(Node *, int);
        void del(Node *, int);
        void inorder(Node *);
        void preorder(Node *);
        void postorder(Node *);
        Node * maximum(Node *);
        Node * minimum(Node *);
        Node * find(Node *, int);
        Node * find_parent(Node *, int);
    public:
        BST();
        void insert(int);
        void inorder();
        void preorder();
        void postorder();
        Node* find(int);
        void del(int);
        int maximum();
        int minimum();
        Node * find_parent(int);
};
BST::BST(){
    root = NULL;
}
Node *BST::find_parent(int e){
    find_parent(root, e);
}
Node *BST::find_parent(Node *node, int e){
    if(node->right->data == e){
        return node;
    }else{
        if(node->data > e){
            find_parent(node->left, e);
        }
        if(node->right->data < e){
            find_parent(node->right, e);
        }
    }
        if(node->right->data == e){
            return node;
        }else{
            if(node->data > e){
                find_parent(node->left, e);
            }
            else if(node->data < e){
                find_parent(node->right, e);
            }
        }

    if(node->left->data == e){
        return node;
    }else{
        if(node->data > e){
                find_parent(node->left, e);
            }
            else if(node->data < e){
                find_parent(node->right, e);
            }
    }
}
Node* BST::find(int e){
    return find(root, e);
}
Node *BST::find(Node *node, int data){
    if(node == NULL || node->data == data){
        return node;
    }else{
        if(data < node->data){
            find(node->left, data);
        }else{
            find(node->right, data);
        }
    }
}
void BST::del(int e){
    //cout << root;
    del(root, e);
}
void BST::del(Node *node, int data){
    Node *a = find(node,data);
    Node *nud;
    if(a==NULL){
        return;
    }
    else{
        nud = a;
    }
    if(nud->data == data){
        if(nud->left != NULL && nud->right != NULL){
            Node *y = maximum(nud->left);
            Node *y1 = maximum(nud->right);
            if(y1->data > y->data){
                y = y1;
            }else{
                y = y;
            }
            nud->data = y->data;
            del(y,y->data);
        }
        else if(nud->right == NULL && nud->left == NULL){
            if(nud->parent->left == nud){
                nud->parent->left = NULL;
                delete(nud);
                return;
            }
            if(nud->parent->right == nud){
                nud->parent->right = NULL;
                delete(nud);
                return;
            }
        }
        else if(nud->right == NULL || nud->left == NULL){
            if(nud->right != NULL){
                Node *y = maximum(nud);
                nud->data = y->data;
                del(y,y->data);
                return;
            }else if(nud->left != NULL){
                Node *y = maximum(nud->left);
                nud->data = y->data;
                del(y,y->data);
                return;
            }
        }
    }
    else if(nud->data > data){
        if(nud->left != NULL)  del(nud->left, data);
        else    return;
    }
    else if(nud->data < data){
        if(nud->right != NULL) del(nud->right, data);
        else return;
    }
}
void BST::insert(int e){
    if(root == NULL)
        root = new Node(e);
    else
    insert(root,e);
}

void BST::insert(Node *node, int data){
    if(data < node->data){
        if(node->left == NULL){
            node->left = new Node(data);
            node->left->parent = node;
        }
        else{
            insert(node->left, data);
        }
    }
    else if(data > node->data){
        if(node->right == NULL){
            node->right = new Node(data);
            node->right->parent = node;
        }
        else{
            insert(node->right, data);
        }
    }
}

void BST::inorder(){
    inorder(root);
}
void BST::postorder(){
    postorder(root);
}
void BST::preorder(){
    preorder(root);
}
void BST::inorder(Node *n){
    if(n != NULL){
        inorder(n->left);
        cout<<n->data<<" ";
        inorder(n->right);
    }
}
void BST::postorder(Node *n){
    if(n != NULL){
    postorder(n->left);
    postorder(n->right);
    cout<<n->data<<" ";
    }
}
void BST::preorder(Node *n){
    if(n != NULL){
    cout<<n->data<<" ";
    preorder(n->left);
    preorder(n->right);
    }
}
int BST::maximum(){
    maximum(root)->data;
}
int BST::minimum(){
    minimum(root)->data;
}
Node *BST::maximum(Node *n){
    if(n->right == NULL) return n;
    maximum(n->right);
}
Node *BST::minimum(Node *n){
    if(n->left == NULL) return (Node*)n->data;
    minimum(n->left);
}

int main(){
    BST b;
    b.insert(20);
    b.insert(3);
    b.insert(1);
    b.insert(18);
    b.insert(10);
    b.insert(15);
    b.insert(12);
    b.insert(17);
    b.del(20);
    b.del(1);
    b.preorder();
    cout<<endl;
    b.postorder();
    cout << endl;
    b.inorder();
    cout << endl;

}
