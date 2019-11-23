#define MAX_VERTICES_NUM 1000

typedef struct edge {
	int vertex_connected;
	int edge_weight;
	struct edge *next;		// next edge in list
} edge;

typedef struct graph {
	edge *edges[MAX_VERTICES_NUM+1];
	int degree_of_vertex[MAX_VERTICES_NUM+1];	// outdegree of each vertex, the degree field of the graph counts the number of meaningful entries for the given vertex
	int num_vertices;
	int num_edges;
	int is_directed;	// bool value: is the graph directed?
} graph;

