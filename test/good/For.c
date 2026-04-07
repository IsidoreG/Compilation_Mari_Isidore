#include <stdio.h>
#include <stdlib.h>
#include "tgc.h"
#pragma GCC diagnostic ignored "-Wpointer-to-int-cast"
#pragma GCC diagnostic ignored "-Wint-to-pointer-cast"
struct array { int* array; int length; };
tgc_t gc;
struct ForAux;
void* ForAux_f(struct ForAux* this);
struct ForAux {
  void* (**vtable)();
};
void* (*ForAux_vtable[])() = { ForAux_f };
void* ForAux_f(struct ForAux* this) {
  int i;
  int res;
  i = 0;
  res = 0;
  for (i = 0; (i < 10); i = (i + 1)) {
    res = (res + 2);
  }
  return (void*)(res);
}
int main(int argc, char *argv[]) {
  tgc_start(&gc, &argc);
  printf("%d\n", ({ struct ForAux* tmp1 = ({ struct ForAux* res = tgc_calloc(({ extern tgc_t gc; &gc; }), 1, sizeof(*res)); res->vtable = ForAux_vtable; res; }); (int) tmp1->vtable[0](tmp1); }));
  tgc_stop(&gc);

  return 0;
}
