//
// Created by Sybatron on 8/9/2024.
//

#ifndef OOPRETAKE_FILEDATASOURCE_H
#define OOPRETAKE_FILEDATASOURCE_H
#pragma once

#include "DataSource.h"

template<typename T>
class FileDataSource : public DataSource<T> {
private:
    T *data;
    size_t currentIndex{};
    size_t length{};
    size_t size{};
public:

    explicit FileDataSource(const char *fileDir);

    FileDataSource(const FileDataSource<T> &other);

    FileDataSource<T> &operator=(const FileDataSource<T> &other);

    ~FileDataSource() override;

    T get() override;

    T *get(size_t count) override;

    bool hasNext() override;

    bool reset() override;

    T operator()() override;

    DataSource<T> &operator>>(T &output) override;

    explicit operator bool() const override;

    DataSource<T> *clone() override;

private:
    void copy(const FileDataSource<T> &other);

    void destroy();

    void initFromFile(const char *fileDir);

    void resize();
};


#include "FileDataSource.inl"

#endif //OOPRETAKE_FILEDATASOURCE_H
