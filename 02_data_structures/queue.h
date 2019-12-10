#define QUEUE_SIZE 100

typedef struct {
	item_type arr[QUEUE_SIZE];
	int head;
	int tail;
	int length;		// number of queue elements
} queue;
