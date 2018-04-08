//
// Created by maciej on 31.03.18.
//

#include "SmartTree.h"

using std::unique_ptr;
using std::ostream;
using std::string;
using std::make_unique;
using std::cout;

namespace datastructures{
    unique_ptr <SmartTree> CreateLeaf(int value){
        auto Leaf = make_unique<SmartTree>();
        Leaf->left = nullptr;
        Leaf->right = nullptr;
        Leaf->value = value;
        return Leaf;
    }

    unique_ptr <SmartTree> InsertLeftChild(unique_ptr<SmartTree> tree, unique_ptr<SmartTree> left_subtree){
        if(tree->left == nullptr)
            tree->left = std::move(left_subtree);
        return tree;
    }

    unique_ptr<SmartTree> InsertRightChild(unique_ptr<SmartTree> tree, unique_ptr<SmartTree> right_subtree) {
        if(tree->right == nullptr)
            tree->right = std::move(right_subtree);
        return tree;
    }

    void PrintTreeInOrder(const unique_ptr<SmartTree> &unique_ptr, ostream *out){
        if(unique_ptr != nullptr) {
            PrintTreeInOrder(unique_ptr->left, out);
            *out << unique_ptr->value << ", ";
            PrintTreeInOrder(unique_ptr->right, out);
        }
    }

    string DumpTree(const unique_ptr<SmartTree> &tree){
        string output = "";
        if(tree != nullptr) {
            output =   "[" + output + std::to_string(tree->value) + " ";
            output = output + DumpTree(tree->left);
            output = output + " " + DumpTree(tree->right) + "]";
        }
        else output += "[none]";
        return output;
    }

    unique_ptr <SmartTree> RestoreTree(const string &tree){
    }
}