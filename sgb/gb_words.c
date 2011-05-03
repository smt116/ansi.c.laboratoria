#include "gb_io.h"
#include "gb_flip.h"

#include "gb_graph.h"
#include "gb_sort.h"
#define panic(c) {gb_free(node_blocks) ; \
panic_code= c;gb_trouble_code= 0;return NULL;} \

#define nodes_per_block 111 \

#define copy5(y,x) { \
*(y) = *(x) ; \
*((y) +1) = *((x) +1) ; \
*((y) +2) = *((x) +2) ; \
*((y) +3) = *((x) +3) ; \
*((y) +4) = *((x) +4) ; \
} \

#define hash_prime 5309 \

#define weight u.I
#define loc a.I \

#define mtch(i) (*(q+i) ==*(r+i) )
#define match(a,b,c,d) (mtch(a) &&mtch(b) &&mtch(c) &&mtch(d) )
#define store_loc_of_diff(k) cur_vertex->arcs->loc= (cur_vertex->arcs-1) ->loc= k
#define ch(q) ((long) *(q) )
#define hdown(k) h==htab[k]?h= htab[k+1]-1:h-- \

typedef struct node_struct {
    long key;
    struct node_struct *link;
    wchar_t wd[5];

} node;

typedef Vertex *hash_table[hash_prime];

static long max_c[] = { 15194, 3560, 4467, 460, 6976, 756, 362 };

static long default_wt_vector[] = { 100, 10, 4, 2, 2, 1, 1, 1, 1 };

static Area node_blocks;

static hash_table *htab;

static double flabs(x)
long x;
{
    if (x >= 0)
	return (double) x;
    return -((double) x);
}

static long iabs(x)
long x;
{
    if (x >= 0)
	return (long) x;
    return -((long) x);
}

Graph *words(n, wt_vector, wt_threshold, seed)
unsigned long n;
long wt_vector[];
long wt_threshold;
long seed;
{

    Graph *new_graph;

    register long wt;
    wchar_t word[5];
    long nn = 0;

    node *next_node;
    node *bad_node;
    node *stack_ptr;
    node *cur_node;

    Vertex *cur_vertex;
    wchar_t *next_string;

    gb_init_rand(seed);

    if (!wt_vector)
	wt_vector = default_wt_vector;
    else {
	register double flacc;
	register long *p, *q;
	register long acc;

	p = wt_vector;
	flacc = flabs(*p++);
	if (flacc < flabs(*p))
	    flacc = flabs(*p);

	for (q = &max_c[0]; q < &max_c[7]; q++)
	    flacc += *q * flabs(*++p);
	if (flacc >= (double) 0x60000000)
	    panic(very_bad_specs);

	p = wt_vector;
	acc = iabs(*p++);
	if (acc < iabs(*p))
	    acc = iabs(*p);

	for (q = &max_c[0]; q < &max_c[7]; q++)
	    acc += *q * iabs(*++p);
	if (acc >= 0x40000000)
	    panic(bad_specs);

    }
    next_node = bad_node = stack_ptr = NULL;
    if (gb_open("plwords.dat") != 0)
	panic(early_data_fault);
	do {
	register long j;
	for (j = 0; j < 5; j++)
	    word[j] = gb_char();
	{
	    register long *p, *q;
	    register long c;
	    switch (gb_char()) {
	    case L'*':
		wt = wt_vector[0];
		break;
	    case L'+':
		wt = wt_vector[1];
		break;
	    case L' ':
	    case L'\n':
		wt = 0;
		break;
	    default:
		panic(syntax_error);
	    }
	    p = &max_c[0];
	    q = &wt_vector[2];
	    do {
		if (p == &max_c[7])
		    panic(syntax_error + 1);
		c = gb_number(10);
		if (c > *p++)
		    panic(syntax_error + 2);
		wt += c ** q++;
	    } while (gb_char() == L',');
	}


	if (wt >= wt_threshold) {
	    if (next_node == bad_node) {
		cur_node =
		    gb_typed_alloc(nodes_per_block, node, node_blocks);
		if (cur_node == NULL)
		    panic(no_room + 1);
		next_node = cur_node + 1;
		bad_node = cur_node + nodes_per_block;
	    } else
		cur_node = next_node++;
	    cur_node->key = wt + 0x40000000;
	    cur_node->link = stack_ptr;
	    copy5(cur_node->wd, word);
	    stack_ptr = cur_node;

	    nn++;
	}
	gb_newline();
    }
    while (!gb_eof());
    if (gb_close() != 0)
	panic(late_data_fault);
    gb_linksort(stack_ptr);
    if (n == 0 || nn < n)
	n = nn;
    new_graph = gb_new_graph(n);
    if (new_graph == NULL)
	panic(no_room);
    if (wt_vector == default_wt_vector)
	wprintf(new_graph->id, L"words(%lu,0,%ld,%ld)", n, wt_threshold,
		seed);
    else
	wprintf(new_graph->id,
		L"words(%lu,{%ld,%ld,%ld,%ld,%ld,%ld,%ld,%ld,%ld},%ld,%ld)",
		n, wt_vector[0], wt_vector[1], wt_vector[2], wt_vector[3],
		wt_vector[4], wt_vector[5], wt_vector[6], wt_vector[7],
		wt_vector[8], wt_threshold, seed);
    wcscpy(new_graph->util_types, L"IZZZZZIZZZZZZZ");
    cur_vertex = new_graph->vertices;
    next_string = gb_typed_alloc(6 * n, wchar_t, new_graph->data);
    htab = gb_typed_alloc(5, hash_table, new_graph->aux_data);


    if (gb_trouble_code == 0 && n) {
	register long j;
	register node *p;
	nn = n;
	for (j = 127; j >= 0; j--)
	    for (p = (node *) gb_sorted[j]; p; p = p->link) {
		{
		    register wchar_t *q;
		    q = cur_vertex->name = next_string;
		    next_string += 6;
		    copy5(q, p->wd);
		    cur_vertex->weight = p->key - 0x40000000;
		    {
			register wchar_t *r;
			register Vertex **h;
			register long raw_hash;
			raw_hash =
			    (((((((ch(q) << 5) + ch(q + 1)) << 5) +
				ch(q + 2)) << 5) + ch(q + 3)) << 5) +
			    ch(q + 4);
			for (h =
			     htab[0] + (raw_hash -
					(ch(q) << 20)) % hash_prime; *h;
			     hdown(0)) {
			    r = (*h)->name;
			    if (match(1, 2, 3, 4))
				gb_new_edge(cur_vertex, *h, 1L),
				    store_loc_of_diff(0);
			}
			*h = cur_vertex;
			for (h =
			     htab[1] + (raw_hash -
					(ch(q + 1) << 15)) % hash_prime;
			     *h; hdown(1)) {
			    r = (*h)->name;
			    if (match(0, 2, 3, 4))
				gb_new_edge(cur_vertex, *h, 1L),
				    store_loc_of_diff(1);
			}
			*h = cur_vertex;
			for (h =
			     htab[2] + (raw_hash -
					(ch(q + 2) << 10)) % hash_prime;
			     *h; hdown(2)) {
			    r = (*h)->name;
			    if (match(0, 1, 3, 4))
				gb_new_edge(cur_vertex, *h, 1L),
				    store_loc_of_diff(2);
			}
			*h = cur_vertex;
			for (h =
			     htab[3] + (raw_hash -
					(ch(q + 3) << 5)) % hash_prime; *h;
			     hdown(3)) {
			    r = (*h)->name;
			    if (match(0, 1, 2, 4))
				gb_new_edge(cur_vertex, *h, 1L),
				    store_loc_of_diff(3);
			}
			*h = cur_vertex;
			for (h =
			     htab[4] + (raw_hash - ch(q + 4)) % hash_prime;
			     *h; hdown(4)) {
			    r = (*h)->name;
			    if (match(0, 1, 2, 3))
				gb_new_edge(cur_vertex, *h, 1L),
				    store_loc_of_diff(4);
			}
			*h = cur_vertex;
		    }

		    cur_vertex++;
		}

		if (--nn == 0)
		    goto done;
	    }
    }
  done:gb_free(node_blocks);

    if (gb_trouble_code) {
	gb_recycle(new_graph);
	panic(alloc_fault);
    }
    return new_graph;
}

