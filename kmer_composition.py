import argparse
from Bio import SeqIO

parser = argparse.ArgumentParser()
parser.add_argument('-f', '--FastaFile', help='Fasta input', type=str, action = 'store', required = True)
parser.add_argument('-k', '--KmerSize', help='Kmer size', type=str, action = 'store', required = True)

args = parser.parse_args()

input_file = args.FastaFile
kmer_size = args.KmerSize

with open(input_file) as f:
    sequence = SeqIO.read(f, 'fasta').seq
    k = kmer_size

    data = dict()

    for i in range(0, len(sequence) - 3):
        curr_kmer = sequence[i] + sequence[i+1] + sequence[i+2] + sequence[i+3]

        if curr_kmer in data.keys():
            data[curr_kmer] += 1
        else:
            data[curr_kmer] = 1

    with open('rosalind_out.txt', 'w') as out:
        for key in sorted(data):
            out.write(str(data[key]))
            out.write(' ')
