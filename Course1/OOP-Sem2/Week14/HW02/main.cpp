//
// Created by Sybatron on 6/5/2022.
//
#include <iostream>
#include <exception>
#include "Control.h"
#include "Label.h"
#include "Checkbox.h"
#include "RadioButton.h"
#include "TextBox.h"
#include "ListBox.h"
#include "Form.h"

void testFormFunc();

int main() {
    std::cout << "New rows and different options are indicated with | during the input" << std::endl;
    try {
        testFormFunc();
    }
    catch (std::exception e) {
        std::cout << e.what();
    }
    return 0;
}

void testFormFunc() {
//    New rows and different options are indicated with | during the input
    Form testForm("Test Form");
    Control *testLabel = new Label("Input:", 0, 0);

    Control *testTextBox = TextBox().input();
    //Test
    //0 8 10 1

    Control *testRadioButton = RadioButton().input();
    //Yes|No|Maybe
    //1 0 1

    testForm.addControl(testLabel);
    testForm.addControl(testTextBox);
    testForm.addControl(testRadioButton);

    testForm.print();
}