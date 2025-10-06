#include <iostream>

class Base {
public:
    Base(int a = 15): x(a) {
    }

    void showX() const {
        std::cout << "x = " << x << "; ";
    }

    void modifyX() {
        std::cout << "Base modify x" << std::endl;
        x *= 3;
    }

protected:
    int x;
};

class Derived : public Base {
public:
    void modifyX() {
        std::cout << "Derived modify x" << std::endl;
        x /= 3;
    }
};

int main() {
    Base b;
    Derived d;
    b.showX();
    d.showX();
    Base *pB;
    pB = &b;
    pB->modifyX();
    pB->showX();
    pB = &d;
    pB->modifyX();
    pB->showX();
    return 0;
}
