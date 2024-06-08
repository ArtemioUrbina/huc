/*	File expr.c: 2.2 (83/06/21,11:24:26) */
/*% cc -O -c %
 *
 */

#ifndef _EXPR_H
#define _EXPR_H

void expression (int comma);
intptr_t expression_ex (LVALUE *lval, int comma, int norval);
intptr_t heir1 (LVALUE *lval, int comma);
intptr_t heir1a (LVALUE *lval, int comma);
intptr_t heir1b (LVALUE *lval, int comma);
intptr_t heir1c (LVALUE *lval, int comma);
intptr_t heir2 (LVALUE *lval, int comma);
intptr_t heir3 (LVALUE *lval, int comma);
intptr_t heir4 (LVALUE *lval, int comma);
intptr_t heir5 (LVALUE *lval, int comma);
intptr_t heir6 (LVALUE *lval, int comma);
intptr_t heir7 (LVALUE *lval, int comma);
intptr_t heir8 (LVALUE *lval, int comma);
intptr_t heir9 (LVALUE *lval, int comma);
intptr_t heir10 (LVALUE *lval, int comma);
intptr_t heir11 (LVALUE *lval, int comma);
void store (LVALUE *lval);
void rvalue (LVALUE *lval);
void needlval (void);

int is_byte (LVALUE *lval);

#endif
