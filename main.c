#include <stdio.h>
#include "linkedlist.h"

// use list for int
S_LINKED_LIST(int);

// use list for int pointer
typedef int * intp;
S_LINKED_LIST(intp);


int main(void){
    // methods
    // type_linkedlist *list = new_type_linked_list();
    // type_list_append(list, value);
    // type_list_prepend(list, value);
    // type_list_insert_at(list, value, index);
    // type_list_delete_at(list, index);
    // type_list_delete(list);
    // type_list_is_empty(list);
    // type_list_get_size(list);
    // type_list_reset_loop(list);
    // type_list_next(list)


    int_linkedlist *lst = new_int_linkedlist();
    int_list_append(lst,123);
    int_list_append(lst, 13);
    int_list_append(lst, 54);
    int_list_prepend(lst, 9);

    int_list_reset_loop(lst);
    int *data = NULL;
    printf("list size: %d\n", int_list_get_size(lst));
    while ((data = int_list_next(lst)) != NULL)
        printf("%d\n", *data);
    
    // after loop should reset list otherwise you are not allowed to insert and delete
    int_list_reset_loop(lst);
    
    printf("\n\n");

    intp_linkedlist *lst2 = new_intp_linkedlist();
    int a =  123;
    int b = 15;
    int c = 90;
    intp_list_append(lst2, &a);
    intp_list_insert_at(lst2, &b, 1); // insert at index 1
    intp_list_insert_at(lst2, &c, 2); // insert at index 2
    intp_list_reset_loop(lst2);
    intp *data1 = NULL; 
    printf("list size: %d\n", intp_list_get_size(lst2));
    while ((data1 = intp_list_next(lst2)) != NULL)
    {
        printf("%d\n", **data1);
    }
    intp_list_reset_loop(lst2);


    
    
    return 0;   
}

