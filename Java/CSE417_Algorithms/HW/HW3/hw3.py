# DFS to find biconnected component

from collections import defaultdict
from time import time

import sys


# The class for graph
class Graph:

    def __init__(self):
        
        # Default the set of nodes and edges in graph
        self.edges = set()
        self.nodes = set() 

        # default the number of nodes and edges in graph
        self.nodes_number = 0
        self.edges_number = 0

        # default dictionary to store graph edges
        self.graph = defaultdict(list)

        # default dictionary to store LOW number of each node
        self.low_number = defaultdict(int)

        # default dictionary to store DFS search sequence number of each node
        self.dfs_number = defaultdict(int)

        # set a counter for the DFS # in the DFS tree
        self.dfs_counter = 0
    
        # Set a counter to the number of biconnected components
        self.bicomp_number = 0

        # default a list to store the biconnected components
        self.bicomp = list()

        # default a set for the articulation points
        self.articulations = set()

        # default a direction tree with DFS pash
        self.dfs_tree = defaultdict(list)

    # function to add an edge to graph
    def add_edge(self, u, v):

        if u in self.graph[v]:                  # Check if the edge already have
            print(f'edge ({u},{v}) exists')
        else:
            self.graph[u].append(v) 
            self.graph[v].append(u)
            
            # Update the edges and nodes list
            self.edges.add((v,u))
            self.edges_number = len(self.edges)

            self.nodes = set(self.graph.keys())
            self.nodes_number = len(self.nodes)
            
            # reset bfs abd low number
            self.low_number = defaultdict(int)
            self.dfs_number = defaultdict(int)


    # Function to add multiple edges from a list
    def add_Edge_from_list(self,edgelist):
        for edge in edgelist:
            self.graph[edge[0]].append(edge[1]) 
            self.graph[edge[1]].append(edge[0])


    # Global initialization for DFS
    def initialization(self):
        # Set the DFS number for all the nodes to -1
        for i in self.nodes:
            self.dfs_number[i] = -1
        
        # Set DFS discover counter to 0
        self.dfs_counter = 0

    
    def DFS(self):
        self.initialization()
        store = list()
        for node in self.nodes:
            if self.dfs_number[node] == -1:
                self.__dfs(node, store)
        
        # If there are any left left edges in the store, these edges are also a biconnected component 
        # of this graph which connected with DFS beginner node
        self.bicomp += [store]


    def __dfs(self, v, store):
        # Initialization
        self.dfs_counter += 1
        self.dfs_number[v] = self.dfs_counter
        self.low_number[v] = self.dfs_counter

        for x in self.graph[v]:
            if self.dfs_number[x] == -1:       # x is undiscovered
                store += [(v,x)]
                self.dfs_tree[v].append(x)
                
                self.__dfs(x, store)

                self.low_number[v] = min(self.low_number[v], self.low_number[x])
                
                # if parent[u] == -1 and children > 1 or parent[u] != -1 and low[v] >= disc[u]:
                if self.dfs_number[v] != 1 and self.low_number[x] >= self.dfs_number[v]:
                    self.articulations.add(v)
                    bicomp = []
                    a=()
                    while a != (v,x):
                        a = store.pop()
                        bicomp += [a]
                    self.bicomp += [bicomp]

            elif v not in self.dfs_tree[x]:            # x is not v's parent
                self.low_number[v] = min(self.low_number[v], self.dfs_number[x])    
                store.append((v,x))

 
def main():
    # Try to open each file by sequence
    for i in range(1,len(sys.argv)):
        test_name = sys.argv[i]
        test = None
        try:
            test = open(test_name,'r')
        except IOError as ex:
            print(ex)

        # If open success, process the data.
        if test:
            test_list = test.read().split()
            
            test_list.pop(0)        # Delete the first number (which is the number of nodes)

            # Creat graph by adding edges in graph
            G = Graph()
            while test_list:
                u = int(test_list.pop(0))
                v = int(test_list.pop(0))
                G.add_edge(u,v)
            
            #print(g.graph)

            start_time = time()
            G.DFS()
            
            
            # Begin to conting the processing time.


            end_time = time()
            run_time = end_time - start_time

            print('Articulations: ')
            print('Summary: %s, %d, %d, %d, %d, %f' % (test_name, len(G.nodes), len(G.edges), len(G.articulations), len(G.bicomp), run_time))
            print()
            print(G.articulations)
            print()
            print(G.edges)
            print()
            print('low',G.low_number)

            print()
            for i in G.bicomp:
                print(i)




if __name__ == '__main__':
    main()


