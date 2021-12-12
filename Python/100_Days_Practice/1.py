import networkx as nx


G = nx.Graph()

k = 2
n = 4 

for i in range(n):                  # Add n nodes
    G.add_nodes_from([i+1])
for node in set((G.nodes)):            # For each node, add k edges
    other_nodes = set(G.nodes) - {node}
    for o_n in set(other_nodes - set(G.neighbors(node))):
        if len(set(G.neighbors(node))) < k:
            if len(set(G.neighbors(o_n))) < k:
                if o_n > node:
                    G.add_edges_from([(node,o_n)])
                    print(G.edges())
    print(a)

print(G.edges)