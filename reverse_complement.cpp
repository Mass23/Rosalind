#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(int argc, char **argv) {

    std::ifstream  fin(argv[1]);
    std::string    line;

    cout << "-------------------------\n";
    cout << "     Transcribe DNA:    \n";
    cout << "-------------------------\n";

    while(std::getline(fin, line)) {

        if(line.empty()){
          continue;
        }

        else if (line[0] == '>'){
          cout << "Sequence: " << line.erase(0, 1) << "\n";
        }

        else {
          for(int i = line.length(); i > -1; i--){

            if (line[i] == 'A'){
              cout << 'T';
            }

            else if (line[i] == 'C'){
              cout << 'G';
            }

            else if (line[i] == 'T'){
              cout << 'A';
            }

            else if (line[i] == 'G'){
              cout << 'C';
            }

          }
          cout << '\n';
          cout << '\n';
        }
        }

    cout << '\n';
    return 0;
}
