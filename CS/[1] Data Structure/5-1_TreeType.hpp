// Project 5-1
// binary search tree : pointer
// TreeType.hpp

#ifndef TREETYPE_H
#define TREETYPE_H
#include <iostream>
#include <vector>
#include "2-2_QueueType.hpp" // using Queue


template<typename ItemType>
struct TreeNode{
    ItemType info;
    TreeNode* left;
    TreeNode* right;
};

enum OrderType {PRE_ORDER, IN_ORDER, POST_ORDER};


template<typename ItemType>
class TreeType {
private:
    TreeNode<ItemType>* root;
    int count;
    
    // 0
    void _clear_Recursive(TreeNode<ItemType>*& tree);

    // 1
    void _insertItem_Recurse(TreeNode<ItemType>*& tree, ItemType item);
    void _deleteNode(TreeNode<ItemType>*& tree);
    void _deleteItem_Recurse(TreeNode<ItemType>*& tree, ItemType item);

    // 2
    TreeNode<ItemType>* _findItem_Recurse(TreeNode<ItemType>*& tree, ItemType item);
    void _traverseTree_PreOrder_Recurse(TreeNode<ItemType>* tree, std::vector<ItemType>& itemList);
    void _traverseTree_InOrder_Recurse(TreeNode<ItemType>* tree, std::vector<ItemType>& itemList);
    void _traverseTree_PostOrder_Recurse(TreeNode<ItemType>* tree, std::vector<ItemType>& itemList);
    void _balanceTree_Recurse(const std::vector<ItemType>& linearized, int start, int end);

    // 3
    int _heightOfTree_Recurse(TreeNode<ItemType>* root); // get height of tree
    

public:
    // 0
    TreeType();
    void clear();
    ~TreeType();

    void copyTree(TreeType& copyTo);

    // 1
    void insertItem(ItemType item);
    void deleteItem(ItemType item);

    // 2
    TreeNode<ItemType>* findItem(ItemType item); // returns the address. nullptr if not exist
    std::vector<ItemType> traverseTree(OrderType order);
    std::vector<ItemType> getAncestors(ItemType value);
    void balanceTree();

    bool isEmpty();
    bool isFull();
    int size();

    // 3
    void printTree(TreeNode<ItemType>* tree = nullptr); // Queue required
    void printTree_Linearized(OrderType order);
};





template<typename ItemType>
TreeType<ItemType>::TreeType() {
    root = nullptr;
    count = 0;
}


// clear
template<typename ItemType>
void TreeType<ItemType>::_clear_Recursive(TreeNode<ItemType>*& tree) {
    if (tree == nullptr) return;
    _clear_Recursive(tree->left);
    _clear_Recursive(tree->right);
    delete tree;
}
template<typename ItemType>
void TreeType<ItemType>::clear() {
    _clear_Recursive(root);
    root = nullptr;
    count = 0;
}


template<typename ItemType>
TreeType<ItemType>::~TreeType() {
    this->clear();
}



// Copy
template<typename ItemType>
void TreeType<ItemType>::copyTree(TreeType& copyTo) {
    if (this == &copyTo) return;

    copyTo.clear();
    std::vector<ItemType> linearized = traverseTree(PRE_ORDER);
    for (int i = 0; i < count; i++) {
        copyTo.insertItem(linearized[i]);
    }
}




// Insert
template<typename ItemType>
void TreeType<ItemType>::_insertItem_Recurse(TreeNode<ItemType>*& tree, ItemType item){
    if (tree == nullptr) {
        tree = new TreeNode<ItemType>{ item, nullptr, nullptr };
        count++;
    }
    else if (item < tree->info) {
        _insertItem_Recurse(tree->left, item);
    }
    else {
        _insertItem_Recurse(tree->right, item);
    }
}
template<typename ItemType>
void TreeType<ItemType>::insertItem(ItemType item) {
    _insertItem_Recurse(root, item);
}



