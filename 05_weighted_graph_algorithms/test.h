void initialize_graph(graph *graph_ptr, int is_directed);
void insert_edge(graph *graph_ptr, int vertex, int vertex_connected, int edge_weight, int is_directed);
void read_graph(graph *graph_ptr, int is_directed);
void print_graph(graph *graph_ptr);
void minimum_spanning_tree_prim(graph *graph_ptr, int start_vertex);
