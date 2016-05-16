#include <stdlib.h>
#include <ton/dsa.h>

struct dsa_list*
list_new(size_t capacity)
{
	struct dsa_list *list = (struct dsa_list*)
		malloc(sizeof(struct dsa_list));
		
	if (list == NULL)
		return NULL;
	
	list->head 	= NULL;
	list->tail 	= NULL;
	list->capacity 	= capacity;
	list->length	= 0;
	list->curssor	= 0;
	
	return list;
}

int
list_seek(struct dsa_list *list, size_t seek)
{
	if (list == NULL) {
		return DSA_ERROR;
	} else {
		list->seek = 0;
		return DSA_SUCCESS;
	}
}

size_t
list_length(struct dsa_list *list)
{
	if (list == NULL)
		return DSA_ERROR;
	else
		return list->length;	
}

int
list_clean(struct dsa_list *list)
{
	struct dsa_node *tmp;
	int		status;
	
	if (list == NULL)
		goto error;
	
	if (list_length(list) <= 0)
		goto error;
		
	list_seek(list, 0);
	for ((tmp = list_next(list)) != NULL) {
		status = node_clean(tmp);
		if (status != DSA_SUCCESS)
			goto error;
	}
	
	free(list);
	
	return DSA_SUCCESS;

error:
	return DSA_ERROR;	
}