#include <iostream>
#include <string>

using namespace std;

struct Node {
    int color;
    Node* next;

    Node(int c) : color(c), next(nullptr) {}
};

class Stack {
private:
    Node* topNode;

public:
    Stack() : topNode(nullptr) {}

    void push(int color) {
        Node* newNode = new Node(color);
        newNode->next = topNode;
        topNode = newNode;
    }

    void pop() {
        if (isEmpty())
            return;

        Node* temp = topNode;
        topNode = topNode->next;
        delete temp;
    }

    int top() const {
        if (isEmpty())
            return -1;

        return topNode->color;
    }

    bool isEmpty() const {
        return topNode == nullptr;
    }

    ~Stack() {
        while (!isEmpty()) {
            pop();
        }
    }
};

void playGame(int caseNum) {
    Stack column;
    string input;

    cout << "caso " << caseNum << ": ";

    while (getline(cin, input)) {
        if (input == "END")
            break;

        if (input.empty())
            continue;

        int color = stoi(input);

        if (!column.isEmpty() && column.top() == color) {
            column.pop();
        } else {
            column.push(color);
        }
    }

    if (column.isEmpty()) {
        cout << "0 -1" << endl;
    } else {
        int topColor = column.top();
        int count = 0;

        while (!column.isEmpty()) {
            count++;
            column.pop();
        }

        cout << count << " " << topColor << endl;
    }
}

int main() {
    int numCases;
    cin >> numCases;
    cin.ignore();

    for (int i = 0; i < numCases; i++) {
        playGame(i);
    }

    return 0;
}
