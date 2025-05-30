# Huffman Text Compressor

A C++ implementation of the Huffman coding algorithm for text compression and decompression. This project demonstrates how to build a Huffman tree, encode text into binary, and decode it back to its original form, offering a fundamental understanding of data compression techniques.

---

## Features

* **Text File Generation**: Automatically generates a random text file for testing purposes.
* **Huffman Encoding**: Compresses text files using the Huffman algorithm, assigning variable-length codes to characters based on their frequency.
* **Huffman Decoding** (Planned): Decompresses Huffman-encoded files back to their original text.
* **Frequency Analysis**: Counts character occurrences to build an optimal Huffman tree.
* **Priority Queue Implementation**: Utilizes a min-priority queue to efficiently construct the Huffman tree.

---

## Getting Started

These instructions will get you a copy of the project up and running on your local machine for development and testing purposes.

### Prerequisites

You'll need a C++ compiler (like g++ or Clang) installed on your system.

### Installation

1.  **Clone the repository:**
    ```bash
    git clone [https://github.com/YOUR_USERNAME/HuffmanTextCompressor.git](https://github.com/YOUR_USERNAME/HuffmanTextCompressor.git)
    cd HuffmanTextCompressor
    ```
    (Remember to replace `YOUR_USERNAME` with your actual GitHub username.)

2.  **Compile the code:**
    ```bash
    g++ -o huffman main.cpp -std=c++11
    ```
    (Assuming your main source file is named `main.cpp`.)

---

## How to Use

1.  **Run the executable:**
    ```bash
    ./huffman
    ```

2.  **Enter a filename:**
    The program will prompt you to "Enter Your File Name:". Type a name (e.g., `my_document`) and press Enter.

3.  **Automatic File Generation & Encoding:**
    The program will then:
    * Generate a random text file with the specified name (e.g., `my_document.txt`).
    * Perform Huffman encoding on this generated file.

Currently, the decoding functionality is not fully implemented in the provided code, but the encoding part will process the file.

---

## Contributing

Contributions are what make the open-source community such an amazing place to learn, inspire, and create. Any contributions you make are **greatly appreciated**.

If you have a suggestion that would make this better, please fork the repo and create a pull request. You can also simply open an issue with the tag "enhancement".
Don't forget to give the project a star! Thanks again!

1.  Fork the Project
2.  Create your Feature Branch (`git checkout -b feature/AmazingFeature`)
3.  Commit your Changes (`git commit -m 'Add some AmazingFeature'`)
4.  Push to the Branch (`git push origin feature/AmazingFeature`)
5.  Open a Pull Request

---


## Acknowledgments

* This project is a personal exploration of data compression algorithms.
