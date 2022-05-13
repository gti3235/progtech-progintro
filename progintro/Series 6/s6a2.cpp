#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main ()
{
  char line[60 + 1];
  char word[20 + 1];

  int counter = 0; 
  int spaces  = 0; 
  int length  = 0; 
  int total = 0; 
  int i = 0;
  int j = 0;
  int blanks = 0;
  int modBlanks = 0;
  int runner = 0;

  scanf ("%s", word); 
  while (word[i] != '\0') { line[i] = word[i]; i+= 1; }
  counter = 1;

  
  while (scanf ("%s", word) != EOF) {
    length = strlen (word);
    if (i + length < 60) {
      line[i++] = ' ';
      counter += 1;
      j = 0;
      
      while (word[j] != '\0') {
      
        line[i++] = word[j++];
      }
    } 
    else {

      blanks = counter - 1;
      spaces = 60 - i;

      modBlanks = spaces % blanks;
      total = spaces / blanks;
      spaces -= modBlanks;
      for (j = 0; j < i; j++) {
        runner = total;
        if (line[j] == ' ') {
          do {
            putchar (' ');
          } while (runner-- > 0);

          if (modBlanks >= counter - 1)
           putchar (' ');

          counter -= 1;    
        }
        else { putchar (line[j]); }
      }
      putchar ('\n'); 

      counter = 1;
      total   = 1;
      i = 0;
      j = 0;
      
      while (word[j] != '\0') { line[i++] = word[j++]; }

    }

  } 

  for (j = 0; j < i; j++) { putchar (line[j]); }
    putchar ('\n');

  return (0);
}
