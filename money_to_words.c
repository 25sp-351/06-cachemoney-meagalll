#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "moneycache.h"

void number_to_words(int num, char *buffer) {
    // This is a simplified example, you'd expand this for full word conversion.
    snprintf(buffer, 50, "%d", num);
}

const char* money_to_words(double amount) {
    char *cached_result = (char *)cache_lookup(amount);
    if (cached_result) {
        return cached_result;
    }

    int dollars = (int)amount;
    int cents = round((amount - dollars) * 100);
    char result[100];

    char dollar_part[50], cent_part[50];
    number_to_words(dollars, dollar_part);
    number_to_words(cents, cent_part);

    if (cents > 0) {
        snprintf(result, sizeof(result), "%s dollars and %s cents", dollar_part, cent_part);
    } else {
        snprintf(result, sizeof(result), "%s dollars", dollar_part);
    }

    cache_store(amount, result);
    return cache_lookup(amount);
}
