#include <stdio.h>

// This file exists to exercise the outdated-thread rendering path.
// The fixture posts a review comment on the original version of
// `compute_value` below, then a follow-up commit changes the line
// the comment was anchored to. GitHub then reports `line: null` and
// only `originalLine` survives in the GraphQL `reviewThreads` query.

static int compute_value(int seed) {
    int factor = 23;
    int offset = 7;
    int adjusted = seed * factor;
    return adjusted + offset;
}

int main(void) {
    int seed = 42;
    int v = compute_value(seed);
    printf("value = %d\n", v);
    return 0;
}
