extern long dijkstra();
#define print_dijkstra_result p_dijkstra_result 
extern void print_dijkstra_result();

#define dist z.I
#define backlink y.V

extern void(*init_queue)();

extern void(*enqueue)();
extern void(*requeue)();
extern Vertex*(*del_min)();

#define hh_val x.I

extern void init_dlist();
extern void enlist();
extern void reenlist();
extern Vertex*del_first();
extern void init_128();
extern Vertex*del_128();
extern void enq_128();
extern void req_128();
