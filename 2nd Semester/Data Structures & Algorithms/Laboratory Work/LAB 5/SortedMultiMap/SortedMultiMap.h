#pragma once
//DO NOT INCLUDE SMMITERATOR

//DO NOT CHANGE THIS PART
#include <vector>
#include <utility>
#include <iostream>

typedef int TKey;
typedef int TValue;
typedef std::pair<TKey, TValue> TElem;
#define NULL_TVALUE -111111
#define NULL_TELEM pair<TKey, TValue>(-111111, -111111);
using namespace std;
class SMMIterator;
typedef bool(*Relation)(TKey, TKey);

struct Node {
    int key;
    int value;
    Node* left;
    Node* right;
};

class SortedMultiMap {
	friend class SMMIterator;
    private:
		//TODO - Representation

        Node* root;
        Relation relation;
        int count;

        Node* createNode(TKey key, TValue value) {
            Node* newNode = new Node();
            newNode->key = key;
            newNode->value = value;
            newNode->left = nullptr;
            newNode->right = nullptr;
            return newNode;
        }

        void destroyTree(Node* _root) {
            if (_root != nullptr) {
                destroyTree(_root->left);
                destroyTree(_root->right);
                delete _root;
            }
        }

        Node* insert(Node* tree_root, TKey key, TValue value) {
            if (tree_root == nullptr)
                return createNode(key, value);

            if (key < tree_root->key)
                tree_root->left = insert(tree_root->left, key, value);
            else if (key > tree_root->key)
                tree_root->right = insert(tree_root->right, key, value);
            else if (key == tree_root->key)
                tree_root->value = value;

            return tree_root;
        }

        void findValues(Node* tree_root, TKey key, vector<TValue>& values_vector) const {
            if (tree_root == nullptr)
                return;

            if (key < tree_root->key)
                findValues(tree_root->left, key, values_vector);
            else if (key > tree_root->key)
                findValues(tree_root->right, key, values_vector);
            else if (key == tree_root->key) {
                values_vector.push_back(tree_root->value);
                findValues(tree_root->left, key, values_vector);
                findValues(tree_root->right, key, values_vector);
            }
        }

        Node* findMin(Node* node) {
            while (node->left != nullptr)
                node = node->left;
            return node;
        }

        Node* _delete(Node* tree_root, TKey key, TValue value, bool& removed) {
            if (tree_root == nullptr)
                return nullptr;

            if (key < tree_root->key)
                tree_root->left = _delete(tree_root->left, key, value, removed);
            else if (key > tree_root->key)
                tree_root->right = _delete(tree_root->right, key, value, removed);
            else {
                if (value == tree_root->value) {
                    // Key-value pair found, we delete it
                    Node* temp;
                    removed = true;

                    if (tree_root->left == nullptr) {
                        temp = tree_root->right;
                        delete tree_root;
                        return temp;
                    } else if (tree_root->right == nullptr) {
                        temp = tree_root->left;
                        delete tree_root;
                        return temp;
                    }

                    temp = findMin(tree_root->right);
                    tree_root->key = temp->key;
                    tree_root->value = temp->value;
                    tree_root->right = _delete(tree_root->right, temp->key, temp->value, removed);
                }
            }

            return tree_root;
        }

        void key_in_map(Node* tree_root, TKey key, bool& exist) {
            if (tree_root != nullptr)
            {
                key_in_map(tree_root->left, key, exist);

                if (tree_root->key == key)
                    exist = true;

                key_in_map(tree_root->right, key, exist);
            }
        }

        void go_through_map(Node* smm_root, int& added_count) {
            bool exists = false;

            if (smm_root != nullptr)
            {
                go_through_map(smm_root->left, added_count);

                key_in_map(root, smm_root->key, exists);
                if (!exists) {
                    add(smm_root->key, smm_root->value);
                    added_count++;
                }

                go_through_map(smm_root->right, added_count);
            }
        }

    public:

    // constructor
    SortedMultiMap(Relation r);

	//adds a new key value pair to the sorted multi map
    void add(TKey c, TValue v);

	//returns the values belonging to a given key
    vector<TValue> search(TKey c) const;

	//removes a key value pair from the sorted multimap
	//returns true if the pair was removed (it was part of the multimap), false if nothing is removed
    bool remove(TKey c, TValue v);

    //returns the number of key-value pairs from the sorted multimap
    int size() const;

    //verifies if the sorted multi map is empty
    bool isEmpty() const;

    // returns an iterator for the sorted multimap. The iterator will returns the pairs as required by the relation (given to the constructor)	
    SMMIterator iterator() const;

    int addIfNotPresent(SortedMultiMap& smm);

    // destructor
    ~SortedMultiMap();
};
