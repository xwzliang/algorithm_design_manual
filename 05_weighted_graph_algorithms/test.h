void initialize_graph();
void insert_edge();
void read_graph();
void print_graph();
typedef struct edge_pair_vertices {
	int vertex_x, vertex_y;
	int edge_weight;
} edge_pair_vertices;
void convert_graph_edges_to_edge_arr();
int weight_compare();
void minimum_spanning_tree_kruskal();
void minimum_spanning_tree_prim();
void shortest_path_dijkstra();
