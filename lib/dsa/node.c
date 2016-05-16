#include <stdlib.h>
#include <ton/dsa.h>

struct dsa_node*
node_new(void *data)
{
	struct dsa_node *node = (struct dsa_node*)
		malloc(sizeof(struct dsa_node));
	
	if (node == NULL)
		return NULL;
		
	node->pre  = NULL;
	node->next = NULL;
	node->data = data;
	
	return node;	
}

int
node_clean(struct dsa_node *node)
{
	if (node == NULL) {
		return 1;
	} else {
		free(node->data);
		free(node);
		return 0;
	}
}