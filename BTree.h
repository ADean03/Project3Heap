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
    vector<Video> temp;

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
                x->videos[i + 1] = x->videos[i];
                i--;
            }
            x->videos[i + 1] = video;
        }
        else {
            while (i >= 0 && x->videos[i].views > video.views) {
                i--;
            }
            i++;
            if (x->children[i]->videos.size() == (2 * minDegree - 1)) {
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
          //  cout << x->videos[i].title << " - " << x->videos[i].views <<  " -> " << x->videos[i].channel<< endl;
            //root->temp.push_back(x->videos.at(i));

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

    void remove()
    {
        Node* temp = root->children.at(0);
        delete root;
        root = temp;
    }

    void insert(Video video)
    {
        if (root->videos.size() == (2 * minDegree - 1)) {
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


   


    int kSmallest = 0;

    string kthLargest(int k) {
        vector<Video> tempVideo;
        string stringTemp;
        string tempNum;
    /*    for (int i = 1; i < k; i++) {
            if (k > root->videos.size()) {
                break;
            }
            
            remove();
        }
        */
        //{
           
        //cout << "here";
       // traverse(root);

        tempVideo.push_back(printer(root));

        tempNum = to_string(k);
        

        stringTemp.append(tempNum); stringTemp.append("th smallest"); stringTemp.append("\n");
        tempNum = tempVideo.at(0).title;
        stringTemp.append("The title is: "); stringTemp.append(tempNum); stringTemp.append("\n");
        tempNum = tempVideo.at(0).channel;
        stringTemp.append("The channel is: "); stringTemp.append(tempNum); stringTemp.append("\n");
        tempNum = tempVideo.at(0).date;
        stringTemp.append("The date is: "); stringTemp.append(tempNum); stringTemp.append("\n");
        tempNum = to_string(tempVideo.at(0).views);
        stringTemp.append("The views are: "); stringTemp.append(tempNum); stringTemp.append("\n");
        tempNum = (tempVideo.at(0).likes);
        stringTemp.append("The likes are: "); stringTemp.append(tempNum); stringTemp.append("\n");
        tempNum = (tempVideo.at(0).dislikes);
        stringTemp.append("The dislikes are: "); stringTemp.append(tempNum); stringTemp.append("\n");
        cout << stringTemp << endl;
        tempVideo.pop_back();
       /* for (int i = 0; i < root->temp.size(); i++) {
       //     insert(temp.at(i).title, temp.at(i).channel, temp.at(i).date, to_string(temp.at(i).views), to_string(temp.at(i).likes), to_string(temp.at(i).dislikes));
            if (!empty(root->temp)) {
                root->temp.erase(root->temp.begin() + i);
            }
        }*/
        return stringTemp;
    }

    
        Video printer(Node* x)
    {
        int i;
        for (i = 0; i < x->videos.size(); i++) {
            if (!x->isLeaf) {
                printer(x->children[i]);
            }
            //  cout << x->videos[i].title << " - " << x->videos[i].views <<  " -> " << x->videos[i].channel<< endl;
            if (i == kSmallest) {
                return x->videos[i];
            }
              //root->temp.push_back(x->videos.at(i));

        }
        if (!x->isLeaf) {
            printer(x->children[i]);
        }
    }


};





#endif
