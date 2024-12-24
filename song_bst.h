#pragma once
#ifndef SONG_BST_H
#define SONG_BST_H

#include <string>
#include <iostream>

struct SongNode {
    std::string title;
    std::string videoId;
    SongNode* left;
    SongNode* right;

    SongNode(const std::string& t, const std::string& v)
        : title(t), videoId(v), left(nullptr), right(nullptr) {}
};

class SongBST {
private:
    SongNode* root;

    void insertNode(SongNode*& node, const std::string& title, const std::string& videoId) {
        if (!node) {
            node = new SongNode(title, videoId);
            return;
        }
        if (title < node->title) {
            insertNode(node->left, title, videoId);
        }
        else {
            insertNode(node->right, title, videoId);
        }
    }

    void inOrderTraversal(SongNode* node) const {
        if (!node) return;
        inOrderTraversal(node->left);
        std::cout << "Title: " << node->title << ", Video ID: " << node->videoId << std::endl;
        inOrderTraversal(node->right);
    }

public:
    SongBST() : root(nullptr) {}

    void insert(const std::string& title, const std::string& videoId) {
        insertNode(root, title, videoId);
    }

    void display() const {
        inOrderTraversal(root);
    }
};

#endif
