#include<iostream>
using namespace std;

class Node{
  private:
    int data;
    Node * left;
    Node * right;
  public:
    Node(int d, Node *l, Node * r){
        data = d;
        left = l;
        right = r;
    }
    friend class BST;
};
class BST{
  private:
    Node * root;
    Node * tmp;
    void preorder(Node *);
    void inorder(Node *);
    void postorder(Node *);
	Node * find(Node *, int);
    void insert(Node *, int);
    void del(Node *, int );
  public:
    BST();
    void insert(int);
    void del(int);
    Node * find(int);
    void preorder();
    void inorder();
    void postorder();
    Node * maximum(Node *);
	Node * minimum(Node *);
};

BST::BST(){
   root = NULL;
}
Node * BST::maximum(Node *node){
	while(node->right!=NULL) {
		node = node->right;
	}
	return node;
}

Node * BST::minimum(Node *node){
	while(node->left!=NULL) {
		node = node->left;
	}
	return node;
}

void BST::del(int e){
    return del(root, e);
}
void BST::del(Node *n, int x)
{
    if(root == NULL)
    {
        cout << "BST is empty" << endl;
    }
    else
    {
        Node * current =n;
        Node * temp;
        Node * t = NULL;

        while(current -> data != x)
        {
            temp = current;

            if(current->data < x)
            {
                if(current->right ==NULL)
                {
                    current = NULL;
                    break;
                }
                current = current->right;
            }
            else if(current->data > x)
            {
                if(current->left == NULL)
                {
                    current = NULL;
                    break;
                }
                current = current->left;
            }
        }

        if(current ==NULL)
        {
            cout << "Data does not exist in tree" << endl;
        }
        // case 1 : right || left tree no child
        else if(current->left == NULL && current->right == NULL)
        {
            if(temp->right == current)
            {
                temp->right = NULL;
            }
            else
            {
                temp->left = NULL;
            }
            delete current;
            cout << "Node has been deleted " << endl;
        }
        //case 2 : RIGHT OR LEFT ONE CHILD NODE
        else if((current->right == NULL && current->left != NULL)||
                (current->left == NULL && current->right != NULL))
        {
            if(current->right == NULL)
            {
                if(current->left->data < temp->data)
                {
                    temp->left = current->left;
                }
                else
                {
                    temp->right = current->right;
                }
                cout << current->data <<" has been deleted." << endl;
                delete current;
            }
            else
            {
                if(current->right->data < temp->data)
                {
                    temp->left = current->right;
                }
                else
                {
                    temp->right = current->left;
                }
                cout << current->data <<" has been deleted." << endl;
                delete current;
            }
        }
        //case 3: Node has 2 children
        else if(current->left != NULL && current->right != NULL)
        {
            current->data = current->right->data;
            temp = current->right;
            current->right = temp->right;

            if(temp->left != NULL)
            {
                t = temp->left;
            }

            delete temp;
            temp = current->right;

            while(temp != NULL)
            {
                temp = temp->left;
            }

            if(t != NULL)
            {
                temp->left = t;
            }
        }
         delete t;
    }
}

void BST::insert(int e){
	return insert(root, e);
}

void BST::insert(Node *n, int e){
	Node *m = new Node(e, NULL, NULL);
	if(root == NULL){
		root = m;
		return;
	}
	else{
		if(e < n->data){
			if(n->left == NULL)
				n->left = m;
			else
				return insert(n->left, e);
		}
		else{
			if(e > n->data){
				if(n->right == NULL)
					n->right = m;
				else
					return insert(n->right, e);
			}
		}
	}
}
Node* BST::find(int k){
    return find(root, k);
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
void BST::postorder(){
	postorder(root);
	cout<<endl;
}

void BST::postorder(Node *n){
	if(n != NULL){
		postorder(n->left);
		postorder(n->right);
        cout<<n->data<<" ";
    }
}

void BST::inorder(){
	inorder(root);
	cout<<endl;
}

void BST::inorder(Node *n){
	if(n != NULL){
		inorder(n->left);
        cout<<n->data<<" ";
        inorder(n->right);
    }
}

void BST::preorder(){
    preorder(root);
    cout<<endl;
}

void BST::preorder(Node * n){
    if(n != NULL){
       cout<<n->data<<" ";
       preorder(n->left);
       preorder(n->right);
    }
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

    b.inorder(); // 5 8 11 20
    b.preorder(); // 8 5 20 11
    b.postorder(); // 5 11 20 8
    cout<<endl;
    b.del(10);
    b.del(15);

    b.inorder(); // 5 8 11 20
    b.preorder(); // 8 5 20 11
    b.postorder(); // 5 11 20 8
    cout<<endl;



    /*b.del(3);

    b.inorder(); // 5 8 11 20
    b.preorder(); // 8 5 20 11
    b.postorder(); // 5 11 20 8
    cout<<endl;*/

    if(b.find(100) == NULL){
        cout<<"oldsongui";
    }

}
