//
// Created by Sybatron on 6/5/2022.
//

#ifndef HW02_FORM_H
#define HW02_FORM_H


class Form {
private:
    char *name;
    Control *controls;
    size_t size;
    size_t capacity;
public:

    virtual ~Form();

private:
    void destroy();
};


#endif //HW02_FORM_H
