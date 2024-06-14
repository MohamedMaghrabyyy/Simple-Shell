#include "shell.h"
/**
 * *_realloc - copies elements from allocated memory to a new one
 * @ptr: old allocated memory
 * @old_size: size of ptr
 * @new_size: size of new allocated memory
 *
 * Return: new allocated memory
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *second;
	unsigned int i = 0;
	char *arr1;
	char *arr2;

	if (ptr == NULL)
	{
		ptr = malloc(new_size);
		return (ptr);
	}
	if (old_size == new_size)
		return (ptr);
	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}
	second = malloc(new_size);
	if (second == NULL)
		return (NULL);
	arr1 = ptr;
	arr2 = second;
	if (new_size > old_size)
	{
		for (i = 0; i < old_size; i++)
			*(arr2 + i) = *(arr1 + i);
		free(arr1);
	}
	else
	{
		for (i = 0; i < new_size; i++)
			*(arr2 + i) = *(arr1 + i);
		free(arr1);
	}
	return (second);
}
