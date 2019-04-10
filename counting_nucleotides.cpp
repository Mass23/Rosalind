#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(int argc, char **argv) {

    std::ifstream  fin(argv[1]);
    std::string    line;

    cout << "-------------------------\n";
    cout << "  Nucleotides counter:   \n";
    cout << "-------------------------\n";

    while(std::getline(fin, line)) {

        if(line.empty()){
          continue;
          }

        else if (line[0] == '>'){
          cout << "Sequence: " << line.erase(0, 1) << "\n";
          }

        else {
          int a_count = 0;
          int c_count = 0;
          int g_count = 0;
          int t_count = 0;

          int len = line.length();
          for (int i = 0; i < len; i++) {
            char c = line[i];
            if (c == 'A'){
              ++a_count;
            } else if (c == 'C'){
              ++c_count;
            } else if (c == 'G'){
              ++g_count;
            } else if (c == 'T'){
              ++t_count;
            }
          }

          cout << "A: " << a_count << "\n";
          cout << "C: " << c_count << "\n";
          cout << "G: " << g_count << "\n";
          cout << "T: " << t_count << "\n";
          cout << "\n";

          }

        }
    return 0;
}
