#include <iostream>

#ifndef nullptr
#define nullptr NULL
#endif

template <class K, class D>
class BinaryTree
{
protected:
    struct Node {
        K key;
        D data;
        Node *left, *right;

        Node(K _key, D _data) : key(_key), data(_data), left(nullptr), right(nullptr) {}
        ~Node()
        {
            if (left) {
                delete left;
            }
            if (right) {
                delete right;
            }
            left = right = nullptr;
        }
        void out(std::ostream &stream, unsigned k)
        {
            for (int i = 0; i < k; i++) {
                stream << " ";
            }

            stream << "[" << key << "]\n";

            if (left) {
                left->out(stream, k - 5);
            }

            if(right){
                right->out(stream, k + 5);
            }
        }
    } *root;
public:
    BinaryTree() : root(nullptr) {}
    ~BinaryTree();
    void add(K key, D data, bool override = true);
    D search(K key);
    void remove(K key);
    void out(std::ostream &stream, unsigned k = 50)
    {
        root->out(stream, k);
    }
};