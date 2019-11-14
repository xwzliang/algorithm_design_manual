void initialize_graph(graph *graph_ptr, int is_directed);
void insert_edge(graph *graph_ptr, int vertex, int vertex_connected, int is_directed);
void read_graph(graph *graph_ptr, int is_directed);
void print_graph(graph *graph_ptr);
void initialize_search(graph *graph_ptr);
void process_vertex_early(int vertex);
void process_vertex_late(int vertex);
void process_edge(int vertex, int vertex_successor);
void breadth_first_search(graph *graph_ptr, int start_vertex);
