#include <stdio.h> 
#include <stdlib.h>

#define DELAY 10000000

struct timer 
{
  int hours; 
  int minutes; 
  int seconds; 
}; 

void init(struct timer *t); 
void delay(); 
void display(struct timer *t); 
void updated(struct timer *t); 

int main(int argc, char **argv)
{
  struct timer clock; 
  init(&clock); 
  while(1)
  {
    display(&clock); 
    updated(&clock); 
  }
  return 0; 
}

void init(struct timer *t)
{
  t->hours = 0; 
  t->minutes = 0; 
  t->seconds = 0; 
}

void delay()
{
  register int i; 
  for(i=0;i<DELAY;i++); 
}

void display(struct timer *t)
{
  printf("%d: ", t->hours); 
  printf("%d: ", t->minutes);
  printf("%d\n", t->seconds); 
}

void updated(struct timer *t)
{
  t->seconds++;
  if(t->seconds==60)
  {
    t->seconds = 0; 
    t->minutes++; 
  }
  if(t->minutes==60)
  {
    t->minutes = 0; 
    t->hours++; 
  }
  if(t->hours==24) t->hours = 0; 
  delay(); 
}