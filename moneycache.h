#ifndef CACHE_H
#define CACHE_H

#include <stdlib.h>
#include <string.h>

typedef struct CacheEntry {
    double key;
    char value[100];
    struct CacheEntry *next;
} CacheEntry;

void cache_init();
const char* cache_lookup(double key);
void cache_store(double key, const char *value);
void cache_free();

#endif // CACHE_H
