#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

class Node
{

public:
    Node* next;
    Node* nextK;
    int value;
};

class List
{

public:
    Node* head;
    int n;
    int k;

    void print()
    {
        Node* currNode = this->head;

        cout << "n: " << this->n << '\n';
        cout << "k: " << this->k << '\n';

        for (int i = 0; i < n; ++i)
        {
            cout << currNode->value << '\n';
            cout << "Next: " << (currNode->next ? currNode->next->value : -1) << '\n';
            cout << "NextK: " << (currNode->nextK ? currNode->nextK->value : -1) << '\n';

            currNode = currNode->next;
        }
    }
};

List* readList(char* file)
{

    ifstream myFile;
    myFile.open(file);

    if (!myFile.is_open())
    {
        return nullptr;
    }

    List* newList = new List();

    Node* currNode = newList->head;
    char number[16];
    while(myFile >> number)
    {
        Node* newNode = new Node();
        newNode->value = atoi(number);

        if (!currNode)
        {
            newList->head = newNode;
            currNode = newList->head;
        }
        else
        {
            currNode->next = newNode;
            currNode = currNode->next;
        }
        newList->n++;
    }

    newList->k = ceil(sqrt(newList->n));

    if (newList->k > 0)
    {
        Node* currKNode = newList->head;
        currNode = newList->head;

        for (int i = 1; i < newList->n; ++i)
        {
            currNode = currNode->next;
            if (i % newList->k == 0)
            {
                currKNode->nextK = currNode;
                currKNode = currNode;
            }
        }
    }

    myFile.close();

    return newList;
}

bool member(List* l, int value)
{
    Node* currNode = l->head;
    Node* prevNode = l->head;
    for (int i = 0; i < l->n; i+=l->k) {

        if (l->head->value > value) {
            return false;
        }

        if (currNode->value == value) {
            return true;
        }

        if (currNode->value < value) {
            prevNode = currNode;
            currNode = currNode->nextK;
            continue;
        }

        // currNode->value > value
        for (int j = 0; j < l->k; ++j) {
            if (prevNode->next->value == value) {
                return true;
            }
            // else
            prevNode = prevNode->next;
        }
        return false;
    }
    return false;
}

int main()
{

    List* newList = readList("test.txt");
    //newList->print();

    cout << member(newList, 7);
    return 0;
};
