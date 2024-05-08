//DREW KROEGER CSC250 ASSINGMENT 5 ANAGRAMS.C- THIS FUNCTION CHECKS IF TWO CHAR ARRAYS ARE ANAGRAMS(IF THEY CONTAIN SAME LETTERS AND AMOUNTS)
//it does this by comparing lengths, then making all the letters lowercase, then sorting them, then checking each index one by one, if this is true, we revert it back to original form
#include <stdio.h>
#include "anagrams.h"

int anagrams(char str[], char strstr[])
{
    int j=0;
    int i=0;
    int stringLength1=0;                //these two lines are used in place of the string length function
    int stringLength2=0;                //^^
    while (str[i] != '\0')              //since we need to eventually compare the length- we see how many chars are in the array until we hit the null
    {
        stringLength1 ++;
        i++;
    }
    i=0;
    while (strstr[i] != '\0')
    {
        stringLength2 ++;
        i++;
    }

    

    if (stringLength2 == stringLength1)  //if these two have the same length- they may be anagrams, if they arent we can skip all this
    {   
        char str2[stringLength1];        //we create two other arrays to take the original value of the strings to be placeholders while we mess around with the originals
        char strstr2[stringLength2];    
        for  (i =0; i<stringLength1;i++) //this is the copying of the strings
        {   
            str2[i]=str[i];
            strstr2[i] =strstr[i];
        }//end of copy for loop



        for (i=0;str[i] !='\0' ;i++)     //this is to make all the characters lowercase
        {
            if(str[i]>= 'A' && str[i] <= 'Z')
            {
                str[i]=str[i]+32;
            }

            if(strstr[i]>= 'A' && strstr[i] <= 'Z')
            {
                strstr[i]=strstr[i]+32; //+32 makes an uppercase ascii the lowercase version
            }
        }



        for (i=0;i<stringLength1-1;i++) //this is a bubble sort that sorts the elements of the array by ascii value(i think)
        {
            for (j=0;j<stringLength1-i-1;j++)
            {
                if(str[j]>str[j+1])
                {
                    char temp = str[j];
                    str[j]=str[j+1];
                    str[j+1]=temp;
                }


                if(strstr[j]>strstr[j+1])
                {
                    char temp = strstr[j];
                    strstr[j]=strstr[j+1];
                    strstr[j+1]=temp;
                }
            }//end of inner sort for loop
        }//end of outer sort for loop




        int checker =0; //this value is for a comparison in next for loop
        for (i=0;str[i] !='\0' ;i++)
        {
            if(str[i]==strstr[i]) //if the values are the same then we increment the checker value
            {
                
                checker++;
            }
            else                 //if the values are different then they are not anagrams and we can break
            {
                 for(i=0;i<stringLength1;i++) //do not want to return scrambled strings
            {
                str[i]=str2[i];
                strstr[i]=strstr2[i];
            }
            
                return 0;
            }
        }//end of checker for loop
        for(i=0;i<stringLength1;i++) //if we get through with no trouble we can assume they are anagrams, and take the temp arrays that are unchanged and put them back in originals
            {
                str[i]=str2[i];
                strstr[i]=strstr2[i];
            }//end of copy for loop
        if (checker == stringLength1)//this checks if the checker equals the string length, if it does than all elements matched with each other, so they are anagrams
        {
        return 1;                   //return back successfully
        }//if of successful if
    }//end of big if 
    else                            //if the stringlength1 doesnt equal string length2 then we already know they cannot be anagrams
    {
        return 0;
    }

}//end of anagrams.c function