#include "DataStructure.h"
#include <fstream>


typedef struct CharacterNodes {
    int characterCode;
    int frequency;
    CharacterNodes* rightChild;
    CharacterNodes* leftChild;
}CharacterNodes;

CharacterNodes* CreateNode(int characterCode , int frequency) {
    CharacterNodes* newNode = new CharacterNodes;
    newNode->characterCode = characterCode;
    newNode->frequency = frequency;
    newNode->rightChild = nullptr;
    newNode->leftChild = nullptr;
    return newNode;
}

void GenerateRandomTextFile(std::string filename){
    srand(time(nullptr));
    std::fstream file(filename + ".txt" , std::ios::out | std::ios::trunc);
    int length = rand() % 10000 + 1000;
    while(length > 0) {
        char randomGeneratedCharacter = 'a' + std::rand() % 26;
        file << randomGeneratedCharacter;
        length--;
    }
    file.close();
}
void HuffmannEncoding(std::string filename) {
    std::fstream file(filename + ".txt" , std::ios::in);
    std::string lines;
    while(std::getline(file , lines)) {
        std::getline(file , lines);
    }

}
void HuffmanDecoding(std::string filename) {

}

int main(){
    std::cout << "Enter Your File Name:\n";
    std::string filename;
    std::getline(std::cin , filename);
    GenerateRandomTextFile(filename);
    system("pause");
}