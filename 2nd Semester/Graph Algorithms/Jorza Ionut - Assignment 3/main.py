import heapq
import random


# from collections import deque


# Add a vertex to the dictionary
def add_vertex(v):
    global graph
    global nr_of_vertices
    if v in graph:
        print("Vertex ", v, " already exists.")
    else:
        nr_of_vertices = nr_of_vertices + 1
        graph[v] = []


# Resets the entire graph
def resets_graph():
    global graph
    graph = {}


# Add an edge between vertex v1 and v2 with edge price e
def add_edge(v1, v2, e):
    global graph
    global nr_of_edges

    # Check if vertex v1 and v2 are valid
    if v1 not in graph:
        print("Vertex ", v1, " does not exist.")
    elif v2 not in graph:
        print("Vertex ", v2, " does not exist.")
    else:
        edge = [v2, e]
        graph[v1].append(edge)
        nr_of_edges += 1


# Iterate through the entire graph
def print_graph():
    global graph
    for vertex in graph:
        for edges in graph[vertex]:
            print(vertex, "->", edges[0], ", price: ", edges[1])


# Prints the outbounds of a specified vertex by the user
def print_outbound_of(user_vertex):
    for edges in graph[user_vertex]:
        print(user_vertex, "->", edges[0], ", price: ", edges[1])


# Prints the inbounds of a specified vertex by the user
def print_inbound_of(user_vertex):
    for vertices in graph:
        for edges in graph[user_vertex]:
            if edges[0] == user_vertex:
                print(vertices, "->", edges[0], ", price: ", edges[1])


# Checks if there is already an edge between 2 vertices
def existing_edge(v1, v2):
    for edges in graph[v1]:
        if edges[0] == v2:
            return True
    return False


# Generates a random graph with a number of vertices and edges provided by the user
def generate_random_graph(nr_of_v, nr_of_e, max_price):
    for v in range(0, nr_of_v):
        add_vertex(v)

    index = 0
    while index < nr_of_e:
        v1 = random.randint(0, nr_of_v - 1)
        v2 = random.randint(0, nr_of_v - 1)
        price = random.randint(0, max_price)
        if not existing_edge(v1, v2):
            add_edge(v1, v2, price)
            index += 1


# Generates the graph from a specified file
def generate_graph_from_file(nr_of_v, nr_of_e, f):
    for v in range(0, int(nr_of_v)):
        add_vertex(v)

    for _ in range(0, int(nr_of_e)):
        string = f.readline()
        string = string.split()
        v1 = int(string[0])
        v2 = int(string[1])
        price = int(string[2])
        add_edge(v1, v2, price)


# Verifies if the edge exists between v1 and v2
def verify_edge_between(v1, v2):
    if v1 not in graph and v2 not in graph:
        return False
    else:
        for edges in graph[v1]:
            if edges[0] == v2:
                return True
    return False


# Checks the in degree and out degree of a vertex specified by the user
def in_out_degree_of(user_vertex):
    if user_vertex not in graph:
        print("The vertex is not part of the graph.")
    else:
        in_degree = int(0)
        out_degree = int(0)
        for _ in graph[user_vertex]:
            out_degree += 1
        for vertices in graph:
            for edges in graph[vertices]:
                if edges[0] == user_vertex:
                    in_degree += 1
        return in_degree, out_degree


# It modifies the price of the edge between v1 and v2
def modify_price_of(v1, v2, user_price):
    for edges in graph[v1]:
        if edges[0] == v2:
            edges[1] = user_price


def parse_N_out(x):
    return graph[x]


# This function is used to find the connected components of an undirected graph using BFS (breadth-first search)
def BFS(user_vertex):
    acc = set()
    acc.add(user_vertex)
    list = [user_vertex]

    while len(list) > 0:
        x = list[0]
        list = list[1:]
        for out_vertices_list in graph[x]:  # we use this to get a list of all outbound vertices of x
            for vertex in out_vertices_list:  # we use this to go one by one in the list of outbound vertices of x
                if vertex not in acc:
                    acc.add(vertex)
                    list.append(vertex)

    return acc


#    visited = set()
#    queue = deque([user_vertex])

