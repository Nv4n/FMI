#include <iostream>
#include "DataSources/DefaultDataSource.h"
#include "DataSources/FileDataSource.h"
#include "DataSources/ArrayDataSource.h"
#include "DataSources/GeneratorDataSource.h"

int main() {
    DefaultDataSource<char> dfds;
    DataSource<char> *dts = dfds.clone();
    char txt = dts->get();
    std::cout << txt + 32 << std::endl;
    char *txts = dts->get(10);
    for (int i = 0; i < 10; ++i) {
        std::cout << txts[i] + i << " ";
    }
    std::cout << std::endl;
    return 0;
}