#ifndef TON_LIB_DSA_H_
#define TON_LIB_DSA_H_

/*Return status*/
#define DSA_SUCCESS 0
#define DSA_ERROR   -1

/*
 *DSA Node
 */
struct dsa_node {
	void 			*data;
	struct dsa_node 	*pre;
	struct dsa_node		*next;	
};

struct dsa_node *node_new(void *data);
int		node_clean(struct dsa_node *node);

/*
 *DSA List
 */
struct dsa_list {
	struct dsa_node		*head;
	struct dsa_node		*tail;
	size_t			capacity;
	size_t			length;
	size_t			cursor;
};

struct dsa_list *list_new(size_t capacity);
struct dsa_node	*list_find(struct dsa_list *list, void *data);
struct dsa_node	*list_pre(struct dsa_list *list);
struct dsa_node	*list_next(struct dsa_list *list);
size_t		list_tell(struct dsa_list *list);
size_t		list_length(struct dsa_list *list);
int		list_clean(struct dsa_list *list);
int 		list_add(struct dsa_list *list, struct dsa_node *node);
int 		list_add_raw(struct dsa_list *list, void *data);
int 		list_remove(struct dsa_list *list, struct dsa_node *node);
int 		list_remove_raw(struct dsa_list *list, void *data);
int		list_seek(struct dsa_list *list, size_t seek);
 
/*
 *DSA Bucket
 */
struct dsa_bucket {
	size_t			length;
	size_t			hash;
	struct dsa_node		*head;
};

struct dsa_bucket	*bucket_new(void);
size_t			bucket_length(struct dsa_bucket *bucket);
int			bucket_clean(struct dsa_bucket *bucket);
int 			bucket_add(struct dsa_bucket *bucket, struct dsa_node *node);
int 			bucket_add_raw(struct dsa_bucket *bucket, void *data);
int 			bucket_remove(struct dsa_bucket *bucket, struct dsa_node *node);
int 			bucket_remove_raw(struct dsa_bucket *bucket, void *data);

/*
 *DSA Hash Set
 */
struct dsa_hashset {
	size_t			capacity;
	size_t			length;
	uint32_t		seed;
	struct dsa_bucket	**buckets;
	size_t 			(*hash_gen)(void*);
};

struct dsa_hashset	*hashset_new(void);
struct dsa_node		*hashset_find(struct dsa_hashset *hashset, void *data);
size_t			hashset_length(struct dsa_hashset *hashset);
int			hashset_clean(struct dsa_hashset *hashset);
int			hashset_add(struct dsa_hashset *hashset, struct dsa_node *node);
int			hashset_add_raw(struct dsa_hashset *hashset, void *data);
int			hashset_remove(struct dsa_hashset *hashset, struct dsa_node *node);
int			hashset_remove_raw(struct dsa_hashset *hashset, void *data);


/*
 *DSA Hash Table
 */
struct dsa_hashtab {
	size_t			capacity;
	size_t			length;
	uint32_t		seed;
	struct dsa_bucket	**buckets;
	size_t 			(*hasg_gen)(void*);	
};

struct dsa_hashtab	*hashtab_new(void);
struct dsa_node		*hashtab_find(struct dsa_hashtab *hashtab, void *data);
size_t			hashtab_length(struct dsa_hashtab *hashtab);
int			hashtab_clean(struct dsa_hashtab *hashtab);
int			hashtab_add(struct dsa_hashtab *hashtab, struct dsa_node *node);
int			hashtab_add_raw(struct dsa_hashtab *hashtab, void *data);
int			hashtab_remove(struct dsa_hashtab *hashtab, struct dsa_node *node);
int			hashtab_remove_raw(struct dsa_hashtab *hashtab, void *data);