#    while queue:
#        vertex = queue.popleft()
#        if vertex not in visited:
#            visited.add(vertex)
#            queue.extend(set(graph[vertex]) & set(graph.keys()) - visited)
#            neighbors = graph.get(vertex, [])  # returns empty list if the vertex is not in the graph
#            queue.extend((uniq(neighbors)) & list(set(graph.keys()) - visited))

# return visited

# minSum = 1000000
#
#
# def get_sum_of_min_cost_walk(first_ever_start, starting_vertex, dest_vertex, visited, currSum, breakk):
#     global minSum
#
#     if breakk:
#         minSum = 10000000
#         return
#
#     if starting_vertex == dest_vertex:
#         minSum = min(minSum, currSum)
#         return
#     else:
#
#         visited[starting_vertex] = True
#
#         for node in graph[starting_vertex]:
#             if node == first_ever_start:
#                 if minSum < 0 or currSum < 0 or currSum + node[1] < 0:
#                     breakk = True
#
#             if not visited[node[0]]:
#                 visited[node[0]] = True
#                 get_sum_of_min_cost_walk(first_ever_start, node[0], dest_vertex, visited, currSum + node[1], breakk)
#                 visited[node[0]] = False
#
#         visited[starting_vertex] = False


# This function is used to compute the path and the total sum from the starting vertex to the destination vertex.
# It is used in the function that performs the minimum cost walk after
# we've completed the parents list for the destination vertex.
def extract_path(parent, starting_vertex, destination_vertex):
    min_sum = 0

    if destination_vertex not in parent:
        return None, 0, False
    path = []
    current_vertex = destination_vertex

    while current_vertex != starting_vertex:
        path.append(current_vertex)
        current_vertex = parent[current_vertex]

    path.append(starting_vertex)
    path.reverse()

    for i in range(0, len(path) - 1):
        for edges in graph[path[i]]:
            if edges[0] == path[i + 1]:
                min_sum += edges[1]

    return path, min_sum, False


# Performs the walk that has the minimum cost from starting_vertex to destination_vertex.
# It then returns the path and the total cost of that path.
# If no walk can be done, it returns None as a path and the sum 0.
def perform_min_cost_walk(starting_vertex, destination_vertex):
    vertices_list = []
    dist = {starting_vertex: 0}
    prev = {starting_vertex: None}
    heapq.heappush(vertices_list, (0, starting_vertex))
    inf = False

    while len(vertices_list) != 0:
        cost, current_vertex = heapq.heappop(vertices_list)

        if current_vertex == starting_vertex and cost < 0:
            inf = True
            break

        if current_vertex == destination_vertex:
            break

        if cost > dist[current_vertex]:
            continue

        for y in graph[current_vertex]:
            if y[0] not in dist or dist[current_vertex] + y[1] < dist[y[0]]:
                dist[y[0]] = dist[current_vertex] + y[1]
                heapq.heappush(vertices_list, (dist[y[0]], y[0]))
                prev[y[0]] = current_vertex

    if not inf:
        return extract_path(prev, starting_vertex, destination_vertex)
    else:
        return None, 0, True


# This is used to print the options
def print_options():
    print("-----------------")
    print("LABORATORY 1")
    print("-----------------")
    print("1. Get the number of vertices.")
    print("2. Iterate the set of vertices.")
    print("3. Verify if there is an edge between 2 vertices.")
    print("4. In-degree and out-degree of a vertex.")
    print("5. Iterate outbound edges of a vertex.")
    print("6. Iterate inbound edges of a vertex.")
    print("7. Modify the cost of an edge.")
    print("8. Modify the graph. (add or remove vertices/edges).")
    print("9. Create another random graph.")
    print("10. Read/Write in a file.")
    print("-----------------")
    print("LABORATORY 2")
    print("-----------------")
    print("21. Find connected components of a graph using breadth-first traversal.")
    print("-----------------")
    print("LABORATORY 3")
    print("-----------------")
    print("31. Lowest cost walk between 2 vertices.")
    print("0. Exit")


