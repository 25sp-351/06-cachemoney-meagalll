#include <stdio.h>
#include "moneycache.h"
#include "money_to_words.c"

int main() {
    cache_init();

    printf("%s\n", money_to_words(10.25));
    printf("%s\n", money_to_words(100));
    printf("%s\n", money_to_words(10.25)); // Should use cache

    cache_free();
    return 0;
}
