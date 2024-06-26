//Graph in form of linked list
#include<iostream>
using namespace std;

struct Node {

    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}

};

void addEdge(Node*& head, int destination) {
    Node* newNode = new Node(destination);
    newNode->next = head;
    head = newNode;
}

int main() {
    int n, i;
    i = 0;
    cout << "Enter the number of nodes\n";
    cin >> n;
    Node* adjacencyList[n];
    for (int i = 0; i < n; i++) {
        adjacencyList[i] = nullptr;
    }
    while (true) {
        i++;
        int x, y;
        cout << "Enter Edge Number " << i << endl;
        cin >> x;
        cin >> y;
        if (x == -1 || y == -1) {
            break;
        } 
        else {
            addEdge(adjacencyList[x - 1], y - 1);
        }
    }
    for (int i = 0; i < n; i++) {
        cout << i + 1 << " -> ";
        Node* current = adjacencyList[i];
        while (current != nullptr) {
            cout << current->data + 1 << " -> ";
            current = current->next;
        }
        cout << "nullptr" << endl;
    }
    for (int i = 0; i < n; i++) {
        Node* current = adjacencyList[i];
        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
    }
    return 0;
}

