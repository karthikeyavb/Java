#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAXN 26
#define MAXP 256
#define MAXRHS 256
#define ASCII 256

// Grammar
int nt_used[MAXN];
char rhs[MAXN][MAXP][MAXRHS];
int rhs_cnt[MAXN];

int firstSet[MAXN][ASCII];
int followSet[MAXN][ASCII];

int startNT = -1;

int is_nt(unsigned char c) {
    return (c >= 'A' && c <= 'Z');
}

int ntIndex(unsigned char X) {
    return X - 'A';
}

int add(int S[ASCII], int x) {
    if (!S[x]) {
        S[x] = 1;
        return 1;
    }
    return 0;
}

void first_of_sequence(const char *str, int pos, int out[ASCII]) {
    memset(out, 0, ASCII * sizeof(int));
    int len = (int)strlen(str);

    if (pos >= len) {
        out[(unsigned char)'#'] = 1;
        return;
    }

    bool all_eps = true;
    for (int i = pos; i < len; ++i) {
        unsigned char Y = str[i];
        if (!is_nt(Y)) {
            add(out, Y);
            all_eps = false;
            break;
        } else {
            int Yi = ntIndex(Y);
            bool has_epsilon_in_first = false;
            for (int c = 0; c < ASCII; ++c) {
                if (firstSet[Yi][c]) {
                    if (c == '#') {
                        has_epsilon_in_first = true;
                    } else {
                        add(out, c);
                    }
                }
            }
            if (!has_epsilon_in_first) {
                all_eps = false;
                break;
            }
        }
    }
    if (all_eps) {
        add(out, '#');
    }
}

void print_set_ascii(const int S[256]) {
    int printed = 0;
    for (int c = 0; c < 256; ++c) {
        if (S[c]) {
            if (printed) {
                printf(", ");
            }
            if (c == '#') {
                printf("#");
            } else if (c == '$') {
                printf("$");
            } else {
                printf("%c", c);
            }
            printed = 1;
        }
    }
    if (!printed) {
        printf("empty");
    }
}

int main() {
    int n;
    if (scanf("%d\n", &n) != 1) return 0;

    for (int i = 0; i < n; ++i) {
        char line[1024];
        if (!fgets(line, sizeof(line), stdin)) return 0;

        char cleaned[1024];
        int p = 0;
        for (int k = 0; line[k]; ++k) {
            unsigned char ch = (unsigned char)line[k];
            if (!isspace(ch)) {
                cleaned[p++] = ch;
            }
        }
        cleaned[p] = '\0';

        if (p < 4 || !is_nt(cleaned[0]) || strncmp(cleaned + 1, "->", 2) != 0) {
            fprintf(stderr, "Error: malformed production '%s'\n", cleaned);
            return 1;
        }

        unsigned char A = (unsigned char)cleaned[0];
        int Ai = ntIndex(A);
        if (startNT == -1) {
            startNT = Ai;
        }
        nt_used[Ai] = 1;

        const char* r = cleaned + 3;
        int alt = 0, bi = 0;
        char buf[1024];
        for (int k = 0; ; ++k) {
            char ch = r[k];
            if (ch == '|' || ch == '\0') {
                buf[bi] = '\0';
                if (bi == 0) {
                    strcpy(rhs[Ai][alt++], "#");
                } else {
                    strcpy(rhs[Ai][alt++], buf);
                }
                bi = 0;
                if (ch == '\0') break;
            } else {
                buf[bi++] = ch;
            }
        }
        rhs_cnt[Ai] = alt;
    }

    // FIRST
    bool changed = true;
    while (changed) {
        changed = false;
        for (int A = 0; A < MAXN; ++A) {
            if (nt_used[A]) {
                for (int r = 0; r < rhs_cnt[A]; ++r) {
                    const char* alpha = rhs[A][r];
                    if (strcmp(alpha, "#") == 0) {
                        if (add(firstSet[A], '#')) {
                            changed = true;
                        }
                        continue;
                    }

                    bool all_eps = true;
                    for (int i = 0; alpha[i]; ++i) {
                        unsigned char Y = alpha[i];
                        if (!is_nt(Y)) {
                            if (add(firstSet[A], Y)) {
                                changed = true;
                            }
                            all_eps = false;
                            break;
                        }

                        int Yi = ntIndex(Y);
                        for (int c = 0; c < ASCII; ++c) {
                            if (c != '#' && firstSet[Yi][c]) {
                                if (add(firstSet[A], c)) {
                                    changed = true;
                                }
                            }
                        }
                        if (!firstSet[Yi]['#']) {
                            all_eps = false;
                            break;
                        }
                    }
                    if (all_eps) {
                        if (add(firstSet[A], '#')) {
                            changed = true;
                        }
                    }
                }
            }
        }
    }

    // FOLLOW
    if (startNT != -1) {
        followSet[startNT]['$'] = 1;
    }
    changed = true;
    while (changed) {
        changed = false;
        for (int A = 0; A < MAXN; ++A) {
            if (nt_used[A]) {
                for (int r = 0; r < rhs_cnt[A]; ++r) {
                    const char* alpha = rhs[A][r];
                    int L = (int)strlen(alpha);
                    for (int i = 0; i < L; ++i) {
                        if (!is_nt((unsigned char)alpha[i])) continue;
                        int B = ntIndex((unsigned char)alpha[i]);
                        
                        int firstBeta[ASCII];
                        first_of_sequence(alpha, i + 1, firstBeta);
                        
                        for (int c = 0; c < ASCII; ++c) {
                            if (c != '#' && firstBeta[c]) {
                                if (add(followSet[B], c)) {
                                    changed = true;
                                }
                            }
                        }
                        
                        if (firstBeta['#']) {
                            for (int c = 0; c < ASCII; ++c) {
                                if (followSet[A][c]) {
                                    if (add(followSet[B], c)) {
                                        changed = true;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    // Output
    for (int A = 0; A < MAXN; ++A) {
        if (nt_used[A]) {
            printf("FIRST(%c) = { ", 'A' + A);
            print_set_ascii(firstSet[A]);
            printf(" }\n");
            printf("FOLLOW(%c) = { ", 'A' + A);
            print_set_ascii(followSet[A]);
            printf(" }\n");
        }
    }
    return 0;
}