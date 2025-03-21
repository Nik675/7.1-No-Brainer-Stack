#include <iostream>
#include <memory>
#include <string>
#include <stdexcept>

template <class Type>
class MyStack
{
public:
    MyStack();					// Constructor
    MyStack(const MyStack &);	// Copy Constructor
    ~MyStack();					// Destructor
    void push(Type item);		// Adds an item 
    void pop();					// Removes an item 
    Type peek();				// Returns the top value
    int size();					// Returns the size
    bool isEmpty();				// Returns true if empty
    void clear();				// Erases all the items
    MyStack<Type>& operator=(const MyStack<Type>& other);	// Deep copy
    template <class T>
    friend std::ostream &operator<<(std::ostream &out, const MyStack<T> &q);  // Displays all the items

private:
    struct Node {
        Type data;
        std::shared_ptr<Node> next;
        Node(Type d) : data(d), next(nullptr) {}
    };
    std::shared_ptr<Node> top;
    int cnt;  // Counter for the number of elements in the stack
};

template <class Type>
MyStack<Type>::MyStack() : top(nullptr), cnt(0) {}

template <class Type>
MyStack<Type>::MyStack(const MyStack<Type> &other) : top(nullptr), cnt(0) {
    *this = other;
}

template <class Type>
MyStack<Type>::~MyStack() {
    clear();
}

template <class Type>
void MyStack<Type>::push(Type item) {
    auto newNode = std::make_shared<Node>(item);
    newNode->next = top;
    top = newNode;
    cnt++;
}

template <class Type>
void MyStack<Type>::pop() {
    if (top) {
        top = top->next;
        cnt--;
    }
}

template <class Type>
Type MyStack<Type>::peek() {
    if (top) {
        return top->data;
    }
    throw std::runtime_error("Stack is empty");
}

template <class Type>
int MyStack<Type>::size() {
    return cnt;
}

template <class Type>
bool MyStack<Type>::isEmpty() {
    return cnt == 0;
}

template <class Type>
void MyStack<Type>::clear() {
    while (top) {
        top = top->next;
    }
    cnt = 0;
}

template <class Type>
MyStack<Type>& MyStack<Type>::operator=(const MyStack<Type>& other) {
    if (this != &other) {
        clear();
        std::shared_ptr<Node> temp = other.top;
        std::shared_ptr<Node> prev = nullptr;
        while (temp) {
            auto newNode = std::make_shared<Node>(temp->data);
            if (!top) {
                top = newNode;
            } else {
                prev->next = newNode;
            }
            prev = newNode;
            temp = temp->next;
        }
        cnt = other.cnt;
    }
    return *this;
}

template <class Type>
std::ostream& operator<<(std::ostream& out, const MyStack<Type>& q) {
    auto temp = q.top;
    while (temp) {
        out << temp->data;
        if (temp->next) out << " ";
        temp = temp->next;
    }
    return out;
}

// Code to check the stack
void testMyStack();
void checkSize();
void errorHandling();
void testTemplate();
// Aids in testing the program
bool checkTestMemory(std::string, int, int);
// Checks to see if the results match
bool checkTest(std::string, int, int);
bool checkTest(std::string, std::string, std::string);

int main()
{
    std::cout << "Testing MyStack\n" << std::endl;
    testMyStack();
    checkSize();
    errorHandling();
    testTemplate();
    std::cout << "Done\n";
    return 0;
}

// This helps with testing, do not modify.
void testMyStack() {
    auto stack = std::make_unique<MyStack<int>>();

    stack->push(1);

    int data = stack->peek();
    stack->pop();
    checkTest("MyStack #1", 1, data);

    stack->push(1);
    stack->push(2);
    stack->push(3);
    stack->push(4);
    stack->push(5);
    checkTest("MyStack #2", 5, stack->peek());
    stack->pop();
    checkTest("MyStack #3", 4, stack->peek());
    stack->pop();
    checkTest("MyStack #4", 3, stack->peek());
    stack->pop();
    checkTest("MyStack #5", 2, stack->peek());
    stack->pop();
    checkTest("MyStack #6", 1, stack->peek());
    stack->pop();
}

void checkSize() {
    auto stack = std::make_unique<MyStack<int>>();
    // Check currentSize
    checkTest("MyStack #7", 0, stack->size());
    stack->push(12);
    stack->push(32);
    checkTest("MyStack #8", 2, stack->size());

    // Now test filling it up
    stack->push(14);
    stack->push(53);
    stack->push(47);
    checkTest("MyStack #9", 5, stack->size());
}

void errorHandling() {
    // Now cover error handling
    auto stack = std::make_unique<MyStack<int>>();
    std::string caughtError = "";
    int num;
    try {
        num = stack->peek();
    }
    catch (std::exception &e) {
        caughtError = "caught";
    }
    checkTest("MyStack #10", "caught", caughtError);
}

void testTemplate() {
    // Test some strings
    auto sstack = std::make_unique<MyStack<std::string>>();

    sstack->push("pencil");
    sstack->push("pen");
    sstack->push("marker");

    checkTest("MyStack #11", 3, sstack->size());

    // Remove pen from the stack.
    std::string temp = sstack->peek(); // Get marker
    sstack->pop();               // Remove marker
    sstack->pop();               // Remove pen
    sstack->push(temp);          // Push marker back in

    // See if it worked
    checkTest("MyStack #12", "marker", sstack->peek());
    sstack->pop();
    checkTest("MyStack #13", "pencil", sstack->peek());
    sstack->pop();

    checkTest("MyStack #14", 0, sstack->size());
}

// This helps with testing, do not modify.
bool checkTest(std::string testName, int whatItShouldBe, int whatItIs) {
    if (whatItShouldBe == whatItIs) {
        std::cout << "Passed " << testName << std::endl;
        return true;
    }
    else {
        std::cout << "***Failed test " << testName << " *** " << std::endl << "   Output was " << whatItIs << std::endl << "   Output should have been " << whatItShouldBe << std::endl;
        return false;
    }
}

// This helps with testing, comment it in when ready, but do not modify the code.
bool checkTest(std::string testName, std::string whatItShouldBe, std::string whatItIs) {
    if (whatItShouldBe == whatItIs) {
        std::cout << "Passed " << testName << std::endl;
        return true;
    }
    else {
        if (whatItShouldBe == "") {
            std::cout << "***Failed test " << testName << " *** " << std::endl << "   Output was " << whatItIs << std::endl << "   Output should have been blank. " << std::endl;
        }
        else {
            std::cout << "***Failed test " << testName << " *** " << std::endl << "   Output was " << whatItIs << std::endl << "   Output should have been " << whatItShouldBe << std::endl;
        }
        return false;
    }
}

// This helps with testing, do not modify.
bool checkTestMemory(std::string testName, int whatItShouldBe, int whatItIs) {
    if (whatItShouldBe == whatItIs) {
        std::cout << "Passed " << testName << std::endl;
        return true;
    }
    else {
        std::cout << "***Failed test " << testName << " *** " << std::endl << ".  ";
        std::cout << "You are manually managing " << whatItIs << " bytes in memory, but it should be " << whatItShouldBe << " bytes." << std::endl;
        return false;
    }
}