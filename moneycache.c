
#include <stdio.h>
#include moneycache.h
#define CACHE_SIZE 100

static CacheEntry *cache[CACHE_SIZE];

unsigned int hash(double key) {
    return ((unsigned int)key) % CACHE_SIZE;
}

void cache_init() {
    memset(cache, 0, sizeof(cache));
}

const char* cache_lookup(double key) {
    unsigned int index = hash(key);
    CacheEntry *entry = cache[index];

    while (entry) {
        if (entry->key == key) {
            return entry->value;
        }
        entry = entry->next;
    }
    return NULL;
}

void cache_store(double key, const char *value) {
    unsigned int index = hash(key);
    CacheEntry *new_entry = malloc(sizeof(CacheEntry));
    if (!new_entry) return;

    new_entry->key = key;
    strncpy(new_entry->value, value, sizeof(new_entry->value) - 1);
    new_entry->value[sizeof(new_entry->value) - 1] = '\0';
    new_entry->next = cache[index];
    cache[index] = new_entry;
}

void cache_free() {
    for (int i = 0; i < CACHE_SIZE; i++) {
        CacheEntry *entry = cache[i];
        while (entry) {
            CacheEntry *temp = entry;
            entry = entry->next;
            free(temp);
        }
    }
}
