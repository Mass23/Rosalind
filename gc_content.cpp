#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(int argc, char **argv) {

    std::ifstream  fin(argv[1]);
    std::string    line;

    cout << "-------------------------\n";
    cout << " GC content calculator:   \n";
    cout << "-------------------------\n";

    while(std::getline(fin, line)) {

        if(line.empty()){
          continue;
          }

        else if (line[0] == '>'){
          cout << "Sequence: " << line.erase(0, 1) << "\n";
          }

        else {
          float a_count = 0;
          float c_count = 0;
          float g_count = 0;
          float t_count = 0;

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

          double gc_content = ((c_count + g_count) / (a_count + c_count + g_count + t_count));
          cout << gc_content << "\n";
          cout << "\n";

          }

        }
    return 0;
}
