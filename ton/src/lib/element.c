#include <stdlib.h>
#include <ton/element.h>

element_t*
element_new(void *data)
{
    element_t *element = (element_t*)malloc(sizeof(element_t));
    if(element == NULL)
        return NULL;
        
    element->pre  = NULL;
    element->next = NULL;
    element->data = data;
    
    return element;
}

void
element_clean(element_t *element)
{
    if(element != NULL) {
        if(element->data != NULL)
            free(element->data);
        free(element);
    }
}