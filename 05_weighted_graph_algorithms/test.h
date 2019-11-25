void initialize_graph(graph *graph_ptr, int is_directed);
void insert_edge(graph *graph_ptr, int vertex, int vertex_connected, int edge_weight, int is_directed);
void read_graph(graph *graph_ptr, int is_directed);
void print_graph(graph *graph_ptr);
typedef struct edge_pair_vertices {
	int vertex_x, vertex_y;
	int edge_weight;
} edge_pair_vertices;
void convert_graph_edges_to_edge_arr(graph *graph_ptr, edge_pair_vertices edge_arr[]);
int weight_compare(const void *ptr1, const void *ptr2);
void minimum_spanning_tree_kruskal(graph *graph_ptr);
void minimum_spanning_tree_prim(graph *graph_ptr, int start_vertex);
void shortest_path_dijkstra(graph *graph_ptr, int start_vertex);