# Used to read from a file (We can read from 'ReadingFile.txt' or even from the 'graph' files)
def read_from_a_text_file():
    resets_graph()
    print("How do you want the graph to be generated?")
    print("1. Read from the reading file.")
    print("2. 1k vertices file.")
    print("3. 10k vertices file.")
    print("4. 100k vertices file.")
    print("5. 1m vertices file.")
    command = int(input(">"))

    if command == 1:
        f = open("ReadingFile.txt", "r")
        string = str(f.readline())
        string = string.split()
        nr_of_v = int(string[0])
        nr_of_e = int(string[1])

        generate_graph_from_file(nr_of_v, nr_of_e, f)
        f.close()

    elif command == 2:
        f = open("graph1k.txt", "r")
        string = str(f.readline())
        string = string.split()
        nr_of_v = int(string[0])
        nr_of_e = int(string[1])

        generate_graph_from_file(nr_of_v, nr_of_e, f)
        f.close()

    elif command == 3:
        f = open("graph10k.txt", "r")
        string = str(f.readline())
        string = string.split()
        nr_of_v = int(string[0])
        nr_of_e = int(string[1])

        generate_graph_from_file(nr_of_v, nr_of_e, f)
        f.close()

    elif command == 4:
        f = open("graph100k.txt", "r")
        string = str(f.readline())
        string = string.split()
        nr_of_v = int(string[0])
        nr_of_e = int(string[1])

        generate_graph_from_file(nr_of_v, nr_of_e, f)
        f.close()

    elif command == 5:
        f = open("graph1m.txt", "r")
        string = str(f.readline())
        string = string.split()
        nr_of_v = int(string[0])
        nr_of_e = int(string[1])

        generate_graph_from_file(nr_of_v, nr_of_e, f)
        f.close()


# Used to write the graph into the 'WrittenGraph.txt' file
def write_in_a_text_file():
    f = open("WrittenGraph.txt", "w")
    f.write(str(nr_of_vertices))
    f.write(" ")
    f.write(str(nr_of_edges))
    f.write('\n')

    for vertices in graph:
        for edges in graph[vertices]:
            string = [str(vertices), "->", str(edges[0]), " price: ", str(edges[1])]
            f.write(str(string))
            f.write('\n')
    f.close()


