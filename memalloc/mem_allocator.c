#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <string.h>

/**
ALIGN[16]: This makes the header end up on a memory address aligned to 16 bytes. 
Recall that the size of a union is the larger size of its members. 
So the union guarantees that the end of the header is memory aligned.
The end of the header is where the actual memory block begins and therefore,
 the memory provided to the caller by the allocator will be aligned to 16 bytes.
*/

typedef char ALIGN[16]; //stub variable of size 16 bytes



// struture for allocations
union header {
    struct {
        size_t size;
        unsigned is_free; //Whether a block is free or not-free?
        union header *next; // points to the next page size allocation
    } s;
    ALIGN stub;
};

typedef union header header_t ;
header_t *head = NULL;
header_t *tail = NULL;

/**
 * To prevent two or more threads from concurrently accessing memory, we will put a basic locking mechanism in place.

We’ll have a global lock, and before every action on memory you have to acquire the lock, and once you are done you have to release the lock.
*/
pthread_mutex_t global_malloc_lock;

header_t *get_free_block(size_t size)
{
    header_t *curr = head;
    while (curr){
        if (curr->s.is_free && curr->s.size >= size)
            curr->s.is_free = 0;
            return curr;
        curr = curr->s.next;
    }
}


void * my_malloc(size_t size){
    void *block = malloc(size);
    if (block == NULL) return NULL;
    memset(block, 0, size);
    printf("mem_alloc: 0x%p calloc(%zu)\n", block, size);
    return block;
}


void * _malloc(size_t size){
    size_t total_size;
    void *block;
    header_t *header;
    if (!size)
        return NULL;
    pthread_mutex_lock(&global_malloc_lock);
    header = get_free_block(size);
    if (header){
        pthread_mutex_unlock(&global_malloc_lock);
        return (void*)(header + 1);
    }
    total_size = sizeof(header_t) + size;
    block = sbrk(total_size);
    if (block == (void*) -1) {
		pthread_mutex_unlock(&global_malloc_lock);
		return NULL;
	}
    header = block;
	header->s.size = size;
	header->s.is_free = 0;
	header->s.next = NULL;

    if (!head)
		head = header;
	if (tail)
		tail->s.next = header;
    tail = header;
	pthread_mutex_unlock(&global_malloc_lock);
	return (void*)(header + 1);
}

void *_calloc(size_t num, size_t nsize)
{
	size_t size;
	void *block;
	if (!num || !nsize)
		return NULL;
	size = num * nsize;
	/* check mul overflow */
	if (nsize != size / num)
		return NULL;
	block = malloc(size);
	if (!block)
		return NULL;
	memset(block, 0, size);
	return block;
}

void *_realloc(void *block, size_t size)
{
	header_t *header;
	void *ret;
	if (!block || !size)
		return malloc(size);
	header = (header_t*)block - 1;
	if (header->s.size >= size)
		return block;
	ret = malloc(size);
	if (ret) {
		/* Relocate contents to the new bigger block */
		memcpy(ret, block, header->s.size);
		/* Free the old memory block */
		free(block);
	}
	return ret;
}


void _free(void *block)
{
	header_t *header, *tmp;
	/* program break is the end of the process's data segment */
	void *programbreak;

	if (!block)
		return;
	pthread_mutex_lock(&global_malloc_lock);
	header = (header_t*)block - 1;
	/* sbrk(0) gives the current program break address */
	programbreak = sbrk(0);

	/*
	   Check if the block to be freed is the last one in the
	   linked list. If it is, then we could shrink the size of the
	   heap and release memory to OS. Else, we will keep the block
	   but mark it as free.
	 */
	if ((char*)block + header->s.size == programbreak) {
		if (head == tail) {
			head = tail = NULL;
		} else {
			tmp = head;
			while (tmp) {
				if(tmp->s.next == tail) {
					tmp->s.next = NULL;
					tail = tmp;
				}
				tmp = tmp->s.next;
			}
		}
		/*
		   sbrk() with a negative argument decrements the program break.
		   So memory is released by the program to OS.
		*/
		sbrk(0 - header->s.size - sizeof(header_t));
		/* Note: This lock does not really assure thread
		   safety, because sbrk() itself is not really
		   thread safe. Suppose there occurs a foregin sbrk(N)
		   after we find the program break and before we decrement
		   it, then we end up realeasing the memory obtained by
		   the foreign sbrk().
		*/
		pthread_mutex_unlock(&global_malloc_lock);
		return;
	}
	header->s.is_free = 1;
	pthread_mutex_unlock(&global_malloc_lock);
}







// int main(){
//     header_t head;
//     printf("Header Size: %zu\n", sizeof(head));
//     // printf("Align Size: %zu\n", sizeof(ALIGN));

//     void * p = my_malloc(4*1024);
//     return 0;
// }

