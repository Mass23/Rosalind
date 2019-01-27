import argparse
from Bio import SeqIO

parser = argparse.ArgumentParser()

parser.add_argument('-f', '--File', help='input file', type=str, action = 'store', required = True)

args = parser.parse_args()

file = args.File

def GetTree(edges):
    tree_list = []
    n_clusters = 0

    for n1, n2 in edges:
        n1 = int(n1)
        n2 = int(n2)
        for i in tree_list:
            set_i = set(i)
            i = list(set_i)

        # Is n1 or n2 already listed?
        already = []
        for i, l in enumerate(tree_list):
            if n1 in l or n2 in l:
                already.append(i)

        # If not
        if len(already) == 0:
            tree_list.append([n1,n2])

        # Else
        else:
            if len(already) == 1:
                # Create a merged list
                new_list = []
                for i in already:
                    new_list.extend(tree_list[i])
                new_list = new_list + [n1, n2]
                new_list = list(set(new_list))
                # Remove the old ones
                for i in already:
                    del tree_list[i]
                # Append to tree_list
                tree_list.append(new_list)
            else:
                # Create a merged list
                new_list = []
                for i in already:
                    new_list.extend(tree_list[i])
                new_list = new_list + [n1, n2]
                new_list = list(set(new_list))
                # Remove the old ones
                tree_list = [v for i, v in enumerate(tree_list) if i not in already]
                # Append to tree_list
                tree_list.append(new_list)
    return(tree_list)

with open(file) as f:
    data = f.readlines()
    data = [i.replace('\n','').split(' ') for i in data]

    n_nodes = int(data[0][0])
    edges = data[1:]

    x = GetTree(edges)

    ###### Not branched nodes
    not_branched = 0
    values = []
    for i in x:
        values.extend(i)

    for i in range(1,n_nodes+1):
        if i not in values:
            not_branched += 1

    # Output:
    print(len(x) + not_branched - 1)
