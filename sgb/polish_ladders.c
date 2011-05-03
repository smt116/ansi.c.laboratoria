#include "polish_ladders.h"

#include "gb_graph.h"
#include "gb_words.h"
#include "gb_dijk.h"
#define quit_if(x,c)  \
if(x) { \
fwprintf(stderr, \
L"Sorry, I couldn't build a dictionary (trouble code %ld)!\n",c) ; \
return c; \
} \

#define a_dist(k) (*(p+k) <*(q+k) ?*(q+k) -*(p+k) :*(p+k) -*(q+k) )  \

#define h_dist(k) (*(p+k) ==*(q+k) ?0:1)  \

wchar_t alph = 0;
wchar_t freq = 0;
wchar_t heur = 0;
wchar_t echo = 0;
unsigned long n = 0;
wchar_t randm = 0;
long seed = 0;

Graph *g;
long zero_vector[9];

Graph *gg;
wchar_t start[6], goal[6];

Vertex *uu, *vv;

long min_dist;

long freq_cost(v)
Vertex *v;
{
    register long acc = v->weight;
    register long k = 16;
    while (acc)
	k--, acc >>= 1;
    return (k < 0 ? 0 : k);
}

long alph_dist(p, q)
register wchar_t *p, *q;
{
    return a_dist(0) + a_dist(1) + a_dist(2) + a_dist(3) + a_dist(4);
}

void plant_new_edge(v)
Vertex *v;
{
    Vertex *u = gg->vertices + gg->n;
    gb_new_edge(u, v, 1L);
    if (alph)
	u->arcs->len = (u->arcs - 1)->len = alph_dist(u->name, v->name);
    else if (freq) {
	u->arcs->len = freq_cost(v);
	(u->arcs - 1)->len = 20;
    }
}

long hamm_dist(p, q)
register wchar_t *p, *q;
{
    return h_dist(0) + h_dist(1) + h_dist(2) + h_dist(3) + h_dist(4);
}

long alph_heur(v)
Vertex *v;
{
    return alph_dist(v->name, goal);
}

long hamm_heur(v)
Vertex *v;
{
    return hamm_dist(v->name, goal);
}

long prompt_for_five(s, p)
wchar_t *s;
register wchar_t *p;
{
    register wchar_t *q;
    register long c;
    while (1) {
	wprintf(L"%ls word: ", s);
	fflush(stdout);
	q = p;
	while (1) {
	    c = getwchar();
	    if (c == WEOF)
		return -1;
	    if (echo)
		putwchar(c);
	    if (c == L'\n')
		break;
	    if (!iswlower(c))
		q = p + 5;
	    else if (q < p + 5)
		*q = c;
	    q++;
	}
	if (q == p + 5)
	    return 0;
	if (q == p)
	    return 1;
	wprintf(L"(Please type five lowercase letters and RETURN.)\n");
    }
}

int main(argc, argv)
int argc;
wchar_t *argv[];
{
    setlocale(LC_CTYPE, "");
    while (--argc) {

	if (wcscmp(argv[argc], L"-v") == 0)
	    verbose = 1;
	else if (wcscmp(argv[argc], L"-a") == 0)
	    alph = 1;
	else if (wcscmp(argv[argc], L"-f") == 0)
	    freq = 1;
	else if (wcscmp(argv[argc], L"-h") == 0)
	    heur = 1;
	else if (wcscmp(argv[argc], L"-e") == 0)
	    echo = 1;
	else if (swscanf(argv[argc], L"-n%lu", &n) == 1)
	    randm = 0;
	else if (swscanf(argv[argc], L"-r%lu", &n) == 1)
	    randm = 1;
	else if (swscanf(argv[argc], L"-s%ld", &seed) == 1);
	else {
	    fwprintf(stderr,
		     L"Usage: %ls [-v][-a][-f][-h][-e][-nN][-rN][-sN]\n",
		     argv[0]);
	    return -2;
	}
    }
    if (alph || randm)
	freq = 0;
    if (freq)
	heur = 0;
    g = words(n, (randm ? zero_vector : NULL), 0L, seed);
    quit_if(g == NULL, panic_code);
    if (verbose) {
	if (alph)
	    wprintf(L"(alphabetic distance selected)\n");
	if (freq)
	    wprintf(L"(frequency-based distances selected)\n");
	if (heur)
	    wprintf
		(L"(lowerbound heuristic will be used to focus the search)\n");
	if (randm)
	    wprintf(L"(random selection of %ld words with seed %ld)\n",
		    g->n, seed);
	else
	    wprintf(L"(the graph has %ld words)\n", g->n);
    }

    if (alph) {
	register Vertex *u;
	for (u = g->vertices + g->n - 1; u >= g->vertices; u--) {
	    register Arc *a;
	    register wchar_t *p = u->name;
	    for (a = u->arcs; a; a = a->next) {
		register wchar_t *q = a->tip->name;
		a->len = a_dist(a->loc);
	    }
	}
    } else if (freq) {
	register Vertex *u;
	for (u = g->vertices + g->n - 1; u >= g->vertices; u--) {
	    register Arc *a;
	    for (a = u->arcs; a; a = a->next)
		a->len = freq_cost(a->tip);
	}
    }

    if (alph || freq || heur) {
	init_queue = init_128;
	del_min = del_128;
	enqueue = enq_128;
	requeue = req_128;
    }


    while (1) {
	putwchar(L'\n');
      restart:

	if (prompt_for_five(L"Starting", start) != 0)
	    break;
	if (prompt_for_five(L"    Goal", goal) != 0)
	    goto restart;

	gg = gb_new_graph(0L);
	quit_if(gg == NULL, no_room + 5);
	gg->vertices = g->vertices;
	gg->n = g->n;

	(gg->vertices + gg->n)->name = start;
	uu = find_word(start, plant_new_edge);
	if (!uu)
	    uu = gg->vertices + gg->n++;

	if (wcsncmp(start, goal, 5) == 0)
	    vv = uu;
	else {
	    (gg->vertices + gg->n)->name = goal;
	    vv = find_word(goal, plant_new_edge);
	    if (!vv)
		vv = gg->vertices + gg->n++;
	}


	if (gg->n == g->n + 2)
	    if (hamm_dist(start, goal) == 1) {
		gg->n--;
		plant_new_edge(uu);
		gg->n++;
	    }


	quit_if(gb_trouble_code, no_room + 6);

	if (!heur)
	    min_dist = dijkstra(uu, vv, gg, NULL);
	else if (alph)
	    min_dist = dijkstra(uu, vv, gg, alph_heur);
	else
	    min_dist = dijkstra(uu, vv, gg, hamm_heur);

	if (min_dist < 0)
	    wprintf(L"Sorry, there's no ladder from %ls to %ls.\n", start,
		    goal);
	else
	    print_dijkstra_result(vv);

	for (uu = g->vertices + gg->n - 1; uu >= g->vertices + g->n; uu--) {
	    register Arc *a;
	    for (a = uu->arcs; a; a = a->next) {
		vv = a->tip;
		vv->arcs = vv->arcs->next;
	    }
	    uu->arcs = NULL;
	}
	gb_recycle(gg);


    }
    return 0;
}
