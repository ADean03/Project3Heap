#ifndef BTREE_H
#define BTREE_H

#include <iostream>
#include <vector>
#include "Video.h"
using namespace std;

// Node of BTree
class Node 
{
public:
    vector<Video> videos;
    vector<Node*> children;
    bool isLeaf;

    Node(bool isLeaf) 
    {
        this->isLeaf = isLeaf;
    }

    ~Node() 
    {
        for (auto child : children) {
            delete child;
        }
    }
};

// BTree
class BTree 
{
 private:
    Node* root;
    int minDegree;

    void insertNonFull(Node* x, Video video) 
    {
        int i = x->videos.size() - 1;
        if (x->isLeaf) {
            x->videos.push_back(video);
            while (i >= 0 && x->videos[i].views > video.views) {
                x->videos[i+1] = x->videos[i];
                i--;
            }
            x->videos[i+1] = video;
        }
        else {
            while (i >= 0 && x->videos[i].views > video.views) {
                i--;
            }
            i++;
            if (x->children[i]->videos.size() == (2*minDegree - 1)) {
                splitChild(x, i, x->children[i]);
                if (x->videos[i].views < video.views) {
                    i++;
                }
            }
            insertNonFull(x->children[i], video);
        }
    }

    void splitChild(Node* x, int i, Node* y) 
    {
        Node* z = new Node(y->isLeaf);
        z->videos.assign(y->videos.begin() + minDegree, y->videos.end());
        y->videos.erase(y->videos.begin() + minDegree, y->videos.end());
        if (!y->isLeaf) {
            z->children.assign(y->children.begin() + minDegree, y->children.end());
            y->children.erase(y->children.begin() + minDegree, y->children.end());
        }
        x->videos.insert(x->videos.begin() + i, y->videos[minDegree - 1]);
        x->children.insert(x->children.begin() + i + 1, z);
        y->videos.erase(y->videos.begin() + minDegree - 1);
        x->isLeaf = false;
    }

    void traverse(Node* x) 
    {
        int i;
        for (i = 0; i < x->videos.size(); i++) {
            if (!x->isLeaf) {
                traverse(x->children[i]);
            }
            cout << x->videos[i].title << " - " << x->videos[i].views << endl;
        }
        if (!x->isLeaf) {
            traverse(x->children[i]);
        }
    }    

 public:
    BTree(int minDegree) 
    {
        this->minDegree = minDegree;
        root = new Node(true);
    }

    ~BTree() 
    {
        delete root;
    }

    void insert(Video video) 
    {
        if (root->videos.size() == (2*minDegree - 1)) {
            Node* s = new Node(false);
            s->children.push_back(root);
            splitChild(s, 0, root);
            insertNonFull(s, video);
            root = s;
        }
        else {
            insertNonFull(root, video);
        }
    }

    void traverse() 
    {
        traverse(root);
    }
};

#endif