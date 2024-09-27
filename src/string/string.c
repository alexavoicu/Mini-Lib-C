// SPDX-License-Identifier: BSD-3-Clause

#include <string.h>
#define MAX_BUFFER_SIZE 10000

char *strcpy(char *destination, const char *source)
{
	int len = strlen(source);

	for (int i = 0; i <= len; i++) {
		destination[i] = source[i];
	}

	return destination;
}

char *strncpy(char *destination, const char *source, size_t len)
{
	if (len > strlen(source)) {
		len = strlen(source);
	}

	for (size_t i = 0; i <= len; i++) {
		destination[i] = source[i];
	}

	return destination;
}

char *strcat(char *destination, const char *source)
{
	int len_dest = strlen(destination);

	strcpy(destination + len_dest, source);

	return destination;
}

char *strncat(char *destination, const char *source, size_t len)
{
	int len_dest = strlen(destination);

	strncpy(destination + len_dest, source, len);
	destination[len_dest + len] = '\0';

	return destination;
}

int strcmp(const char *str1, const char *str2)
{
	int i = 0;

	while (str1[i] == str2[i] && str1[i] != '\0' && str2[i] != '\0') {
		i++;
	}

	if (str1[i] == '\0' && str2[i] == '\0') {
		return 0;
	}

	if (str1[i] > str2[i]) {
		return 1;
	}

	return -1;
}

int strncmp(const char *str1, const char *str2, size_t len)
{
	size_t i = 0;

	while (str1[i] == str2[i] && str1[i] != '\0' && str2[i] != '\0' && i < len) {
		i++;
	}

	if (i == len) {
		return 0;
	}

	if (str1[i] == '\0' && str2[i] == '\0') {
		return 0;
	}

	if (str1[i] > str2[i]) {
		return 1;
	}

	return -1;
}

size_t strlen(const char *str)
{
	size_t i = 0;

	for (; *str != '\0'; str++, i++)
		;

	return i;
}

char *strchr(const char *str, int c)
{
	for (size_t i = 0; i < strlen(str); i++) {
		if (str[i] == c) {
			return (char *) str + i;
		}
	}

	return NULL;
}

char *strrchr(const char *str, int c)
{
	for (int i = strlen(str) - 1; i >= 0; i--) {
		if (str[i] == c) {
			return (char *) str + i;
		}
	}

	return NULL;
}

char *strstr(const char *haystack, const char *needle)
{
	size_t len_needle = strlen(needle);

	for (size_t i = 0; i < strlen(haystack); i++) {
		if (strncmp(haystack + i, needle, len_needle) == 0) {
			return (char *) haystack + i;
		}
	}

	return NULL;
}

char *strrstr(const char *haystack, const char *needle)
{
	size_t len_needle = strlen(needle);

	for (int i = strlen(haystack) - 1; i >= 0; i--) {
		if (strncmp(haystack + i, needle, len_needle) == 0) {
			return (char *) haystack + i;
		}
	}

	return NULL;
}

void *memcpy(void *destination, const void *source, size_t num)
{
	for (size_t i = 0; i < num; i++) {
		*((unsigned char*) (destination + i)) = *((unsigned char*) (source + i));
	}

	return destination;
}

void *memmove(void *destination, const void *source, size_t num)
{
	char buffer[MAX_BUFFER_SIZE];

	strcpy(buffer, source);

	return memcpy(destination, buffer, num);
}

int memcmp(const void *ptr1, const void *ptr2, size_t num)
{
	unsigned char *p1 = (unsigned char*)ptr1;	// din documentatie https://man7.org/linux/man-pages/man3/memcmp.3.html
	unsigned char *p2 = (unsigned char*)ptr2;	// bytes sunt comparati ca unsigned char
	size_t i = 0;

	while (*(p1 + i) == *(p2 + i) && i < num) {
		i++;
	}

	if (i == num) {
		return 0;
	}

	if(*(p1 + i) > *(p2 + i)) {
		return 1;
	}

	return -1;
}

void *memset(void *source, int value, size_t num)
{
	for (size_t i = 0; i < num; i++){
		*((unsigned char*) (source + i)) = (unsigned char) value;
	}

	return source;
}
