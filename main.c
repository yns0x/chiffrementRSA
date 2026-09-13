#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "utils.h"

int main(int argc, char *argv[]) {
    system("cls");
    asciiMenu(argc);
    if (strcmp(argv[1], "--gen") == 0) {
        const Secret s = genererSecret();
        const ClePublique pub = genererClePub(s);
        const ClePrivee priv = genererClePriv(s, pub);
        printf("Cle privee : (%lld,%lld) \nCle publique : (%lld,%lld)", priv.d, priv.n, pub.e, pub.n );
    }
    else if (strcmp(argv[1], "--encrypt") == 0) {
        long long x, y;
        long long m;
        sscanf(argv[2], "%lld", &m);
        if (sscanf(argv[3], "(%lld,%lld)", &x, &y) == 2) {
            ClePublique p;
            p.e = x; p.n = y;
            printf("Voici le message crype : %lld",chiffrage(m, p));
        } else {
            printf("Format de cle invalide...\n");
            exit(1);
        }
    }
    else if (strcmp(argv[1], "--decrypt") == 0) {
        long long x, y;
        long long m;
        sscanf(argv[2], "%lld", &m);
        if (sscanf(argv[3], "(%lld,%lld)", &x, &y) == 2) {
            ClePrivee p;
            p.d = x; p.n = y;
            printf("Voici le message decrype : %lld",dechiffrage(m, p));
        } else {
            printf("Format de cle invalide...\n");
            exit(1);
        }
    }
}