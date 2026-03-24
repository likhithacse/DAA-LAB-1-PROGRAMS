#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// Node structure for Huffman Tree
struct Node {
    char data;
    int freq;
    Node *left, *right;

    Node(char d, int f) {
        data = d;
        freq = f;
        left = right = NULL;
    }
};

// Comparator for priority queue (min-heap)
struct Compare {
    bool operator()(Node* l, Node* r) {
        return l->freq > r->freq;
    }
};

// Function to print Huffman Codes
void printCodes(Node* root, string str) {
    if (!root)
        return;

    // If leaf node, print character and code
    if (root->data != '$')
        cout << root->data << " : " << str << endl;

    printCodes(root->left, str + "0");
    printCodes(root->right, str + "1");
}

// Main function to build Huffman Tree
void HuffmanCodes(char data[], int freq[], int size) {

    priority_queue<Node*, vector<Node*>, Compare> pq;

    // Create leaf nodes and push into priority queue
    for (int i = 0; i < size; i++) {
        pq.push(new Node(data[i], freq[i]));
    }

    // Build the tree
    while (pq.size() != 1) {
        Node *left = pq.top(); pq.pop();
        Node *right = pq.top(); pq.pop();

        // Create new internal node
        Node *newNode = new Node('$', left->freq + right->freq);
        newNode->left = left;
        newNode->right = right;

        pq.push(newNode);
    }

    // Print Huffman Codes
    printCodes(pq.top(), "");
}

int main() {
    char data[] = {'A', 'B', 'C', 'D'};
    int freq[] = {5, 2, 1, 1};

    int size = sizeof(data) / sizeof(data[0]);

    cout << "Huffman Codes:\n";
    HuffmanCodes(data, freq, size);

    return 0;
}