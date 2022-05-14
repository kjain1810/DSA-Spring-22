#include <stdlib.h>

struct DataItem
{
	int data; // You can add or delete data types
	long long key;
};

struct HashTable
{
	int size;
	struct DataItem **hashArray;
};

// Initialize a hash table with given size of entries
struct HashTable *initHashTable(int size)
{
	struct HashTable *table = (struct HashTable *)malloc(sizeof(struct HashTable));
	table->size = size;
	table->hashArray = (struct DataItem **)calloc(table->size, sizeof(struct DataItem *));
	return table;
}

// Delete an initialized hash table
void deleteHashTable(struct HashTable *table)
{
	for (int i = 0; i < table->size; ++i)
		if (table->hashArray[i] != NULL)
		{
			free(table->hashArray[i]);
			table->hashArray[i] = NULL;
		}
	free(table->hashArray);
	free(table);
}

// Function that hashes the key to an integer in [0,size of hash table)
int hashCode(struct HashTable *table, long long key)
{
	// Implement this function yourself
	return -1;
}

struct DataItem *search(struct HashTable *table, long long key)
{
	// get the hash
	int hashIndex = hashCode(table, key);

	// move in array until an empty
	while (table->hashArray[hashIndex] != NULL)
	{

		if (table->hashArray[hashIndex]->key == key)
			return table->hashArray[hashIndex];

		// go to next cell
		++hashIndex;

		// wrap around the table
		hashIndex %= table->size;
	}

	return NULL;
}

void insert(struct HashTable *table, long long key, int data)
{

	struct DataItem *item = (struct DataItem *)malloc(sizeof(struct DataItem));
	item->data = data;
	item->key = key;

	// get the hash
	int hashIndex = hashCode(table, key);

	// move in array until an empty or deleted cell
	while (table->hashArray[hashIndex] != NULL)
	{
		// go to next cell
		++hashIndex;

		// wrap around the table
		hashIndex %= table->size;
	}

	table->hashArray[hashIndex] = item;
}

struct DataItem *delete (struct HashTable *table, struct DataItem *item)
{
	long long key = item->key;

	// get the hash
	int hashIndex = hashCode(table, key);

	// move in array until an empty
	while (table->hashArray[hashIndex] != NULL)
	{

		if (table->hashArray[hashIndex]->key == key)
		{
			struct DataItem *temp = table->hashArray[hashIndex];

			// deletes the data at deleted position
			free(table->hashArray[hashIndex]);
			table->hashArray[hashIndex] = NULL;
			return temp;
		}

		// go to next cell
		++hashIndex;

		// wrap around the table
		hashIndex %= table->size;
	}

	return NULL;
}
