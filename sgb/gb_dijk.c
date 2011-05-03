#include "gb_graph.h"
#define dist z.I \

#define backlink y.V \

#define hh_val x.I \

#define print_dijkstra_result p_dijkstra_result \

#define llink v.V
#define rlink w.V \

static Vertex head[128];

void init_dlist(d)
long d;
{
    head->llink = head->rlink = head;
    head->dist = d - 1;
}

void enlist(v, d)
Vertex *v;
long d;
{
    register Vertex *t = head->llink;
    v->dist = d;
    while (d < t->dist)
	t = t->llink;
    v->llink = t;
    (v->rlink = t->rlink)->llink = v;
    t->rlink = v;
}

void reenlist(v, d)
Vertex *v;
long d;
{
    register Vertex *t = v->llink;
    (t->rlink = v->rlink)->llink = v->llink;
    v->dist = d;
    while (d < t->dist)
	t = t->llink;
    v->llink = t;
    (v->rlink = t->rlink)->llink = v;
    t->rlink = v;
}

Vertex *del_first()
{
    Vertex *t;
    t = head->rlink;
    if (t == head)
	return NULL;
    (head->rlink = t->rlink)->llink = head;
    return t;
}

static long master_key;

void init_128(d)
long d;
{
    register Vertex *u;
    master_key = d;
    for (u = head; u < head + 128; u++)
	u->llink = u->rlink = u;
}

Vertex *del_128()
{
    long d;
    register Vertex *u, *t;
    for (d = master_key; d < master_key + 128; d++) {
	u = head + (d & 0x7f);
	t = u->rlink;
	if (t != u) {
	    master_key = d;
	    (u->rlink = t->rlink)->llink = u;
	    return t;
	}
    }
    return NULL;
}

void enq_128(v, d)
Vertex *v;
long d;
{
    register Vertex *u = head + (d & 0x7f);
    v->dist = d;
    (v->llink = u->llink)->rlink = v;
    v->rlink = u;
    u->llink = v;
}

void req_128(v, d)
Vertex *v;
long d;
{
    register Vertex *u = head + (d & 0x7f);
    (v->llink->rlink = v->rlink)->llink = v->llink;
    v->dist = d;
    (v->llink = u->llink)->rlink = v;
    v->rlink = u;
    u->llink = v;
    if (d < master_key)
	master_key = d;
}

static long dummy(v)
Vertex *v;
{
    return 0;
}

void (*init_queue) () = init_dlist;
void (*enqueue) () = enlist;
void (*requeue) () = reenlist;

Vertex *(*del_min) () = del_first;

long dijkstra(uu, vv, gg, hh)
Vertex *uu;
Vertex *vv;
Graph *gg;
long (*hh) ();
{
    register Vertex *t;
    if (!hh)
	hh = dummy;
    for (t = gg->vertices + gg->n - 1; t >= gg->vertices; t--)
	t->backlink = NULL;
    uu->backlink = uu;
    uu->dist = 0;
    uu->hh_val = (*hh) (uu);
    (*init_queue) (0L);

    t = uu;
    if (verbose)
    {
	wprintf(L"Distances from %ls", uu->name);
	if (hh != dummy)
	    wprintf(L" [%ld]", uu->hh_val);
	wprintf(L":\n");
    }


    while (t != vv) {
	{
	    register Arc *a;
	    register long d = t->dist - t->hh_val;
	    for (a = t->arcs; a; a = a->next) {
		register Vertex *v = a->tip;
		if (v->backlink) {
		    register long dd = d + a->len + v->hh_val;
		    if (dd < v->dist) {
			v->backlink = t;
			(*requeue) (v, dd);
		    }
		} else {
		    v->hh_val = (*hh) (v);
		    v->backlink = t;
		    (*enqueue) (v, d + a->len + v->hh_val);
		}
	    }
	}


	t = (*del_min) ();
	if (t == NULL)
	    return -1;

	if (verbose) {
	    wprintf(L" %ld to %ls", t->dist - t->hh_val + uu->hh_val,
		    t->name);
	    if (hh != dummy)
		wprintf(L" [%ld]", t->hh_val);
	    wprintf(L" via %ls\n", t->backlink->name);
	}

    }
    return vv->dist - vv->hh_val + uu->hh_val;
}

void print_dijkstra_result(vv)
Vertex *vv;
{
    register Vertex *t, *p, *q;
    t = NULL, p = vv;
    if (!p->backlink) {
	wprintf(L"Sorry, %ls is unreachable.\n", p->name);
	return;
    }
    do {
	q = p->backlink;
	p->backlink = t;
	t = p;
	p = q;
    } while (t != p);
    do {
	wprintf(L"%10ld %ls\n", t->dist - t->hh_val + p->hh_val, t->name);
	t = t->backlink;
    } while (t);
    t = p;
    do {
	q = t->backlink;
	t->backlink = p;
	p = t;
	t = q;
    } while (p != vv);
}
