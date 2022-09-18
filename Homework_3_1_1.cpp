#include <fstream>
#include <iostream>

int* readArray(std::ifstream& inFile, int& size);
void writeArray(std::ofstream& outFile, int size, int* array);

int main() {

    setlocale(LC_ALL, "Russian");

    std::ifstream inFile("in.txt");
    if (inFile.is_open()) {

        std::ofstream outFile("out.txt");
        if (!outFile.is_open()) {
            std::cout << "Не удалось открыть файл на запись!" << std::endl;
            return 0;
        }

        int size1 = 0;
        int* array1 = readArray(inFile, size1);

        int size2 = 0;
        int* array2 = readArray(inFile, size2);

        writeArray(outFile, size2, array2);
        writeArray(outFile, size1, array1);

        delete[] array1;
        array1 = nullptr;
        delete[] array2;
        array2 = nullptr;

        inFile.close();
        outFile.close();
    }
    else {
        std::cout << "Не удалось открыть файл на чтение!" << std::endl;
    }
}


int* readArray(std::ifstream& inFile, int& size) {

    size = 0;
    inFile >> size;

    int* array = new int[size]();

    for (int i = 0; i < size; i++) {
        if (!inFile.eof()) {
            inFile >> array[i];
        }
    }
    return array;
}

void writeArray(std::ofstream& outFile, int size, int* array) {
    outFile << size << std::endl;
    for (int i = 0; i < size; i++) {
        outFile << array[size - i - 1] << " ";
    }
    outFile << std::endl;
}