Vertex *find_word(q, f)
wchar_t *q;
void (*f) ();

{
    register wchar_t *r;
    register Vertex **h;
    register long raw_hash;
    raw_hash =
	(((((((ch(q) << 5) + ch(q + 1)) << 5) + ch(q + 2)) << 5) +
	  ch(q + 3)) << 5) + ch(q + 4);
    for (h = htab[0] + (raw_hash - (ch(q) << 20)) % hash_prime; *h;
	 hdown(0)) {
	r = (*h)->name;
	if (mtch(0) && match(1, 2, 3, 4))
	    return *h;
    }
    if (f) {
	for (h = htab[0] + (raw_hash - (ch(q) << 20)) % hash_prime; *h;
	     hdown(0)) {
	    r = (*h)->name;
	    if (match(1, 2, 3, 4))
		(*f) (*h);
	}
	for (h = htab[1] + (raw_hash - (ch(q + 1) << 15)) % hash_prime; *h;
	     hdown(1)) {
	    r = (*h)->name;
	    if (match(0, 2, 3, 4))
		(*f) (*h);
	}
	for (h = htab[2] + (raw_hash - (ch(q + 2) << 10)) % hash_prime; *h;
	     hdown(2)) {
	    r = (*h)->name;
	    if (match(0, 1, 3, 4))
		(*f) (*h);
	}
	for (h = htab[3] + (raw_hash - (ch(q + 3) << 5)) % hash_prime; *h;
	     hdown(3)) {
	    r = (*h)->name;
	    if (match(0, 1, 2, 4))
		(*f) (*h);
	}
	for (h = htab[4] + (raw_hash - ch(q + 4)) % hash_prime; *h;
	     hdown(4)) {
	    r = (*h)->name;
	    if (match(0, 1, 2, 3))
		(*f) (*h);
	}
    }

    return NULL;
}
