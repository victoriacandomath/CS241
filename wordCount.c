/*********************/
/* Victoria Varela     */
/* CS 241-002          */
/* 9/10/21             */
/* This file is used   */
/* to count the number */
/* of words, lines,    */
/* and characters      */
/* from an input file  */
/*********************/

#include <stdio.h>

/************************************/
/* Main function that reads input   */
/* and counts all the variables     */
/* Returns 0, not used for anything */
/************************************/

int main()
{
  
#define IN 1
#define OUT 0
  
  int c, lin, chars, wrd, state, linChr, linWrd;
  int maxWrd, maxChr, maxChrLin, maxWrdLin;
  c = 0;
  lin = 0;
  chars = 0;
  wrd = 0;
  linChr = 1;
  linWrd = 0;
  maxWrd = 0;
  maxChr = 0;
  maxChrLin = 0;
  maxWrdLin = 0;
  state = OUT;

  while((c=getchar()) != EOF)
    {

      if(c == '\n')
	{
	  printf("[%d, %d]", linWrd, linChr);
	  printf("\n");
	  lin++;
	  if(linChr > maxChr)
	    {
	      maxChr = linChr;
	      maxChrLin = lin;
	    }
	  if(linWrd >=  maxWrd)
	    {
	      maxWrd = linWrd;
	      maxWrdLin = lin;
	    }
	  linWrd = 0;
	  linChr = -1;
	  chars = chars - 1;
	}
      
      printf("%c", c);
      chars++;
      linChr++;

      if(c == ' ' || c == '\n' || c == '\t')
	{
	  state = OUT;
	}
 
      else if(state == OUT)
	{
	  state = IN;
	  wrd++;
	  linWrd++;
	}     
    }
  printf("\n");
  printf("%d lines, %d words, %d characters", lin, wrd, chars);
  printf("\n");
  printf("Line %d has the most words with %d", maxWrdLin, maxWrd);
  printf("\n");
  printf("Line %d has the most characters with %d", maxChrLin, maxChr);
  return 0;
}
