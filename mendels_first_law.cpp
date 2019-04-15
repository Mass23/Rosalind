#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(int argc, char **argv) {

    cout << "-------------------------\n";
    cout << "   Mendel's first law:   \n";
    cout << "-------------------------\n";

    float k;
    cout << "Number of homozygous dominants individuals: ";
    cin >> k;

    float m;
    cout << "Number of heterozygous individuals: ";
    cin >> m;

    float n;
    cout << "Number of homozygous recessive individuals: ";
    cin >> n;

    float comb_k_k = k * (k-1);
    float comb_k_m = k * m;
    float comb_k_n = k * n;

    float comb_m_k = m * k;
    float comb_m_m = m * (m-1);
    float comb_m_n = m * n;

    float comb_n_k = n * k;
    float comb_n_m = n * m;
    float comb_n_n = n * (n-1);

    float tot_comb = (comb_k_k + comb_k_m + comb_k_n) + (comb_m_k + comb_m_m + comb_m_n) + (comb_n_k + comb_n_m + comb_n_n);


    float prob_k_k = 1 * comb_k_k;
    float prob_k_m = 1 * comb_k_m;
    float prob_k_n = 1 * comb_k_n;

    float prob_m_k = 1 * comb_m_k;
    float prob_m_m = 0.75 * comb_m_m;
    float prob_m_n = 0.5 * comb_m_n;

    float prob_n_k = 1 * comb_n_k;
    float prob_n_m = 0.5 * comb_n_m;
    float prob_n_n = 0 * comb_n_n;

    float tot_prob = (prob_k_k + prob_k_m + prob_k_n) + (prob_m_k + prob_m_m + prob_m_n) + (prob_n_k + prob_n_m + prob_n_n);

    float prob = tot_prob / tot_comb;
    cout << "\n" << "Probability: " << prob << "\n";

    return 0;
}