// delete
template<typename ItemType>
void TreeType<ItemType>::_deleteNode(TreeNode<ItemType>*& tree) {
    TreeNode<ItemType>* tempNode;
    // if one of both does NOT exist
    if (tree->left == nullptr) {
        tempNode = tree;
        tree = tree->right;
        delete tempNode;
        count--;
    }
    else if (tree->right == nullptr) {
        tempNode = tree;
        tree = tree->left;
        delete tempNode;
        count--;
    }
    else {
        // getPredecessor(tree->left, data);
        tempNode = tree->left;
        while (tempNode->right != nullptr){
            tempNode = tempNode->right;
        }

        tree->info = tempNode->info;
        _deleteItem_Recurse(tree->left, tempNode->info);
    }
}
template<typename ItemType>
void TreeType<ItemType>::_deleteItem_Recurse(TreeNode<ItemType>*& tree, ItemType item) {
    if (tree == nullptr) return;

    if (item == tree->info) { // delete node here
        _deleteNode(tree);
    }
    else if(item < tree->info){
        _deleteItem_Recurse(tree->left, item);
    }
    else if (item > tree->info) {
        _deleteItem_Recurse(tree->right, item);
    }
}
template<typename ItemType>
void TreeType<ItemType>::deleteItem(ItemType item) {
    _deleteItem_Recurse(root, item);
}



// find
template<typename ItemType>
TreeNode<ItemType>* TreeType<ItemType>::_findItem_Recurse(TreeNode<ItemType>*& tree, ItemType item){
    if (tree == nullptr) return nullptr; // left node: not found
    else if (item == tree->info) return tree;

    else if (item < tree->info) {
        return _findItem_Recurse(tree->left, item);
    }
    else if (item > tree->info) {
        return _findItem_Recurse(tree->right, item);
    }
}
template<typename ItemType>
TreeNode<ItemType>* TreeType<ItemType>::findItem(ItemType item) {
    return _findItem_Recurse(root, item);
}



// traverse tree : inOrder, preOrder, postOrder
template<typename ItemType>
void TreeType<ItemType>::_traverseTree_PreOrder_Recurse(TreeNode<ItemType>* tree, std::vector<ItemType>& itemList) {
    if (tree == nullptr) return;

    itemList.push_back(tree->info);
    _traverseTree_PreOrder_Recurse(tree->left, itemList);
    _traverseTree_PreOrder_Recurse(tree->right, itemList);
}
template<typename ItemType>
void TreeType<ItemType>::_traverseTree_InOrder_Recurse(TreeNode<ItemType>* tree, std::vector<ItemType>& itemList) {
    if (tree == nullptr) return;

    _traverseTree_InOrder_Recurse(tree->left, itemList);
    itemList.push_back(tree->info);
    _traverseTree_InOrder_Recurse(tree->right, itemList);
}
template<typename ItemType>
void TreeType<ItemType>::_traverseTree_PostOrder_Recurse(TreeNode<ItemType>* tree, std::vector<ItemType>& itemList) {
    if (tree == nullptr) return;

    _traverseTree_PostOrder_Recurse(tree->left, itemList);
    _traverseTree_PostOrder_Recurse(tree->right, itemList);
    itemList.push_back(tree->info);
}

template<typename ItemType>
std::vector<ItemType> TreeType<ItemType>::traverseTree(OrderType order) {
    std::vector<ItemType> itemList;

    switch (order) {
    case PRE_ORDER:
        _traverseTree_PreOrder_Recurse(root, itemList);
        break;
    case IN_ORDER:
        _traverseTree_InOrder_Recurse(root, itemList);
        break;
    case POST_ORDER:
        _traverseTree_PostOrder_Recurse(root, itemList);
        break;
    }

    return itemList;
}



// get Ancestors
template<typename ItemType>
std::vector<ItemType> TreeType<ItemType>::getAncestors(ItemType value) {
    TreeNode<ItemType>* tree = root;
    std::vector<ItemType> ancestors;

    while (tree != nullptr) {

        if (value == tree->info) return ancestors;
        else if (value < tree->info) {
            ancestors.push_back(tree->info);
            tree = tree->left;
        }
        else if (tree->info < value) {
            ancestors.push_back(tree->info);
            tree = tree->right;
        }
    }

    ancestors.clear();
    return ancestors;
}



// Balance tree
template<typename ItemType>
void TreeType<ItemType>::_balanceTree_Recurse(const std::vector<ItemType>& linearized, int start, int end) {
    if (end <= start) return;

    int mid = (start + end) / 2;
    insertItem(linearized[mid]);

    _balanceTree_Recurse(linearized, start, mid);
    _balanceTree_Recurse(linearized, mid + 1, end);
}
template<typename ItemType>
void TreeType<ItemType>::balanceTree() {
    // linearize
    std::vector<ItemType> linearized = traverseTree(IN_ORDER);

    // clear original tree
    clear();

    // binary search-like and insert into tree
    _balanceTree_Recurse(linearized, 0, count);;
}




