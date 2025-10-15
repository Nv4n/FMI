//
// Created by Sybatron on 1/28/2023.
//
#include <iostream>
#include <fstream>
#include <string>


void space(std::ofstream &writer) {
    writer << "\n";
}

int main() {
    std::ifstream reader("inputQuestions.txt");
    std::ofstream writer("outputQuestions.txt");
    if (!(reader.is_open() && writer.is_open())) {
        return 0;
    }

    std::string currString;
    int index = 11;

//    //Question #10
//    questionsList.add(new Question(
//            "The default size of a physical extent in LVM is_________",
//            "twice the size of a logical extent",
//            "the same size as the resident file system's disk block",
//            "1/1024 of the total volume size",
//            "4MB",
//            QuestionOption.D
//    ));
    while (!reader.eof()) {
        writer << "\t//Question #";
        writer << index++;
        space(writer);
        writer << "questionsList.add(new Question(";
        space(writer);
        for (int i = 0; i < 5; ++i) {
            std::getline(reader, currString);
            if (currString.size() > 0) {
                currString.pop_back();
            }
            writer << '"' + currString + "\",";
            space(writer);
        }
        std::getline(reader, currString);
        if (currString.size() > 0) {
            currString.pop_back();
        }
        writer << "QuestionOption." + currString;
        space(writer);
        writer << "));";
        space(writer);
    }
    reader.close();
    writer.close();
}
