/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   main.cpp
 * Author: uyanda
 *
 * Created on 13 April 2020, 6:37 PM
 */

#include <iostream>
#include <vector>

using namespace std;

/*
 *
 */

class Node
{
    public:
    int data;
    Node* left;
    Node* right;
};


Node* newNode(int data);

void loadLevel (vector<Node>& treelist);
void outputLevel (vector<Node*>& treelist);
void levelOrder(Node * root);

int main(int argc, char** argv) {

    Node *root = newNode(1);

    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    levelOrder(root);


    return 0;
}

Node* newNode(int data)
{
    Node* root = new Node();
    root->data = data;
    root->left = NULL;
    root->right = NULL;

    return(root);
}


void loadLevel (vector<Node*>& treelist)
{
    vector<Node*> temp;

    int vectorSize = treelist.size();

    for (int i = 0; i < vectorSize; i++)
    {
        if (treelist.at(i)->left != NULL)
        {
            temp.push_back(treelist.at(i)->left);
        }

        if (treelist.at(i)->right != NULL)
        {
            temp.push_back(treelist.at(i)->right);
        }
    }

    treelist.clear();

    for(int i = 0; i < temp.size(); i++)
    {
        treelist.push_back(temp.at(i));
    }
    temp.clear();
}


void outputLevel (vector<Node*>& treelist)
{
    for (int i = 0; i < treelist.size(); i++)
    {
        cout << treelist.at(i)->data << " ";
    }
}

void levelOrder(Node * root)
{
    vector<Node*> treelist;
    treelist.push_back(root);

    int vectorSize = treelist.size();


    while (vectorSize > 0)
    {
        outputLevel (treelist);
        loadLevel (treelist);


        vectorSize = treelist.size();
    }


}