# The menu
def menu():
    print("How do you want the graph to be generated?")
    print("1. Random vertices/edges.")
    print("2. 1k vertices file.")
    print("3. 10k vertices file.")
    print("4. 100k vertices file.")
    print("5. 1m vertices file.")
    print("6. Reading file.")
    command = int(input(">"))

    if command == 1:
        nr_of_v = int(input("Number of vertices: "))
        nr_of_e = int(input("Number of edges: "))
        max_price = int(input("Max price: "))
        generate_random_graph(nr_of_v, nr_of_e, max_price)

    elif command == 2:
        f = open("graph1k.txt", "r")
        string = str(f.readline())
        string = string.split()
        nr_of_v = int(string[0])
        nr_of_e = int(string[1])

        generate_graph_from_file(nr_of_v, nr_of_e, f)
        f.close()

    elif command == 3:
        f = open("graph10k.txt", "r")
        string = str(f.readline())
        string = string.split()
        nr_of_v = int(string[0])
        nr_of_e = int(string[1])

        generate_graph_from_file(nr_of_v, nr_of_e, f)
        f.close()

    elif command == 4:
        f = open("graph100k.txt", "r")
        string = str(f.readline())
        string = string.split()
        nr_of_v = int(string[0])
        nr_of_e = int(string[1])

        generate_graph_from_file(nr_of_v, nr_of_e, f)
        f.close()

    elif command == 5:
        f = open("graph1m.txt", "r")
        string = str(f.readline())
        string = string.split()
        nr_of_v = int(string[0])
        nr_of_e = int(string[1])

        generate_graph_from_file(nr_of_v, nr_of_e, f)
        f.close()

    elif command == 6:
        f = open("ReadingFile.txt", "r")
        string = str(f.readline())
        string = string.split()
        nr_of_v = int(string[0])
        nr_of_e = int(string[1])

        generate_graph_from_file(nr_of_v, nr_of_e, f)
        f.close()

    while True:

        print_options()
        command = int(input(">"))

        if command == 1:
            print("Number of vertices: ", nr_of_vertices)
            print("Number of edges: ", nr_of_edges)

        elif command == 2:
            print_graph()

        elif command == 3:
            v1 = int(input("First vertex:"))
            v2 = int(input("Second vertex:"))
            edge_exist = verify_edge_between(v1, v2)
            if edge_exist:
                print("The edge between ", v1, " and ", v2, " exists.")
            else:
                print("The edge between ", v1, " and ", v2, " does not exist.")

        elif command == 4:
            user_vertex = int(input("Enter the vertex: "))
            if user_vertex in graph:
                in_d, out_d = in_out_degree_of(user_vertex)
                print("In degree of ", user_vertex, ": ", in_d)
                print("Out degree of ", user_vertex, ": ", out_d)
            else:
                print("There is no ", user_vertex, " in our graph.")

        elif command == 5:
            user_vertex = int(input("Enter the vertex: "))
            if user_vertex in graph:
                print_outbound_of(user_vertex)
            else:
                print("There is no ", user_vertex, " in our graph.")

        elif command == 6:
            user_vertex = int(input("Enter the vertex: "))
            if user_vertex in graph:
                print_inbound_of(user_vertex)
            else:
                print("There is no ", user_vertex, " in our graph.")

        elif command == 7:
            v1 = int(input("First vertex: "))
            v2 = int(input("Target vertex: "))
            if not existing_edge(v1, v2):
                print("There is no edge between ", v1, " and ", v2)
            else:
                user_price = int(input("Enter the new price: "))
                modify_price_of(v1, v2, user_price)

        elif command == 8:
            print("What do you want to modify?")
            print("1. Edges.")
            print("2. Vertices.")
            print("0. Back")
            command = int(input(">"))

            if command == 1:
                print("1. Add an edge.")
                print("2. Remove an edge.")
                print("3. Back")
                command = int(input(">"))

                if command == 1:
                    v1 = int(input("First vertex: "))
                    v2 = int(input("Target vertex: "))
                    if not existing_edge(v1, v2):
                        user_price = int(input("Price: "))
                        add_edge(v1, v2, user_price)
                    else:
                        print("This edge already exists.")
            elif command == 2:
                print("1. Add a vertex.")
                print("2. Remove an edge.")
                print("3. Back")
                command = int(input(">"))

                if command == 1:
                    user_vertex = int(input("Vertex: "))
                    if user_vertex not in graph:
                        add_vertex(user_vertex)
                    else:
                        print("This vertex is already part of the graph.")

        elif command == 9:
            resets_graph()
            nr_of_v = int(input("Number of vertices: "))
            nr_of_e = int(input("Number of edges: "))
            max_price = int(input("Max price: "))
            generate_random_graph(nr_of_v, nr_of_e, max_price)

        elif command == 10:
            print("1. Read the graph from a file.")
            print("2. Write the graph to a file.")
            command = int(input(">"))

            if command == 1:
                read_from_a_text_file()
            elif command == 2:
                write_in_a_text_file()

        elif command == 21:
            user_vertex = int(input("Enter the vertex: "))
            if user_vertex in graph:
                BFS_list = BFS(user_vertex)
                print("Connected components using BFS: ", BFS_list)
            else:
                print("There is no ", user_vertex, " in our graph.")

        elif command == 31:

            starting_vertex = int(input("Enter starting vertex: "))
            ending_vertex = int(input("Enter destination vertex: "))
            if starting_vertex in graph:
                if ending_vertex in graph:

                    # visited = [False for _ in range(nr_of_vertices + 1)]
                    # get_sum_of_min_cost_walk(starting_vertex, starting_vertex, ending_vertex, visited, 0, False)
                    # if minSum == 1000000:
                    #     print("No walk could be done.")
                    # elif minSum == 10000000:
                    #     print("Infinite negative cycle detected.")
                    # else:
                    #     print("Lowest cost walk is: ", minSum)
                    min_path, min_sum, inf = perform_min_cost_walk(starting_vertex, ending_vertex)
                    if not inf:
                        print("Path: ", min_path)
                        print("Cost: ", min_sum)
                        if min_path is None:
                            print("No walk could be done between ", starting_vertex, " and ", ending_vertex)
                    else:
                        print("Infinite cycle detected.")

                else:
                    print("There is no ", ending_vertex, " in our graph.")
            else:
                print("There is no ", starting_vertex, " in our graph.")

        elif command == 99:
            for y in graph[1]:
                print(y[1])

        elif command == 0:
            break


graph = {}
nr_of_vertices = 0
nr_of_edges = 0
menu()
