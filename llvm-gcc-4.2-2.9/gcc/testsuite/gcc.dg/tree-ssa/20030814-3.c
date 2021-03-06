/* { dg-do compile } */
/* { dg-options "-O1 -fdump-tree-dom3" } */
/* LLVM LOCAL test not applicable */
/* { dg-require-fdump "" } */
    
extern void abort (void);

void
foo (int value)
{
  switch (value)
    {
    case 40:
    case 42:
	      if (value != 42)
		abort ();
    case 50:
      blah ();
    }
}

/* There should be one IF conditional.  */
/* { dg-final { scan-tree-dump-times "if " 1 "dom3"} } */
 
/* { dg-final { cleanup-tree-dump "dom3" } } */
