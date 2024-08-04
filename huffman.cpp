#include <iostream>
#include <queue>
#include <vector>

// A node in the Huffman tree
struct Node {
    char ch;
    int freq;
    Node* left;
    Node* right;
};

// Compare nodes based on frequency
struct compare {
    bool operator()(Node* a, Node* b) {
        return a->freq > b->freq;
    }
};

// Build the Huffman tree
Node* buildHuffmanTree(std::vector<Node*> nodes) {
    std::priority_queue<Node*, std::vector<Node*>, compare> pq;
    for (auto node : nodes) {
        pq.push(node);
    }

    while (pq.size() > 1) {
        Node* left = pq.top();
        pq.pop();
        Node* right = pq.top();
        pq.pop();

        Node* internal = new Node();
        internal->freq = left->freq + right->freq;
        internal->left = left;
        internal->right = right;

        pq.push(internal);
    }

    return pq.top();
}

// Perform preorder traversal
void preorderTraversal(Node* node, std::string code) {
    if (node == nullptr) return;

    if (node->ch != '$') {
        std::cout << node->ch << ": " << code << std::endl;
    }

    preorderTraversal(node->left, code + "0");
    preorderTraversal(node->right, code + "1");
}

int main() {
    int n;
    std::cout << "Enter the number of characters: ";
    std::cin >> n;

    std::vector<Node*> nodes;
    for (int i = 0; i < n; i++) {
        char ch;
        int freq;
        std::cout << "Enter character " << i + 1 << ": ";
        std::cin >> ch;
        std::cout << "Enter frequency " << i + 1 << ": ";
        std::cin >> freq;

        Node* node = new Node();
        node->ch = ch;
        node->freq = freq;
        nodes.push_back(node);
    }

    Node* root = buildHuffmanTree(nodes);

    std::cout << "Huffman codes:" << std::endl;
    preorderTraversal(root, "");

    return 0;
}