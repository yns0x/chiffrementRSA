#include "utils.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LIMITE 10000

int premier(const long long n) {
  long long d;
  if (n == 1) return 0;
  if (n % 2 == 0) return (n == 2);
  for (d = 3; d * d <= n; d = d + 2) if (n % d == 0) return 0;
  return 1;
}

Secret genererSecret() {
    srand(time(NULL));
    Secret c;
    do {
        c.p = 0;
        c.q = 0;
        while(!premier(c.p)) {
            c.p = rand() % LIMITE;
        }
        while(!premier(c.q)) {
            c.q = rand() % LIMITE;
        }
    } while (c.p == c.q );
    return c;
}

static long long euclideEtendu(const long long a, const long long b, long long *x, long long *y) {
    if (b == 0) {
        *x = 1;
        *y = 0;
        return a;
    }
    long long x1, y1;
    long long gcd = euclideEtendu(b, a % b, &x1, &y1);
    *x = y1;
    *y = x1 - (a / b) * y1;
    return gcd;
}

ClePublique genererClePub(Secret p) {
    long long n = p.p * p.q;
    long long e = 0;
    long long min = (p.p - 1) * (p.q - 1);
    long long x, y;
    while (euclideEtendu(e, min, &x, &y) != 1) {
        e = rand() % LIMITE;
    }
    ClePublique pu;
    pu.e = e;
    pu.n = n;
    return pu;
}

ClePrivee genererClePriv(const Secret p, const ClePublique c) {
    ClePrivee pr;
    pr.n = c.n;
    long long x, y;
    long long min = (p.p - 1) * (p.q - 1);
    euclideEtendu(c.e, min, &x, &y);
    pr.d = x % min;
    if (pr.d < 0) {
        pr.d += min;
    }
    return pr;
}

long long algoCarre(const long long mod, long long a, long long r) {
    long long p = 1;
    a = a % mod;
    while (r > 0) {
        if (r % 2 == 0) {
            r = r / 2;
        }
        else {
            r = (r - 1) / 2;
            p = (p * a) % mod;
        }
        a = (a * a) % mod;
    }
    return p;
}

long long chiffrage(const long long m, const ClePublique cpu) {
    return algoCarre(cpu.n, m, cpu.e);
}

long long dechiffrage(const long long crypt, const ClePrivee cpr){
    return algoCarre(cpr.n, crypt, cpr.d);
}

void asciiMenu(const int argc) {
    const auto sep = "\n||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||";
    printf(R"(%s)", sep);printf(R"(%s)", sep);
    printf(R"(
       ;lc  'l; ...clllllllllllllllllllc,:l;'. .........',;:ccllllllllllllllllc..'cllllll,c.  .,cl,.               .
      ..',;' .,. ;cllllllllllllllllllllllc,..                 ........',;;::cc..,cllllllc,c   .:lc;..
      .     .  .,clllllllllllllllllllllc;.            .                         ...,:::cc,;  .'llccc;'.
      ..','....  .;llllllllllllllllllc;........'',;:::;,,::::cccccccccccc::..;;;,'.... ....  .,clllllc:.
      ...cclllc:'. ':lllllllllllllllc,,,;;;;;;;,;:;;,',;;;,,;;::ccclllllc,.;cllllllllcc;..    ';cccllll.
       ..,cccccccc:..':lllllllllllllcccc:cc:;''',;:c;'..',,,;;,,,,''''...,clcllllllllllc'.   'cclllllcl. .
       .'..';::cc:::..,,clllllllllllllllc:;:clc::;:cc,.,;clllllllllll;;;::;;;;:ccllllll:,    clllllllll. .c
       .,. .clllllllc',;;:lllllllllllll:;cllll::;::;..';::::::;:;;:::ccclllllccc:ccclll;'   ;lllllllll: .;c',.
       ',...',,.',;:::'.,,,clllllllllllclllllc:;:c:: .,,,;;;;;;;;;:::cccllccclllllllllc;.  ;lllllllllc'..c'clc.
       .'..'','........ ...:lllllllllllllllll::clc;.          ............. .''''',;::;:  'llllllllllc .,,:lllc.
 .     .',lO0OOkOOxcc::.  'cllllllllllllllllcclc;'.. .cdkkkxxxddoo;'.....'coloooodkkx:'' .cllllllllll'..,:lllll;' .
 .     '...0KKKKKd',;;,,'..clc::cllllllllllllllcc;.,c0KKKKKKKKKKKd.,;;;;;;'xKKKK0Oxl;;; ':llllllllll:  .;lllllll,  '.
 .    .   '0KKKKO,';;;,.....',:cllllllllll::cllll;clo:;codxxxxkkO'';;;;;,..lkxoc'..';c..cllllllllllc.  ;llllllllc.  .
       .   :ooooc. .. ..,;;'....,:clllllllcc::,;;;:cc:.....      .   .     .....,::c:..cllllllllllc.  ;llllllllll;
.     .''............ .;;;...   . .',;:::cclllllcc:::clcc:;::;:;..'''''',;;;;;:cclc,.,cllllllllllc.  :llllllllllc.
      .,.,'''..   .. ......          ..  .  .....':cllllllllllllccccccllllllllllc;..clllllllllllc. .:lllllllllc...   .
  .  .,.''.. ....',.,,....          ..... ..       ..',;;::clllllllllllllllllllc'.'clllllllllll:. .:llllllllc'    . ...
  . .:.':.  ..,;cllllllllc,,      ......                     ...',,:lllllllllll;.:lllllllllllc,. ,clllllllc,.   .:c. ..
   .',','  .,cllllllllllllllc;          ......'',,,,'............':clllllllllllcclllllllllll:..'clllllllll:.   .'cllc.
 . .'..'..:lllllllllllllllllll:' ....,;cllllcllllllllllllcllllclllllllllllllllllllllllllllc',';lllllllll;.   .'lllll)");
    printf(R"(%s)", sep);printf(R"(%s)", sep);
    if (argc < 2) {
            printf(" --gen | Genere et renvois la paire cle privee/publique \n --encrypt number <public key> | encrypter un message a la personne ayant sa cle privee \n"
                   " --decrypt number <private key> | decrypter le message recu par une personne qui a utilise la cle publique");
            exit(1);
        }
}