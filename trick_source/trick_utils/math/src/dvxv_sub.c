/*******************************************************************************
*                                                                              *
* Trick Simulation Environment Software                                        *
*                                                                              *
* Copyright (c) 1996,1997 LinCom Corporation, Houston, TX                      *
* All rights reserved.                                                         *
*                                                                              *
* Copyrighted by LinCom Corporation and proprietary to it. Any unauthorized    *
* use of Trick Software including source code, object code or executables is   *
* strictly prohibited and LinCom assumes no liability for such actions or      *
* results thereof.                                                             *
*                                                                              *
* Trick Software has been developed under NASA Government Contracts and        *
* access to it may be granted for Government work by the following contact:    *
*                                                                              *
* Contact: Charles Gott, Branch Chief                                          *
*          Simulation and Graphics Branch                                      *
*          Automation, Robotics, & Simulation Division                         *
*          NASA, Johnson Space Center, Houston, TX                             *
*                                                                              *
*******************************************************************************/
/* 
   PURPOSE: (Vector cross product difference) ASSUMPTIONS AND LIMITATIONS: ((3x1 vector implementation)) PROGRAMMERS:
   (((Les Quiocho) (NASA/JSC) (Jan 1990) (v1.0) (Init Release))) */

/* 
 * $Id: dvxv_sub.c 49 2009-02-02 22:37:59Z lin $
 */

#include "../include/trick_math.h"

void dvxv_sub(double diff[],    /* Out: Difference of cross product and difference */
              double vect1[],   /* In: Vector1 */
              double vect2[])
{                                      /* In: Vector2 */
    diff[0] -= ((vect1[1] * vect2[2]) - (vect1[2] * vect2[1]));
    diff[1] -= ((vect1[2] * vect2[0]) - (vect1[0] * vect2[2]));
    diff[2] -= ((vect1[0] * vect2[1]) - (vect1[1] * vect2[0]));

    return;
}
