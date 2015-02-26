/********************************* TRICK HEADER *******************************
PURPOSE:                     ( Test scheduling )
REFERENCE:                   ( None )
ASSUMPTIONS AND LIMITATIONS: ( None )
CLASS:                       ( derivative )
LIBRARY DEPENDENCY:          ( sched_deriv.o )
PROGRAMMERS:                 ( (Keith Vetter) (Titan) (8-20-2002) (Trick tutorial) )
*******************************************************************************/

/*
 * $Id: sched_deriv.c 737 2010-06-14 20:47:08Z wwoodard $
 */

#include "../include/sched.h"


int sched_deriv(
                  /* RETURN: -- Always return zero */
  SCHEDULE *S )      /* INOUT:  -- Schedule struct */
{
   S->acc = -1 * S->pos * S->mass ;

   return( 0 );
}
