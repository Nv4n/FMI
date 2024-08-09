//
// Created by Sybatron on 4/20/2024.
//
#include <iostream>
#include "2.h"

int main() {
    ModifiableIntegerFunction func1([](int16_t x) -> int16_t { return x - 2; });
    ModifiableIntegerFunction func2 = func1;
    ModifiableIntegerFunction func3([](int16_t x) -> int16_t { return x - 10; });

    std::cout << std::boolalpha << func1.isParallel(func3) << std::endl;
//    std::cout << std::boolalpha << func1.isSurjection() << std::endl;
    ModifiableIntegerFunction func4([](int16_t x) -> int16_t { return x - 25; });
    func2.serialize("functest.dat");
    func4.deserialize("functest.dat");
    bool test = func2 >= func4;
    func3.specifyResult(2, 10);
    func3.excludeInput(2);

    std::cout << std::boolalpha << func3.isParallel(func4) << std::endl;
}
