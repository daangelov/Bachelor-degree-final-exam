#include <iostream>
#include <fstream>
#include <queue>
#include <string>

using namespace std;

class Node
{
public:
    char value;
    Node* left;
    Node* middle;
    Node* right;

    int level;

    Node(char value)
    {
        this->value = value;
        this->level = 0;

        this->left = nullptr;
        this->middle = nullptr;
        this->right = nullptr;
    }

    Node* setLeft(char value)
    {
        Node* newNode = new Node(value);
        newNode->level = this->level + 1;
        this->left = newNode;

        return this->left;
    }

    Node* setMiddle(char value)
    {
        Node* newNode = new Node(value);
        newNode->level = this->level + 1;
        this->middle = newNode;

        return this->middle;
    }

    Node* setRight(char value)
    {
        Node* newNode = new Node(value);
        newNode->level = this->level + 1;
        this->right = newNode;

        return this->right;
    }
};

class TernaryTree
{
public:
    Node* root;
    int depth;

    TernaryTree(Node* root)
    {
        this->root = root;
    }
};

string readLast(TernaryTree* tree)
{
    queue<Node*> q;
    q.push(tree->root);

    int currLevel = 0;
    string word;

    while(!q.empty())
    {
        Node* currNode = q.front();
        q.pop();

        if (currNode->level > currLevel)
        {
            word = "";
            currLevel = currNode->level;
        }

        word += currNode->value;

        if (currNode->left != nullptr)
        {
            q.push(currNode->left);
        }
        if (currNode->middle != nullptr)
        {
            q.push(currNode->middle);
        }
        if (currNode->right != nullptr)
        {
            q.push(currNode->right);
        }
    }

    return word;
}

void DFS(Node* node, string &text) {

    if (node == nullptr) {
        text += " *";
        return;
    }
    text += " (";
    text += node->value;

    DFS(node->left, text);
    DFS(node->middle, text);
    DFS(node->right, text);

    text += ")";
}

void serialize(TernaryTree* tree, string file)
{
    string result = "";
    DFS(tree->root, result);

    ofstream myFile;
    myFile.open(file);
    myFile << result;
    myFile.close();
}

int main()
{
    Node* root = new Node('b');

    Node* x = root->setLeft('x');
    Node* y = root->setMiddle('y');

    x->setLeft('p');
    x->setMiddle('q');
    Node* r = x->setRight('r');
    Node* s = y->setRight('s');

    r->setLeft('c');
    r->setRight('a');
    s->setMiddle('t');

    TernaryTree* newT = new TernaryTree(root);

    string result = readLast(newT);
    cout << result << '\n';

    serialize(newT, "result.txt");
    return 0;
}
