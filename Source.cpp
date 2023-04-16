#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// ��������� ��� ������������� ����� ������
struct Elem {
    string value;   // �������� ����� (�����)
    Elem* next;     // ��������� �� ��������� �����
};

// ������� ��� ��������� ����� �� �����
void pushWordToStack(Elem*& stack, const string& word) {
    Elem* newElem = new Elem;
    newElem->value = word;
    newElem->next = stack;
    stack = newElem;
}

// ������� ��� ��������� ����� ����� �� �����
void printStack(Elem* stack) {
    while (stack != nullptr) {
        cout << stack->value << " ";
        stack = stack->next;
    }
    cout << endl;
}

// ������� ��� ������ ���, �� ����������� �� ����������� �������� �������
void findWords(Elem* stack, char startChar, char endChar) {
    while (stack != nullptr) {
        if (stack->value.front() == startChar && stack->value.back() == endChar) {
            cout << stack->value << " ";
        }
        stack = stack->next;
    }
    cout << endl;
}

string pop(Elem*& stack)
{
    Elem* tmp = stack->next; // 1
    string value = stack->value; // 2
    delete stack; // 3
    stack = tmp; // 4
    return value; // 5
}


int main() 
{

    Elem* stack = nullptr;

    // ³�������� ���� ��� ����������
    ifstream file("C:/Student/13.txt");

    if (!file) {
        cerr << "file not found" << endl;
        return
            1;
    }
 
    string word;
    // ������� ����� � ����� �� ������ �� � ����
    while (file >> word) {
        pushWordToStack(stack, word);
    }

    // �������� ���� ����� �� �����
    cout << "stack content: ";
    printStack(stack);

    // �������� ��������� �� ������ �����
    char startChar, endChar;
    cout << "first letter: ";
    cin >> startChar;
    cout << "last letter: ";
    cin >> endChar;

    // ��������� �����, �� ����������� �� ����������� �������� �������
    cout << "words started with '" << startChar << "' and ended with '" << endChar << "': ";
    findWords(stack, startChar, endChar);

    // ��������� ���'���, ������� ��� ������
    pop(stack);


    return 0;
}