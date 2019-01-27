import argparse
from Bio import SeqIO

parser = argparse.ArgumentParser()

parser.add_argument('-f', '--File', help='input file', type=str, action = 'store', required = True)
parser.add_argument('-k', '--MinKmerSize', help='Minimal Kmer size', type=str, action = 'store', required = True)
parser.add_argument('-m', '--MaxKmerSize', help='Maximal Kmer size', type=str, action = 'store', required = True)

args = parser.parse_args()

file = args.File
min_size = int(args.MinKmerSize)
max_size = int(args.MaxKmerSize) + 1

with open('rosalind.fasta') as in_fasta:
    sequence = SeqIO.read(in_fasta, 'fasta').seq
    reverse = str(sequence.reverse_complement())[::-1]
    sequence = str(sequence)

    for kmer_size in range(min_size, max_size):
        for nuc in range(0, len(sequence) - kmer_size + 1):

            curr_kmer = sequence[nuc: nuc + kmer_size]
            curr_reverse = reverse[nuc: nuc + kmer_size]

            if curr_kmer == curr_reverse[::-1]:
                print(nuc + 1, kmer_size)
