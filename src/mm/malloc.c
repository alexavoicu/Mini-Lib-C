// SPDX-License-Identifier: BSD-3-Clause

#include <internal/mm/mem_list.h>
#include <internal/types.h>
#include <internal/essentials.h>
#include <sys/mman.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

void *malloc(size_t size)
{
	void *ret  = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
	if (ret == MAP_FAILED) {
		return NULL;
	}

	mem_list_add(ret, size);
	return ret;
}

void *calloc(size_t nmemb, size_t size)
{
	void *ret  = mmap(NULL, nmemb * size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
	if (ret == MAP_FAILED) {
		return NULL;
	}

	for (size_t i = 0; i < nmemb * size; i++) {
		*((char *)(ret + i)) = 0;
	}

	mem_list_add(ret, nmemb * size);
	return ret;
}

void free(void *ptr)
{
	if (ptr == NULL)
		return;

	struct mem_list *struct_to_free = mem_list_find(ptr);

	if (struct_to_free == NULL)
		return;

	size_t len = struct_to_free->len;
	mem_list_del(ptr);
	munmap(ptr, len);
}

void *realloc(void *ptr, size_t size)
{
	if (ptr == NULL) {
		return malloc(size);
	}

	struct mem_list *struct_to_realloc = mem_list_find(ptr);
	void *ret = mremap(ptr, struct_to_realloc->len, size, 0);

	if (ret == MAP_FAILED) {
		return NULL;
	}

	mem_list_del(ptr);
	mem_list_add(ret, size);
	return ret;
}

void *reallocarray(void *ptr, size_t nmemb, size_t size)
{
	return realloc(ptr, nmemb * size);
}
