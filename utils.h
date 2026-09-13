#pragma once

typedef struct {
    long long p;
    long long q;
} Secret;

typedef struct {
    long long e;
    long long n;
} ClePublique;

typedef struct {
    long long d;
    long long n;
} ClePrivee;

int premier(long long n);

Secret genererSecret();

ClePublique genererClePub(Secret p);

ClePrivee genererClePriv(Secret p, ClePublique c);

long long chiffrage(long long m, ClePublique cpu);

long long dechiffrage(long long crypt, ClePrivee cpr);

long long algoCarre(long long mod, long long a, long long r);

void asciiMenu(int argc);