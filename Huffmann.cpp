#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <queue>

typedef struct CharacterNodes {
    std::vector<bool> characterCode;
    char character;
    int frequency;
    CharacterNodes* rightChild;
    CharacterNodes* leftChild;

    ~CharacterNodes() {
        delete leftChild;  // Delete the left subtree
        delete rightChild; // Delete the right subtree
    }
}CharacterNodes;

struct CompareCharacterNodes {
    bool operator()(CharacterNodes* n1, CharacterNodes* n2) {
        return n1->frequency > n2->frequency;
    }
};

std::vector<bool> ConvertStringToBinary (std::string x) {
    std::vector<bool> binary;
    for(int i = 0 ; i<x.length() ; i++) {
        binary.push_back((x[i] == '0') ? false : true);
    }
    return binary;
}

CharacterNodes* CreateNode(char character , int frequency , CharacterNodes* right , CharacterNodes* left) {
    CharacterNodes* newNode = new CharacterNodes;
    newNode->characterCode = {};
    newNode->character = character;
    newNode->frequency = frequency;
    newNode->rightChild = right;
    newNode->leftChild = left;
    return newNode;
}

void GenerateRandomTextFile(std::string filename){
    std::fstream file(filename + ".txt" , std::ios::out | std::ios::trunc);
    int length = rand() % 10000 + 1000;
    while(length > 0) {
        char randomGeneratedCharacter = std::rand() % (127 - 32) + 32;
        file << randomGeneratedCharacter;
        length--;
    }
    file.close();
}

void saveHuffmanCode(CharacterNodes* root , std::string currentcode) {
    if(root == nullptr) return;
    if(root->leftChild == nullptr && root->rightChild == nullptr) {  
        root->characterCode = ConvertStringToBinary(currentcode);
    }
    else{
        if(root->leftChild != nullptr) {
            saveHuffmanCode(root->leftChild , currentcode + "0");
    } 
        if(root->rightChild != nullptr) {
            saveHuffmanCode(root->rightChild , currentcode + "1");
    }
}
}

void HuffmanEncoding(std::string filename) {
    int* CountCharacters = new int[95];
    for(int i = 0 ; i < 95 ; i++) {
        CountCharacters[i] = 0;
    }
    const int ASCII_Offset = 32;
    std::fstream file(filename + ".txt" , std::ios::in);
    char temp;
    int i = 0;
    while(file.get(temp)) {
        CountCharacters[temp - ASCII_Offset] ++;
        i++;
    }
    std::priority_queue<CharacterNodes* , std::vector<CharacterNodes*>, std::greater<CharacterNodes*>> min_heap;
    for(int i = 0 ; i < 95 ; i++) {
        if(CountCharacters[i] != 0) {
            CharacterNodes* temp = CreateNode(i + ASCII_Offset , CountCharacters[i] , nullptr , nullptr);
            min_heap.push(temp);
        }
    }
    while (min_heap.size() > 1) {
        CharacterNodes* left = min_heap.top();
        min_heap.pop();
        CharacterNodes* right = min_heap.top();
        min_heap.pop();
        CharacterNodes* parent = CreateNode('\0', left->frequency + right->frequency, left, right);
        min_heap.push(parent);
    }
    CharacterNodes* huffmanRoot = min_heap.top();
    min_heap.pop();
    saveHuffmanCode(huffmanRoot , "");
}
void HuffmanDecoding(std::string filename) {

}

int main(){
    srand(time(nullptr));
    std::cout << "Enter Your File Name:\n";
    std::string filename;
    std::getline(std::cin , filename);
    GenerateRandomTextFile(filename);
    HuffmanEncoding(filename);
    system("pause");
}