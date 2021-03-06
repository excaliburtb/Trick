
/**
@file

@verbatim
PURPOSE:
    ( Test abstract class pointers )
@endverbatim
*******************************************************************************/

#ifndef _BALL_HH_
#define _BALL_HH_

#include <iostream>
#include <stdio.h>

class Ball {
    public:
        virtual ~Ball() {} ;
        virtual void print_type() = 0 ;
} ;

class Baseball : public Ball {
    public:
        Baseball() {} ;
        ~Baseball() {} ;
        virtual void print_type() { std::cout << "baseball" << std::endl ; } ;
} ;

class Soccerball : public Ball {
    public:
        Soccerball() {} ;
        ~Soccerball() {} ;
        virtual void print_type() { std::cout << "soccer ball" << std::endl ; } ;
} ;

#endif
