#define PQ_SIZE 100

typedef struct {
	item_type arr[PQ_SIZE+1];		// body of queue
	int length;		// number of queue elements
} priority_queue;
