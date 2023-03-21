
#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
};
class BST
{
    Node *helper;

public:
    Node *root;
    BST()
    {
        root = helper = NULL;
    }

    Node *new_node(int key)
    {
        Node *temp1 = new Node;
        temp1->data = key;
        temp1->left = temp1->right = NULL;

        return temp1;
    }

    void Display_Inoder(Node *temp)
    {
        if (root == NULL)
        {
            return;
        }

        if (temp->left != NULL)
        {
            Display_Inoder(temp->left);
        }

        cout << temp->data << "  ";

        if (temp->right != NULL)
        {
            Display_Inoder(temp->right);
        }

        return;
    }

    void insert(Node *temp, int key)
    {
        //cout<<"insert<<endl"<<endl;
        if (root == NULL)
        {
            temp = new_node(key);
            root = temp;
            return;
        }

        if (temp->data == key)
        {
            cout << "The number is already exists in the Tree" << endl;
            return;
        }

        if (temp->data > key)
        {
            if (temp->left != NULL)
            {
                insert(temp->left, key);
                return;
            }
            else
            {
                temp->left = new_node(key);
                cout << temp->left->data << endl;
                return;
            }
        }
        else
        {
            if (temp->right != NULL)
            {
                insert(temp->right, key);
                return;
            }
            else
            {
                temp->right = new_node(key);
                cout << temp->right->data << endl;
                return;
            }
        }
    }
    Node *minimum_Key(Node *current)
    {
        while (current->left != NULL)
        {
            current = current->left;
        }
        return current;
    }

    void search_Key(Node *&current, int key, Node *&parent)
    {

        while (current != NULL && current->data != key)
        {
            parent = current;

            if (key < current->data)
            {
                current = current->left;
            }
            else
            {
                current = current->right;
            }
        }
    }

    Node *Delete_Node_BST(Node *root, int data)
    {
        Node *parent = NULL;
        Node *current = root;

        search_Key(current, data, parent);

        if (root == NULL)
            return root;

        else
        {
            //Having no child
            if (root->right == NULL && root->left == NULL)
            {
                delete root;
                root = NULL;
            }
            //Having one child
            else if (root->right == NULL)
            {
                Node *temp = root;
                root = root->left;
                delete temp;
            }
            else if (root->left == NULL)
            {
                Node *temp = root;
                root = root->right;
                delete temp;
            }
            //Having two child
            else
            {
                Node *temp = minimum_Key(root->left);
                root->data = temp->data;
                root->left = Delete_Node_BST(root->left, temp->data);
            }
        }
        return root;
    }
};
int main()
{
    BST obj;
    obj.insert(obj.root, 60);
    obj.insert(obj.root, 39);
    obj.insert(obj.root, 63);
    obj.insert(obj.root, 31);
    obj.insert(obj.root, 39);
    obj.insert(obj.root, 49);
    obj.insert(obj.root, 67);
    obj.insert(obj.root, 38);
    cout << "-----DISPLAY FUNCTION-----" << endl;
    obj.Display_Inoder(obj.root);
    cout << endl;
    cout << "-----DELETEION FUNCTION -----" << endl;
    cout << "case 1: If there is no child" << endl;
    obj.Delete_Node_BST(obj.root, 68);
    obj.Display_Inoder(obj.root);
    cout << "\ncase 2: If there is one child" << endl;
    obj.Delete_Node_BST(obj.root, 38);
    obj.Display_Inoder(obj.root);
    cout << "\ncase 3: If there is two child" << endl;
    obj.Delete_Node_BST(obj.root, 40);
    obj.Display_Inoder(obj.root);

    return 0;
}
