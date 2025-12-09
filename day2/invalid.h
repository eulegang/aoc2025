#ifndef INVALID_H
#define INVALID_H

void visit_invalids(long a, long b, void (&invalid_handler)(long));

int digits(long value);
long expand(int i);

#endif
