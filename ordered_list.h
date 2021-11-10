typedef enum BOOL
{
  false,
  true
} boolean;
typedef struct LIST List;


List * construct();
boolean insert(List * , char *);
boolean find(List *  , char * );
int node_count(List *);
int size(List *);
void print(List *);
int traversals();
void destroy(List *);
void contentAt(List *, int , char* );