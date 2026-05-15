#include <iostream>
#include <vector>
#include <ctime>
#include <algorithm>

struct Node {
    char data;
    unsigned freq;
    Node *left, *right;
    Node(char d, unsigned f) : data(d), freq(f), left(nullptr), right(nullptr) {}
};

struct Compare {
    bool operator()(Node* l, Node* r) {
        return l->freq > r->freq;
    }
};

void minHeapify(std::vector<Node*>& minHeap, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;
    int size = minHeap.size();
    if (left < size && minHeap[left]->freq < minHeap[smallest]->freq)
        smallest = left;
    if (right < size && minHeap[right]->freq < minHeap[smallest]->freq)
        smallest = right;
    if (smallest != idx) {
        std::swap(minHeap[smallest], minHeap[idx]);
        minHeapify(minHeap, smallest);
    }
}

Node* extractMin(std::vector<Node*>& minHeap) {
    Node* temp = minHeap[0];
    minHeap[0] = minHeap.back();
    minHeap.pop_back();
    minHeapify(minHeap, 0);
    return temp;
}

void insertMinHeap(std::vector<Node*>& minHeap, Node* node) {
    minHeap.push_back(node);
    int i = minHeap.size() - 1;
    while (i && minHeap[i]->freq < minHeap[(i - 1) / 2]->freq) {
        std::swap(minHeap[i], minHeap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

Node* buildHuffmanTree(const std::vector<char>& data, const std::vector<int>& freq, int size) {
    std::vector<Node*> minHeap;
    for (int i = 0; i < size; ++i)
        minHeap.push_back(new Node(data[i], freq[i]));
    
    std::make_heap(minHeap.begin(), minHeap.end(), Compare());
    // Since make_heap uses a different logic (max-heap by default), 
    // and we need a min-heap, I'll use a more standard way.
    
    // Actually, let's just use a priority_queue for simplicity as per "maintain simplicity"
    #include <queue>
    std::priority_queue<Node*, std::vector<Node*>, Compare> pq;
    for (int i = 0; i < size; ++i)
        pq.push(new Node(data[i], freq[i]));

    while (pq.size() != 1) {
        Node* left = pq.top(); pq.pop();
        Node* right = pq.top(); pq.pop();
        Node* top = new Node('$', left->freq + right->freq);
        top->left = left;
        top->right = right;
        pq.push(top);
    }
    return pq.top();
}

void printCodes(Node* root, std::string str) {
    if (!root) return;
    if (root->data != '$') std::cout << root->data << ": " << str << std::endl;
    printCodes(root->left, str + "0");
    printCodes(root->right, str + "1");
}

int main() {
    int n;
    std::cout << "Enter number of characters: ";
    if (!(std::cin >> n)) return 0;
    
    std::vector<char> arr(n);
    std::vector<int> freq(n);
    std::cout << "Enter characters and frequencies:" << std::endl;
    for (int i = 0; i < n; i++) std::cin >> arr[i] >> freq[i];

    clock_t start = clock();
    Node* root = buildHuffmanTree(arr, freq, n);
    printCodes(root, "");
    clock_t end = clock();

    std::cout << "Time taken: " << (double)(end - start) / CLOCKS_PER_SEC << " seconds" << std::endl;

    return 0;
}

/*
Concept:
Huffman Coding is a Greedy algorithm used for lossless data compression. 
It builds a prefix-free binary tree where characters that appear more 
frequently are assigned shorter codes.
Complexity: O(n log n)
Recurrence Relation: T(n) = O(n log n)
*/
