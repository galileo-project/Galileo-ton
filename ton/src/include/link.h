#include <ton/element.h>

#ifndef TON_LIB_LINK_H_
#define TON_LIB_LINK_H_

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

#endif //TON_LIB_LINK_H_