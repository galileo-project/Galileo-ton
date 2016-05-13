#ifndef TON_LIB_ELEMENT_H_
#define TON_LIB_ELEMENT_H_

//hash generator function
typedef size_t (*hash_func_t)(void*);

/*********************
*       Element      *
**********************/

typedef struct element_s {
    void             *data;
    struct element_s pre;
    struct element_s next;
} element_t;

element_t   *element_new(void*);
void        *element_clean(element_t*);

/*********************
*         Link       *
**********************/

typedef struct link_s {
    size_t    length;
    size_t    cursor;
    element_t head;
    element_t tail;
} link_t;

link_t      *link_new(void);
void        link_clean(link_t*);
int         link_seek(link_t*, size_t);
element_t   *link_next(link_t*);
element_t   *link_pre(link_t*);
size_t      link_length(link_t*);
element_t   *link_find(link_t*, void*);


/********************
*       Bucket      *
*********************/

//bucket of hash table struct
typedef struct bucket_s {
    element_t   *head;
} bucket_t;


/*********************
*       Hash Set     *
**********************/

//hash table struct
typedef struct hashset_s {
    size_t      length;
    size_t      capacity;
    uint32_t    seed;
    bucket_t    *buckets;
    hash_func_t hash_gen;
} hashset_t;


//functions of hash table 
hashset_t   *hashset_new(void);
hashset_t   *hashset_init(hashset_t*, hash_func_t, size_t);
hashset_t   *hashset_add(hashset_t*, element_t*);
hashset_t   *hashset_add_data(hashset_t*, void*);
element_t   *hashset_find(hashset_t*, void*);
int         hashset_rehash(hashset_t*, size_t);
int         hashset_clean(hashset_t*);

/*********************
*     Hash Table     *
**********************/

//hash table struct
typedef struct hashtab_s {
    size_t      length;
    size_t      capacity;
    uint32_t    seed;
    bucket_t    *buckets;
    hash_func_t hash_gen;
} hashtab_t;


//functions of hash table 
hashtab_t   *hashtab_new(void);
hashtab_t   *hashtab_init(hashtab_t*, hash_func_t, size_t);
hashtab_t   *hashtab_add(hashtab_t*, element_t*);
hashtab_t   *hashtab_add_data(hashtab_t*, void*);
element_t   *hashtab_find(hashtab_t*, void*);
int         hashtab_rehash(hashtab_t*, size_t);
int         hashtab_clean(hashtab_t*);


#endif //TON_LIB_ELEMENT_H_