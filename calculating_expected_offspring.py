import argparse

parser = argparse.ArgumentParser()

parser.add_argument('-f', '--File', help='input file', type=str, action = 'store', required = True)
parser.add_argument('-o', '--OffspringPerCouple', help='Number of offspring per couple', type=str, action = 'store', required = True)

args = parser.parse_args()

file = args.File
offspring_per_couple = int(args.OffspringPerCouple)

with open(file) as f:
    data = f.read().split(' ')
    data = [int(i) for i in data]

    AAAA = data[0]
    AAAa = data[1]
    AAaa = data[2]
    AaAa = data[3]
    Aaaa = data[4]
    aaaa = data[5]

    probAAAA = 1 * AAAA
    probAAAa = 1 * AAAa
    probAAaa = 1 * AAaa
    probAaAa = 0.75 * AaAa
    probAaaa = 0.5 * Aaaa
    probaaaa = 0 * aaaa

    result = (offspring_per_couple * probAAAA) + (offspring_per_couple * probAAAa) + (offspring_per_couple * probAAaa) + (offspring_per_couple * probAaAa) + (offspring_per_couple * probAaaa) + (offspring_per_couple * probaaaa)
    print(result)
