#include <stdio.h>
#include <stdlib.h> // for exit(1)
#include "anagrams.h"
int main(int args, char *argv[])
{

 if (args == 3)
 {
 int ans = anagrams(argv[1], argv[2]);


 if (ans == 1) // anagrams
    {
    printf("%s is an anagram of %s", argv[1], argv[2]);
    }

 else
    {
    printf("%s and %s are not anagram of each other", argv[1], argv[2]);
    }
 } // end if



else
{
 printf("usage: ./a.out string1 string2\n"); //this seems to catch if there was punctuation or spaces using the argc, you could also possibly make if statments dealing with array at i equaling certain ascii codes
 exit(1);
 }
 return 0;
}//end of main