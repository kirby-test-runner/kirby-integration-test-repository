#include <stdio.h>

// This file exists to exercise the outdated-thread rendering path.
// The fixture posts a review comment on the original version of
// `compute_value` below, then a follow-up commit changes the line
// the comment was anchored to. GitHub then reports `line: null` and
// only `originalLine` survives in the GraphQL `reviewThreads` query.
//
// A third commit further reorders the function so a SECOND review
// comment (originally on line 11, the closing brace) also becomes
// outdated — exercises the two-outdated-threads-on-same-file case.

static int compute(int seed, int factor, int offset) {
    int product = seed * factor;
    int result = product + offset;
    return result;
}

int main(void) {
    int v = compute(42, 23, 7);
    printf("value = %d\n", v);
    return 0;
}
