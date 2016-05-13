#ifndef TON_LIB_ELEMENT_H_
#define TON_LIB_ELEMENT_H_

typedef struct element_s {
    void             *data;
    struct element_s pre;
    struct element_s next;
} element_t;

element_t   *element_new(void*);
void        *element_clean(element_t*);

#endif //TON_LIB_ELEMENT_H_