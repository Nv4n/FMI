#include <iostream>

#include <Date.h>

int main()
{
    try
    {
        Date date("04/17/2006");
        std::cout << date.GetDay() << " " << date.GetMonth() << " " << date.GetYear << std::endl;
    }
    catch (const std::exception &ex)
    {
        std::cerr << ex.what() << std::endl;
    }
    return 0;
}