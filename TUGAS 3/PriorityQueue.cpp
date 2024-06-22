#include <iostream>
#include <vector>

using namespace std;

vector<int> H;
int heapSize = -1;

int parent(int i) {
    return (i - 1) / 2;
}

int leftChild(int i) {
    return ((2 * i) + 1);
}

int rightChild(int i) {
    return ((2 * i) + 2);
}

void shiftUp(int i) {
    while (i > 0 && H[parent(i)] < H[i]) {
        swap(H[parent(i)], H[i]);
        i = parent(i);
    }
}

void shiftDown(int i) {
    int maxIndex = i;
    int l = leftChild(i);
    if (l <= heapSize && H[l] > H[maxIndex]) {
        maxIndex = l;
    }
    int r = rightChild(i);
    if (r <= heapSize && H[r] > H[maxIndex]) {
        maxIndex = r;
    }
    if (i != maxIndex) {
        swap(H[i], H[maxIndex]);
        shiftDown(maxIndex);
    }
}

void insert(int p) {
    heapSize = heapSize + 1;
    if (heapSize < H.size()) {
        H[heapSize] = p;
    } else {
        H.push_back(p);
    }
    shiftUp(heapSize);
}

int extractMax() {
    int result = H[0];
    H[0] = H[heapSize];
    heapSize = heapSize - 1;
    shiftDown(0);
    return result;
}

void changePriority(int i, int p) {
    int oldp = H[i];
    H[i] = p;
    if (p > oldp) {
        shiftUp(i);
    } else {
        shiftDown(i);
    }
}

int getMax() {
    return H[0];
}

void remove(int i) {
    H[i] = getMax() + 1;
    shiftUp(i);
    extractMax();
}

void buildHeap(const vector<int>& input) {
    H = input;
    heapSize = input.size() - 1;
    for (int i = (heapSize / 2); i >= 0; --i) {
        shiftDown(i);
    }
}

int main() {
    int n, value;
    cout << "Enter the number of elements to insert into the heap: ";
    cin >> n;

    vector<int> input(n);
    cout << "Enter the elements: ";
    for (int i = 0; i < n; ++i) {
        cin >> input[i];
    }

    buildHeap(input);

    cout << "Priority Queue after building the heap: ";
    for (int i = 0; i <= heapSize; ++i) {
        cout << H[i] << " ";
    }
    cout << "\n";

    cout << "Node with maximum priority: " << extractMax() << "\n";

    cout << "Priority Queue after extracting maximum: ";
    for (int i = 0; i <= heapSize; ++i) {
        cout << H[i] << " ";
    }
    cout << "\n";

    int index, newPriority;
    cout << "Enter the index and new priority to change: ";
    cin >> index >> newPriority;
    changePriority(index, newPriority);

    cout << "Priority queue after priority change: ";
    for (int i = 0; i <= heapSize; ++i) {
        cout << H[i] << " ";
    }
    cout << "\n";

    cout << "Enter the index to remove: ";
    cin >> index;
    remove(index);

    cout << "Priority queue after removing the element: ";
    for (int i = 0; i <= heapSize; ++i) {
        cout << H[i] << " ";
    }
    cout << "\n";

    return 0;
}