#include <stdio.h>
#include <unistd.h>

int
main (void)
{
  int i, egy_e;
  unsigned char b;
  
  while (read (0, (void *) &b, sizeof (unsigned char)))
    {
      for (i = 0; i < 8; ++i)
	{
	  egy_e = b & 0x80;

	  if ((egy_e >> 7) == 1)
	    printf ("1");
	  else
	    printf ("0");
	  b <<= 1;
	}
    }
}
