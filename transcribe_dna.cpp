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
          for(int i = 0; i < line.length(); i++){

            if (line[i] == 'T'){
              cout << 'U';
            }

            else {
              cout << line[i];
            }

          }
          cout << '\n' << '\n';
        }

        }

    cout << '\n';
    return 0;
}
