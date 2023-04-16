#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Структура для представлення вузла списку
struct Elem {
    string value;   // Значення вузла (слово)
    Elem* next;     // Посилання на наступний вузол
};

// Функція для додавання слова до стеку
void pushWordToStack(Elem*& stack, const string& word) {
    Elem* newElem = new Elem;
    newElem->value = word;
    newElem->next = stack;
    stack = newElem;
}

// Функція для виведення вмісту стеку на екран
void printStack(Elem* stack) {
    while (stack != nullptr) {
        cout << stack->value << " ";
        stack = stack->next;
    }
    cout << endl;
}

// Функція для пошуку слів, що починаються та закінчуються заданими літерами
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

    // Відкриваємо файл для зчитування
    ifstream file("C:/Student/13.txt");

    if (!file) {
        cerr << "file not found" << endl;
        return
            1;
    }
 
    string word;
    // Зчитуємо слова з файлу та додаємо їх у стек
    while (file >> word) {
        pushWordToStack(stack, word);
    }

    // Виводимо вміст стеку на екран
    cout << "stack content: ";
    printStack(stack);

    // Запитуємо початкову та кінцеву літери
    char startChar, endChar;
    cout << "first letter: ";
    cin >> startChar;
    cout << "last letter: ";
    cin >> endChar;

    // Знаходимо слова, що починаються та закінчуються заданими літерами
    cout << "words started with '" << startChar << "' and ended with '" << endChar << "': ";
    findWords(stack, startChar, endChar);

    // Звільняємо пам'ять, виділену для списку
    pop(stack);


    return 0;
}