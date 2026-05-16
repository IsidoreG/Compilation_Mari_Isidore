#include <stdio.h>
#include <stdlib.h>
#include "tgc.h"
#pragma GCC diagnostic ignored "-Wpointer-to-int-cast"
#pragma GCC diagnostic ignored "-Wint-to-pointer-cast"
struct array { int* array; int length; };
tgc_t gc;
struct DoWhileAux;
void* DoWhileAux_w(struct DoWhileAux* this);
struct DoWhileAux {
  void* (**vtable)();
};
void* (*DoWhileAux_vtable[])() = { DoWhileAux_w };
void* DoWhileAux_w(struct DoWhileAux* this) {
  int i;
  int res;
  i = 0;
  res = 0;
  do {
    res = (res + 2);
    i = (i + 1);
  } while ((i < 10));
  if ((res == 20)) {
    printf("%d\n", 1);
  }
  else {
    printf("%d\n", 0);
  }
  return (void*)(res);
}
int main(int argc, char *argv[]) {
  tgc_start(&gc, &argc);
  printf("%d\n", ({ struct DoWhileAux* tmp1 = ({ struct DoWhileAux* res = tgc_calloc(({ extern tgc_t gc; &gc; }), 1, sizeof(*res)); res->vtable = DoWhileAux_vtable; res; }); (int) tmp1->vtable[0](tmp1); }));
  tgc_stop(&gc);

  return 0;
}
