#include <stdlib.h>
#include <ton/dsa.h>

static int is_null(void *p);

/*
*DSA List functions
*/
struct dsa_list*
list_new(size_t capacity)
{
	struct dsa_list *list = (struct dsa_list*)
		malloc(sizeof(struct dsa_list));
		
	if (is_null(list))
		return NULL;
	
	list->head 	= NULL;
	list->tail 	= NULL;
	list->capacity 	= capacity;
	list->length	= 0;
	list->cursor	= 0;
	
	return list;
}

int
list_reset(struct dsa_list *list, int position)
{
	if (is_null(list) || !(position == 0 || position == -1)) {
		return DSA_ERROR;
	} else {
		if (position == 0)
			list->seek = list->head;
		else if(position == -1)
			list->seek = list->tail;
		return DSA_SUCCESS;
	}
}

size_t
list_length(struct dsa_list *list)
{
	if (is_null(list))
		return DSA_ERROR;
	else
		return list->length;	
}

int
list_clean(struct dsa_list *list)
{
	struct dsa_node *tmp;
	int		status;
	
	if (is_null(list))
		goto error;
	
	if (list_length(list) <= 0)
		goto error;
		
	status = list_reset(list, 0);
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

struct dsa_node*
list_pre(struct dsa_list *list)
{
	struct dsa_node *tmp;
	
	if (is_null(list))
		goto error;
	
	tmp = list->cursor->pre;
	if (tmp == NULL) {
		goto error;
	} else {
		list->cursor = tmp;
		return tmp;
	}
		
error:
	return NULL;
}

struct dsa_node*
list_next(struct dsa_list *list)
{
	struct dsa_node *tmp;
	
	if (is_null(list))
		goto error;
	
	tmp = list->cursor->next;
	if (tmp == NULL) {
		goto error;
	} else {
		list->cursor = tmp;
		return tmp;
	}
		
error:
	return NULL;
}


/*utils*/
static int
is_null(void *p)
{
	if (p == NULL)
		return 1;
	else
		return 0;
}
