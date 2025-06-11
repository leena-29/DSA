
#include <iostream>
using namespace std;

// Reference-counted Smart Pointer
template <typename T>
class SmartPointer {
private:
    T* ptr;            // actual pointer
    int* ref_count;    // reference count

public:
    // Constructor
    SmartPointer(T* p = nullptr) {
        ptr = p;
        ref_count = new int(1);
    }

    // Copy Constructor
    SmartPointer(const SmartPointer<T>& sp) {
        ptr = sp.ptr;
        ref_count = sp.ref_count;
        ++(*ref_count);
    }

    // Assignment Operator
    SmartPointer<T>& operator=(const SmartPointer<T>& sp) {
        if (this != &sp) {
            if (--(*ref_count) == 0) {
                delete ptr;
                delete ref_count;
            }
            ptr = sp.ptr;
            ref_count = sp.ref_count;
            ++(*ref_count);
        }
        return *this;
    }

    // Destructor
    ~SmartPointer() {
        if (--(*ref_count) == 0) {
            delete ptr;
            delete ref_count;
        }
    }

    // Dereference operator
    T& operator*() {
        return *ptr;
    }

    // Arrow operator
    T* operator->() {
        return ptr;
    }
};

// Sample class to test SmartPointer
class Test {
public:
    void greet() {
        cout << "Hello from Test class!" << endl;
    }
};

int main() {
    SmartPointer<Test> sp1(new Test());
    {
        SmartPointer<Test> sp2 = sp1;  // Reference count increases
        sp2->greet();
    } // sp2 goes out of scope, reference count decreases

    sp1->greet(); // Still valid
    return 0;
}