// empty, full, size
template<typename ItemType>
bool TreeType<ItemType>::isEmpty() { 
    return (root == nullptr); 
}

template<typename ItemType>
bool TreeType<ItemType>::isFull() {
    TreeNode<ItemType>* location;

    try {
        location = new TreeNode<ItemType>;
        delete location;
        return false;
    }
    catch (std::bad_alloc exception) {
        return true;
    }
}

template<typename ItemType>
int TreeType<ItemType>::size() {
    return count;
}



// Print tree
template<typename ItemType>
int TreeType<ItemType>::_heightOfTree_Recurse(TreeNode<ItemType>* root){
    if (root == NULL) {
        return 0;
    }

    auto max = [](int a, int b) { return (a > b ? a : b); };
    int height = 1 + max(_heightOfTree_Recurse(root->left), _heightOfTree_Recurse(root->right));
    // if(height == n) ...

    return height;
}

template<typename ItemType>
void TreeType<ItemType>::printTree(TreeNode<ItemType>* tree/* = nullptr*/) { // default nullptr <- this means 'starting from root'
    if (isEmpty()) {
        std::cout << "Tree is Empty!\n";
        return;
    }
    if (tree == nullptr) tree = root;


    auto printSpace = [](double n, TreeNode<ItemType>* removed) {
        for (; n > 0; n--) std::cout << "\t";
        if (removed == nullptr) std::cout << " ";
        else std::cout << removed->info;
    };

    QueueType<TreeNode<ItemType>*> treeLevel, temp;
    treeLevel.enqueue(tree);
    int counter = 0;
    int height = _heightOfTree_Recurse(tree) - 1;
    double numberOfElements = pow(2, (height + 1)) - 1;

    while (counter <= height) {
        TreeNode<ItemType>* removed = (treeLevel.dequeue());

        if (temp.isEmpty()) {
            printSpace(numberOfElements
                / pow(2, counter + 1),
                removed);
        }
        else {
            printSpace(numberOfElements / pow(2, counter),
                removed);
        }

        if (removed == nullptr) {
            temp.enqueue(nullptr);
            temp.enqueue(nullptr);
        }
        else {
            temp.enqueue(removed->left);
            temp.enqueue(removed->right);
        }
        if (treeLevel.isEmpty()) {
            std::cout << std::endl << std::endl;
            treeLevel = temp;

            while (!temp.isEmpty()) {
                temp.dequeue();
            }
            counter++;
        }
    }
}



template<typename ItemType>
void TreeType<ItemType>::printTree_Linearized(OrderType order) {
    if (isEmpty()) {
        std::cout << "Tree is Empty!\n";
        return;
    }

    std::vector<ItemType> linearized = traverseTree(order);
    for (int i = 0; i < count; i++) {
        std::cout << linearized[i] << ' ';
    }
    std::cout << '\n';
}

#endif



/* ==== Test Code ====
    TreeType<int> tree;


    std::cout << "[#1]\n";
    tree.insertItem(5);
    tree.insertItem(3);
    tree.insertItem(4);
    tree.insertItem(9);
    tree.insertItem(7);
    tree.insertItem(6);
    tree.insertItem(12);
    tree.insertItem(8);
    tree.insertItem(20);
    tree.insertItem(11);
    tree.insertItem(2);
    tree.insertItem(1);

    tree.printTree();
    tree.printTree_Linearized(IN_ORDER);


    std::cout << "[#2]\n";
    TreeType<int> tree2;
    tree.copyTree(tree2);
    tree2.printTree();
    tree.printTree_Linearized(IN_ORDER);


    std::cout << "[#3]\n";
    tree.clear();
    tree.printTree();
    tree.printTree_Linearized(IN_ORDER);


    std::cout << "[#4]\n";
    std::cout << tree.size() << '\n';
    tree.insertItem(1);
    std::cout << tree.size() << '\n';
    tree.deleteItem(2);
    std::cout << tree.size() << '\n';
    tree.deleteItem(1);
    std::cout << tree.size() << '\n';
    std::cout << tree2.findItem(2)->info << '\n';


    std::cout << "[#5]\n";
    tree2.printTree_Linearized(PRE_ORDER);
    tree2.printTree_Linearized(IN_ORDER);
    tree2.printTree_Linearized(POST_ORDER);


    std::cout << "[#5]\n";
    std::vector<int> t = tree2.getAncestors(20);
    for (int i = 0; i < t.size(); i++) std::cout << t[i] << ' '; std::cout << '\n';

    std::cout << tree2.getAncestors(100).size();


*/