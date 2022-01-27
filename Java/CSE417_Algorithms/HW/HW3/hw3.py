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
        self.bicomp = set()

        # default a set for the articulation points
        self.articulations = set()

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

 

    '''A recursive function that finds and prints strongly connected

    components using DFS traversal

    u --> The vertex to be visited next

    disc[] --> Stores discovery times of visited vertices

    low[] -- >> earliest visited vertex (the vertex with minimum

               discovery time) that can be reached from subtree

               rooted with current vertex

    st -- >> To store visited edges'''

    # Function to add multiple edges from a list
    def add_Edge_from_list(self,edgelist):
        for edge in edgelist:
            self.graph[edge[0]].append(edge[1]) 
            self.graph[edge[1]].append(edge[0])


    # Global initialization for DFS
    def initialization(self):
        for i in self.dfs_number:
            self.dfs_number[i] = -1
        self.dfs_counter = 0

    
    def DFS(self):
        self.initialization()

    def dfs(self):
        pass

    def BCCUtil(self, u, parent, st):
        # Count of children in current node 
        children = 0
        # Initialize discovery time and low value
        self.dfs_number[u] = self.bfs_counter
        self.low_number[u] = self.bfs_counter
        self.bfs_counter += 1 

        # Recur for all the vertices adjacent to this vertex
        for v in self.graph[u]:
            # If v is not visited yet, then make it a child of u
            # in DFS tree and recur for it
            if self.dfs_number[v] == -1 :
                parent[v] = u
                children += 1
                st.append((u, v)) # store the edge in stack
                self.BCCUtil(v, parent, st)
 
                # Check if the subtree rooted with v has a connection to
                # one of the ancestors of u
                # Case 1 -- per Strongly Connected Components Article
                self.low_number[u] = min(self.low_number[u], self.low_number[v])

                # If u is an articulation point, pop 
                # all edges from stack till (u, v)
                if parent[u] == -1 and children > 1 or parent[u] != -1 and self.low_number[v] >= self.dfs_number[u]:
                    self.bicomp
                    w = -1
                    while w != (u, v):
                        w = st.pop()
                        print(w,end=" ")
                    print()

            elif v != parent[u] and self.low_number[u] > self.dfs_number[v]:
                '''Update low value of 'u' only of 'v' is still in stack
                (i.e. it's a back edge, not cross edge).
                Case 2 
                -- per Strongly Connected Components Article'''
                self.low_number[u] = min(self.low_number [u], self.dfs_number[v])    
                st.append((u, v))
 
    # The function to do DFS traversal. 

    # It uses recursive BCCUtil()

    def BCC(self):

        # Initialize disc and low, and parent arrays

        self.dfs_number = [-1] * (self.nodes_number)

        self.low_number = [-1] * (self.nodes_number)

        parent = [-1] * (self.nodes_number)

        st = []
 
        # Call the recursive helper function to 
        # find articulation points
        # in DFS tree rooted with vertex 'i'

        for i in range(self.nodes_number):
            if self.dfs_number[i] == -1:
                self.BCCUtil(i, parent, st)
 

            # If stack is not empty, pop all edges from stack

            if st:
                self.bicomp 
                while st:
                    w = st.pop()
                    print(w,end=" ")
                print ()
 
# Create a graph given in the above diagram
 
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
            G.BCC;
            
            
            # Begin to conting the processing time.


            end_time = time()
            run_time = end_time - start_time

            print('Articulations: ')
            print('Summary: %s, %d, %d, %d, %d, %f' % (test_name, len(G.nodes), len(G.edges), len(G.articulations), len(G.bicomp), run_time))
            print()
            print(G.nodes)

            print(G.edges)
            print()





if __name__ == '__main__':
    main()


