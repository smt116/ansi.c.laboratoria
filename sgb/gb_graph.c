#include "polish_ladders.h"

#ifdef SYSV
#include <string.h>
#else
#include <strings.h>
#endif
#include <stdio.h>
#include <stdlib.h>
#define gb_typed_alloc(n,t,s) (t*) gb_alloc((long) ((n) *sizeof(t) ) ,s)  \

#define n_1 uu.I \

#define arcs_per_block 102 \

#define gb_new_graph gb_nugraph
#define gb_new_arc gb_nuarc
#define gb_new_edge gb_nuedge \

#define string_block_size 1016 \

#define hash_link u.V
#define hash_head v.V \

#define HASH_MULT 314159
#define HASH_PRIME 593996012 \

typedef union {
    struct vertex_struct *V;
    struct arc_struct *A;
    struct graph_struct *G;
    wchar_t *S;
    long I;
} util;

typedef struct vertex_struct {
    struct arc_struct *arcs;
    wchar_t *name;
    util u, v, w, x, y, z;
} Vertex;

typedef struct arc_struct {
    struct vertex_struct *tip;
    struct arc_struct *next;
    long len;
    util a, b;
} Arc;

#define init_area(s)  *s= NULL
struct area_pointers {
    wchar_t *first;
    struct area_pointers *next;

};

typedef struct area_pointers *Area[1];

#define ID_FIELD_SIZE 161
typedef struct graph_struct {
    Vertex *vertices;
    long n;
    long m;
    wchar_t id[ID_FIELD_SIZE];
    wchar_t util_types[15];
    Area data;
    Area aux_data;
    util uu, vv, ww, xx, yy, zz;
} Graph;

typedef unsigned long siz_t;

static Arc *next_arc;
static Arc *bad_arc;
static wchar_t *next_string;
static wchar_t *bad_string;
static Arc dummy_arc[2];
static Graph dummy_graph;
static Graph *cur_graph = &dummy_graph;

long verbose = 0;
long panic_code = 0;

long gb_trouble_code = 0;

long extra_n = 4;
wchar_t null_string[1];

siz_t edge_trick = sizeof(Arc) - (sizeof(Arc) & (sizeof(Arc) - 1));

wchar_t *gb_alloc(n, s)
size_t n;
Area s;
{
    size_t m = sizeof(wchar_t *);
    Area t;
    wchar_t *loc;	
    if (n <= 0 || n > 0xffff00 - 2 * m) {
	gb_trouble_code |= 2;
	return NULL;
    }
    n = ((n + m - 1) / m) * m;
    loc = (wchar_t *) calloc((size_t) ((n + 2 * m + 255)), 256);

    if (loc) {

	*t = (struct area_pointers *) (loc + n);

	(*t)->first = loc;

	(*t)->next = *s;

	*s = *t;

    }

    else
	gb_trouble_code |= 1;

    return loc;
}

void gb_free(s)
Area s;
{
    Area t;
    while (*s) {
	*t = (*s)->next;
	free((*s)->first);
	*s = *t;
    }
}

Graph *gb_new_graph(n)
long n;
{
    cur_graph = (Graph *) calloc(1, sizeof(Graph));
    if (cur_graph) {
	cur_graph->vertices =
	    gb_typed_alloc(n + extra_n, Vertex, cur_graph->data);
	if (cur_graph->vertices) {
	    Vertex *p;
	    cur_graph->n = n;
	    for (p = cur_graph->vertices + n + extra_n - 1;
		 p >= cur_graph->vertices; p--)
		p->name = null_string;
	    wprintf(cur_graph->id, L"gb_new_graph(%ld)", n);
	    wcscpy(cur_graph->util_types, L"ZZZZZZZZZZZZZZ");
	} else {
	    free((wchar_t *) cur_graph);
	    cur_graph = NULL;
	}
    }
    next_arc = bad_arc = NULL;
    next_string = bad_string = NULL;
    gb_trouble_code = 0;
    return cur_graph;
}

void make_compound_id(g, s1, gg, s2)
Graph *g;
wchar_t *s1;
Graph *gg;
wchar_t *s2;
{
    int avail = ID_FIELD_SIZE - wcslen(s1) - wcslen(s2);
    wchar_t tmp[ID_FIELD_SIZE];
    wcscpy(tmp, gg->id);
    if (wcslen(tmp) < avail)
	wprintf(g->id, L"%ls%ls%ls", s1, tmp, s2);
    else
	wprintf(g->id, L"%ls%.*s...)%ls", s1, avail - 5, tmp, s2);
}

void make_double_compound_id(g, s1, gg, s2, ggg, s3)

Graph *g;
wchar_t *s1;
Graph *gg;
wchar_t *s2;
Graph *ggg;
wchar_t *s3;
{
    int avail = ID_FIELD_SIZE - wcslen(s1) - wcslen(s2) - wcslen(s3);
    if (wcslen(gg->id) + wcslen(ggg->id) < avail)
	wprintf(g->id, L"%ls%ls%ls%ls%ls", s1, gg->id, s2, ggg->id, s3);
    else
	wprintf(g->id, L"%ls%.*s...)%ls%.*s...)%ls", s1, avail / 2 - 5,
		gg->id, s2, (avail - 9) / 2, ggg->id, s3);
}

