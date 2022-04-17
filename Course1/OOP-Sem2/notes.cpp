#include<fstream>

void write(std::ostream& out)const{
    out.write(reinterpret_cast<const char*>(&size),sizeof(size));
    for (size_t i = 0; i < size; i++)
    {
        this->books[i].wrote(out);
    }
    out.write(reinterpret_cast<const char*>(&currentWieght),sizeof(currentWeight));
    out.write(reinterpret_cast<const char*>(&maxWeight),sizeof(maxWeight));
}

Backpack void read(std::istream&in){
    int size = 0;
    in.read(reinterpret_cast<char*>(&size),sizeof(size));
    Book* books = new Book[size];
    for (size_t i = 0; i < size; i++)
    {
        this->books[i].read(in);
    }
    double currentWeight = 0;
    const double maxWeight = 0;
    in.read(reinterpret_cast<char*>(&currentWeight), sizeof(currentWeight));
    in.read(reinterpret_cast<char*>(&maxWeight),sizeof(maxWeight));
}