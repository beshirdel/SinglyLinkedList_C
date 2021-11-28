#ifndef SINGLE_LINKED_LIST_H
#define SINGLE_LINKED_LIST_H
#include <malloc.h>

#define S_LINKED_LIST(type) \
typedef struct __SINGLE_S_node_##type \
{                           \
    type data;              \
    struct __SINGLE_S_node_##type *next; \
} __SINGLE_Node_##type;                     \
typedef struct _linked_list_##type \
{                                \
    __SINGLE_Node_##type *start;                 \
} type##_linkedlist;                        \
                                        \
static __SINGLE_Node_##type *loop_node_##type; \
static _Bool in_loop_##type = 0; \
\
static __SINGLE_Node_##type * makeNode_##type (type data){ \
    __SINGLE_Node_##type *node = (__SINGLE_Node_##type *) malloc(sizeof(__SINGLE_Node_##type)); \
    node->data = data;  \
    node->next = NULL; \
    return node; \
}  \
  \
static void deallocate_node_##type (__SINGLE_Node_##type *node){ \
    free(node); \
}\
\
int type##_list_get_size (type##_linkedlist const *list){ \
    __SINGLE_Node_##type *node = list->start; \
    int count = 0; \
    while (node != NULL) \
    { \
        count++; \
        node = node->next; \
    } \
    return count; \
}\
\
void type##_list_delete(type##_linkedlist *list){ \
    if(in_loop_##type == 1)\
        return;\
    __SINGLE_Node_##type *node = list->start; \
    __SINGLE_Node_##type *nextNode = NULL; \
    while (node != NULL) \
    { \
        nextNode = node->next; \
        deallocate_node_##type(node); \
        node = nextNode;    \
    } \
\
    free(list); \
}\
\
\
type##_linkedlist* new_##type##_linkedlist (){\
    type##_linkedlist *lst = (type##_linkedlist *) malloc(sizeof(type##_linkedlist));\
    lst->start = NULL;\
    return lst;\
}\
\
\
\
\
_Bool type##_list_insert_at(type##_linkedlist *list, type data, int const index){\
    if(in_loop_##type == 1)\
        return 0;\
    int const size = type##_list_get_size(list);\
    if(index < 0 || index > size)\
        return 0;\
\
    __SINGLE_Node_##type *new_node = makeNode_##type(data);\
\
    if(index == 0){\
        new_node->next = list->start; \
        list->start = new_node; \
    }else{ \
        __SINGLE_Node_##type *parent = list->start;\
        for (int i = 0; i < index - 1; i++)\
            parent = parent->next;\
\
        __SINGLE_Node_##type *current = parent->next;\
        parent->next = new_node;\
        new_node->next = current;\
    }\
    \
    return 1;\
    \
}\
\
_Bool type##_list_delete_at(type##_linkedlist *list, int const index){ \
    if(in_loop_##type == 1)\
        return 0;\
    int const size = type##_list_get_size(list); \
    if(index < 0 || index >= size) \
        return 0;\
    \
\
    __SINGLE_Node_##type *next_node; \
\
    if(index == 0){\
        next_node = list->start;\
        list->start = next_node->next;\
    }else{\
        __SINGLE_Node_##type *parent = list->start;\
        for (int i = 0; i < index - 1; i++) \
            parent = parent->next;\
\
        next_node = parent->next;\
        parent->next = next_node->next;\
    }\
\
    deallocate_node_##type(next_node);\
    \
    return 1;\
\
}\
\
\
void type##_list_append(type##_linkedlist *list, type data){ \
    type##_list_insert_at(list, data ,type##_list_get_size(list)); \
} \
\
void type##_list_prepend(type##_linkedlist *list, type data){ \
    type##_list_insert_at(list, data , 0);\
}\
\
_Bool is_##type##_list_is_empty(type##_linkedlist *list){\
    return type##_list_get_size(list) == 0;\
}\
void type##_list_reset_loop(type##_linkedlist *list){ \
    loop_node_##type = list->start; \
    in_loop_##type = 0; \
}\
type * type##_list_next(type##_linkedlist *list){ \
    in_loop_##type = 1;\
    if(loop_node_##type != NULL){ \
        type * result = &loop_node_##type->data; \
        loop_node_##type = loop_node_##type->next; \
        return result; \
    } \
    return NULL; \
}\




#endif