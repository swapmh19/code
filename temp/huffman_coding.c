#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Node {
    char data;
    unsigned freq;
    struct Node *left, *right;
};

struct MinHeap {
    unsigned size;
    unsigned capacity;
    struct Node** array;
};

struct Node* newNode(char data, unsigned freq) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->left = temp->right = NULL;
    temp->data = data;
    temp->freq = freq;
    return temp;
}

void swapNodes(struct Node** a, struct Node** b) {
    struct Node* t = *a;
    *a = *b;
    *b = t;
}

void minHeapify(struct MinHeap* minHeap, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;
    if (left < minHeap->size && minHeap->array[left]->freq < minHeap->array[smallest]->freq)
        smallest = left;
    if (right < minHeap->size && minHeap->array[right]->freq < minHeap->array[smallest]->freq)
        smallest = right;
    if (smallest != idx) {
        swapNodes(&minHeap->array[smallest], &minHeap->array[idx]);
        minHeapify(minHeap, smallest);
    }
}

struct Node* extractMin(struct MinHeap* minHeap) {
    struct Node* temp = minHeap->array[0];
    minHeap->array[0] = minHeap->array[minHeap->size - 1];
    --minHeap->size;
    minHeapify(minHeap, 0);
    return temp;
}

void insertMinHeap(struct MinHeap* minHeap, struct Node* minHeapNode) {
    ++minHeap->size;
    int i = minHeap->size - 1;
    while (i && minHeapNode->freq < minHeap->array[(i - 1) / 2]->freq) {
        minHeap->array[i] = minHeap->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    minHeap->array[i] = minHeapNode;
}

struct MinHeap* createAndBuildMinHeap(char data[], int freq[], int size) {
    struct MinHeap* minHeap = (struct MinHeap*)malloc(sizeof(struct MinHeap));
    minHeap->size = size;
    minHeap->capacity = size;
    minHeap->array = (struct Node**)malloc(minHeap->capacity * sizeof(struct Node*));
    for (int i = 0; i < size; ++i)
        minHeap->array[i] = newNode(data[i], freq[i]);
    for (int i = (minHeap->size - 2) / 2; i >= 0; --i)
        minHeapify(minHeap, i);
    return minHeap;
}

struct Node* buildHuffmanTree(char data[], int freq[], int size) {
    struct Node *left, *right, *top;
    struct MinHeap* minHeap = createAndBuildMinHeap(data, freq, size);
    while (minHeap->size != 1) {
        left = extractMin(minHeap);
        right = extractMin(minHeap);
        top = newNode('$', left->freq + right->freq);
        top->left = left;
        top->right = right;
        insertMinHeap(minHeap, top);
    }
    return extractMin(minHeap);
}

void printCodes(struct Node* root, int arr[], int top) {
    if (root->left) {
        arr[top] = 0;
        printCodes(root->left, arr, top + 1);
    }
    if (root->right) {
        arr[top] = 1;
        printCodes(root->right, arr, top + 1);
    }
    if (!(root->left) && !(root->right)) {
        printf("%c: ", root->data);
        for (int i = 0; i < top; ++i) printf("%d", arr[i]);
        printf("\n");
    }
}

int main() {
    int n;
    printf("Enter number of characters: ");
    scanf("%d", &n);
    char arr[n];
    int freq[n];
    printf("Enter characters and frequencies:\n");
    for (int i = 0; i < n; i++) scanf(" %c %d", &arr[i], &freq[i]);

    clock_t start = clock();
    struct Node* root = buildHuffmanTree(arr, freq, n);
    int codes[100], top = 0;
    printCodes(root, codes, top);
    clock_t end = clock();

    printf("Time taken: %f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

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
