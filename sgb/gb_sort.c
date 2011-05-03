#include "polish_ladders.h"

#include <stdio.h>
#include "gb_flip.h"

typedef struct node_struct {
    long key;
    struct node_struct *link;
} node;

node *gb_sorted[256];
static node *alt_sorted[256];

void gb_linksort(l)
node *l;
{
    register long k;
    register node **pp;
    register node *p, *q;
    for (pp = alt_sorted + 255; pp >= alt_sorted; pp--)
	*pp = NULL;

    for (p = l; p; p = q) {
	k = gb_next_rand() >> 23;
	q = p->link;
	p->link = alt_sorted[k];
	alt_sorted[k] = p;
    }

    for (pp = gb_sorted + 255; pp >= gb_sorted; pp--)
	*pp = NULL;

    for (pp = alt_sorted + 255; pp >= alt_sorted; pp--)
	for (p = *pp; p; p = q) {
	    k = gb_next_rand() >> 23;
	    q = p->link;
	    p->link = gb_sorted[k];
	    gb_sorted[k] = p;
	}

    for (pp = alt_sorted + 255; pp >= alt_sorted; pp--)
	*pp = NULL;

    for (pp = gb_sorted + 255; pp >= gb_sorted; pp--)
	for (p = *pp; p; p = q) {
	    k = p->key & 0xff;
	    q = p->link;
	    p->link = alt_sorted[k];
	    alt_sorted[k] = p;
	}

    for (pp = gb_sorted + 255; pp >= gb_sorted; pp--)
	*pp = NULL;

    for (pp = alt_sorted; pp < alt_sorted + 256; pp++)
	for (p = *pp; p; p = q) {
	    k = (p->key >> 8) & 0xff;
	    q = p->link;
	    p->link = gb_sorted[k];
	    gb_sorted[k] = p;
	}

    for (pp = alt_sorted + 255; pp >= alt_sorted; pp--)
	*pp = NULL;

    for (pp = gb_sorted + 255; pp >= gb_sorted; pp--)
	for (p = *pp; p; p = q) {
	    k = (p->key >> 16) & 0xff;
	    q = p->link;
	    p->link = alt_sorted[k];
	    alt_sorted[k] = p;
	}

    for (pp = gb_sorted + 255; pp >= gb_sorted; pp--)
	*pp = NULL;

    for (pp = alt_sorted; pp < alt_sorted + 256; pp++)
	for (p = *pp; p; p = q) {
	    k = (p->key >> 24) & 0xff;
	    q = p->link;
	    p->link = gb_sorted[k];
	    gb_sorted[k] = p;
	}


}