Arc *gb_virgin_arc()
{
    register Arc *cur_arc = next_arc;
    if (cur_arc == bad_arc) {
	cur_arc = gb_typed_alloc(arcs_per_block, Arc, cur_graph->data);
	if (cur_arc == NULL)
	    cur_arc = dummy_arc;
	else {
	    next_arc = cur_arc + 1;
	    bad_arc = cur_arc + arcs_per_block;
	}
    } else
	next_arc++;
    return cur_arc;
}

void gb_new_arc(u, v, len)
Vertex *u, *v;
long len;
{
    register Arc *cur_arc = gb_virgin_arc();
    cur_arc->tip = v;
    cur_arc->next = u->arcs;
    cur_arc->len = len;
    u->arcs = cur_arc;
    cur_graph->m++;
}

void gb_new_edge(u, v, len)
Vertex *u, *v;
long len;
{
    register Arc *cur_arc = gb_virgin_arc();
    if (cur_arc != dummy_arc)
	next_arc++;
    if (u < v) {
	cur_arc->tip = v;
	cur_arc->next = u->arcs;
	(cur_arc + 1)->tip = u;
	(cur_arc + 1)->next = v->arcs;
	u->arcs = cur_arc;
	v->arcs = cur_arc + 1;
    } else {
	(cur_arc + 1)->tip = v;
	(cur_arc + 1)->next = u->arcs;
	u->arcs = cur_arc + 1;
	cur_arc->tip = u;
	cur_arc->next = v->arcs;
	v->arcs = cur_arc;
    }
    cur_arc->len = (cur_arc + 1)->len = len;
    cur_graph->m += 2;
}

wchar_t *gb_save_string(s)
register wchar_t *s;
{
    register wchar_t *p = s;
    register long len;

    while (*p++);
    len = p - s;
    p = next_string;
    if (p + len > bad_string) {
	long size = string_block_size;
	if (len > size)
	    size = len;

	p = gb_alloc(size, cur_graph->data);

	if (p == NULL)
	    return null_string;
	bad_string = p + size;
    }
    while (*s)
	*p++ = *s++;
    *p++ = '\0';
    next_string = p;
    return p - len;
}

void switch_to_graph(g)
Graph *g;
{
    cur_graph->ww.A = next_arc;
    cur_graph->xx.A = bad_arc;
    cur_graph->yy.S = next_string;
    cur_graph->zz.S = bad_string;
    cur_graph = (g ? g : &dummy_graph);
    next_arc = cur_graph->ww.A;
    bad_arc = cur_graph->xx.A;
    next_string = cur_graph->yy.S;
    bad_string = cur_graph->zz.S;
    cur_graph->ww.A = NULL;
    cur_graph->xx.A = NULL;
    cur_graph->yy.S = NULL;
    cur_graph->zz.S = NULL;
}

void gb_recycle(g)
Graph *g;
{
    if (g) {
	gb_free(g->data);
	gb_free(g->aux_data);
	free((wchar_t *) g);
    }
}

void hash_in(v)
Vertex *v;
{
    register wchar_t *t = v->name;
    register Vertex *u;
    {
	register long h;
	for (h = 0; *t; t++) {
	    h += (h ^ (h >> 1)) + HASH_MULT * (wchar_t) *t;
	    while (h >= HASH_PRIME)
		h -= HASH_PRIME;
	}
	u = cur_graph->vertices + (h % cur_graph->n);
    }

    v->hash_link = u->hash_head;
    u->hash_head = v;
}

Vertex *hash_out(s)
wchar_t *s;
{
    register wchar_t *t = s;
    register Vertex *u;
    {
	register long h;
	for (h = 0; *t; t++) {
	    h += (h ^ (h >> 1)) + HASH_MULT * (wchar_t) *t;
	    while (h >= HASH_PRIME)
		h -= HASH_PRIME;
	}
	u = cur_graph->vertices + (h % cur_graph->n);
    }

    for (u = u->hash_head; u; u = u->hash_link)
	if (wcscmp(s, u->name) == 0)
	    return u;
    return NULL;
}

void hash_setup(g)
Graph *g;
{
    Graph *save_cur_graph;
    if (g && g->n > 0) {
	register Vertex *v;
	save_cur_graph = cur_graph;
	cur_graph = g;
	for (v = g->vertices; v < g->vertices + g->n; v++)
	    v->hash_head = NULL;
	for (v = g->vertices; v < g->vertices + g->n; v++)
	    hash_in(v);
	g->util_types[0] = g->util_types[1] = 'V';

	cur_graph = save_cur_graph;
    }
}

Vertex *hash_lookup(s, g)
wchar_t *s;
Graph *g;
{
    Graph *save_cur_graph;
    if (g && g->n > 0) {
	register Vertex *v;
	save_cur_graph = cur_graph;
	cur_graph = g;
	v = hash_out(s);
	cur_graph = save_cur_graph;
	return v;
    } else
	return NULL;
}
