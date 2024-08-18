#include <stdio.h>
#include <pthread.h>


typedef char ALIGN[16];

union header{

    struct {
        size_t size;
        unsigned is_free; 
        union header *next; 
    } s;

    ALIGN stub; 
};  

typedef union header header_t; 
header_t *head, *tail; 

pthread_mutex_t global_malloc_lock;


header_t *get_free_block(size_t size)
/* travers the linked list, in order to see if there already exist a free block*/

{
    header_t *curr = head; 

    while(curr != NULL){
        if (curr->s.is_free && curr->s.size >= size)
            return curr; 
        else curr = curr->s.next; 
    }
}

void *malloc(size_t size)
{   

    size_t total_size; 
    void *block; 
    header_t *header; 

    if (!size)             // size == 0; 
        return NULL; 

    pthread_mutex_lock(&global_malloc_lock); 
    header = get_free_block(size); 
    if (header){
        header->s.is_free = 0; 
        pthread_mutex_unlock(&global_malloc_lock); 
        return (void*)(header + 1); 
    }
// in case we  didn't ofund one free, we extand the head by sbrk()
    total_size = size + sizeof(header_t); 
    block = sbrk(total_size); 
    if (block == (void*) - 1){
        pthread_mutex_unlock(&global_malloc_lock);
        return NULL;  
    }

    header = block; 
    header->s.size = size; 
    header->s.is_free = 0; 
    header->s.next  = NULL;

    if (!head) 
        head = header; 
    if (tail)
        tail->s.next = header; 
    tail  = header; 
    pthread_mutex_unlock(&global_malloc_lock); 
    return (void*)(header + 1); 


}