#ifdef __HUCC__

// malloc() is not supported in HuCC at this time.
main()
{
    exit (0);
}

#else

#include <stdlib.h>

int *a, *b;
int n;

#ifdef STACK_SIZE
//#define BLOCK_SIZE (STACK_SIZE / (sizeof (*a) + sizeof (*b)))
#define BLOCK_SIZE 128
#else
#define BLOCK_SIZE 32768
#endif
foo ()
{
  int i;
  for (i = 0; i < n; i++)
    a[i] = -1;
  for (i = 0; i < BLOCK_SIZE - 1; i++)
    b[i] = -1;
}

main ()
{
  n = BLOCK_SIZE;
  a = malloc (n * sizeof(int));//*a));
  b = malloc (n * sizeof(int));//*b));
  *b++ = 0;
  foo ();
  if (b[-1])
    abort ();
  exit (0);
}

#endif // __HUCC__
