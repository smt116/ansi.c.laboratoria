#include "polish_ladders.h"

#include <stdio.h> 
#include <stdlib.h> 
#ifdef SYSV
#include <string.h> 
#else
#include <strings.h> 
#endif
#undef min
typedef union{
struct vertex_struct*V;
struct arc_struct*A;
struct graph_struct*G;
wchar_t *S;
long I;
}util;

typedef struct vertex_struct{
struct arc_struct*arcs;
wchar_t *name;
util u,v,w,x,y,z;
}Vertex;

typedef struct arc_struct{
struct vertex_struct*tip;
struct arc_struct*next;
long len;
util a,b;
}Arc;

#define init_area(s)  *s= NULL
struct area_pointers{
wchar_t *first;
struct area_pointers*next;

};

typedef struct area_pointers*Area[1];

#define ID_FIELD_SIZE 161
typedef struct graph_struct{
Vertex*vertices;
long n;
long m;
  wchar_t id[ID_FIELD_SIZE]; 
  wchar_t util_types[15]; 
Area data;
Area aux_data;
util uu,vv,ww,xx,yy,zz;
}Graph;

typedef unsigned long siz_t;

extern long verbose;
extern long panic_code;

#define alloc_fault (-1) 
#define no_room 1 
#define early_data_fault 10 
#define late_data_fault 11 
#define syntax_error 20 
#define bad_specs 30 
#define very_bad_specs 40 
#define missing_operand 50 
#define invalid_operand 60 
#define impossible 90 

extern long gb_trouble_code;

extern wchar_t *gb_alloc();
#define gb_typed_alloc(n,t,s) \
               (t*)gb_alloc((long)((n)*sizeof(t)),s)
extern void gb_free();

#define n_1  uu.I
#define mark_bipartite(g,n1) g->n_1= n1,g->util_types[8]= 'I'

extern long extra_n;

extern wchar_t  null_string[];
extern void make_compound_id();

extern void make_double_compound_id();

extern siz_t edge_trick;

#define gb_new_graph gb_nugraph 
#define gb_new_arc gb_nuarc
#define gb_new_edge gb_nuedge
extern Graph*gb_new_graph();
extern void gb_new_arc();
extern Arc*gb_virgin_arc();
extern void gb_new_edge();
extern wchar_t *gb_save_string();
extern void switch_to_graph();
extern void gb_recycle();

extern void hash_in();
extern Vertex*hash_out();
extern void hash_setup();
extern Vertex*hash_lookup();
