#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(int argc, char **argv) {

    cout << "-------------------------\n";
    cout << "    Hamming distance:    \n";
    cout << "-------------------------\n";

    std::string seq1;
    std::cout << "Sequence 1: ";
    std::getline(std::cin, seq1);
    float seq1_length = seq1.length();

    std::string seq2;
    std::cout << "Sequence 2: ";
    std::getline(std::cin, seq2);
    float seq2_length = seq2.length();
    cout << "\n";

    float min_length;

    if (seq1_length < seq2_length){
      min_length = seq1_length;
    }

    else{
      min_length = seq2_length;
    }

    float match = 0;
    float mismatch = 0;

    for (int i = 0; i < min_length; i++){

      if (seq1[i] == seq2[i]){
        match = match + 1;
      }

      else{
        mismatch = mismatch + 1;
      }
    }

    float identity = (match / min_length);

    cout << "Hamming distance: " << mismatch << "\n";
    cout << "Identity: " << identity << "\n";
    cout << "Sequences length: " << min_length << "\n";
    return 0;
}
