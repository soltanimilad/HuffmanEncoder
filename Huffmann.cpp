#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <queue>

typedef struct CharacterNodes {
    char character;
    int frequency;
    CharacterNodes* rightChild;
    CharacterNodes* leftChild;
}CharacterNodes;

struct CompareCharacterNodes {
    bool operator()(CharacterNodes* n1, CharacterNodes* n2) {
        return n1->frequency > n2->frequency;
    }
};

CharacterNodes* CreateNode(char character , int frequency , CharacterNodes* right , CharacterNodes* left) {
    CharacterNodes* newNode = new CharacterNodes;
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
void WriteTreeRecursive(CharacterNodes* node, std::ofstream& outFile) {
    if (node == nullptr) {
        return;
    }

    if (node->leftChild == nullptr && node->rightChild == nullptr) {
        char leaf_marker = '1';
        outFile.write(&leaf_marker, sizeof(int));
        outFile.write(&node->character, sizeof(char));
    } else {
        char internal_marker = '0';
        outFile.write(&internal_marker, sizeof(int));
        WriteTreeRecursive(node->leftChild, outFile);
        WriteTreeRecursive(node->rightChild, outFile);
    }
}

void SaveHuffmanTreeToFile(CharacterNodes* root, const std::string& output_filename) {
    std::ofstream outFile(output_filename + ".bin", std::ios::binary | std::ios::out | std::ios::trunc);
    if (!outFile.is_open()) {
        std::cerr << "Error: Could not open file for writing Huffman tree: " << output_filename << "\n";
        return;
    }

    if (root) { 
        WriteTreeRecursive(root, outFile);
    }
    outFile.close();
    std::cout << "Huffman tree saved to: " << output_filename << std::endl;
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
    SaveHuffmanTreeToFile(huffmanRoot , filename + "Compressed");
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