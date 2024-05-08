//Drew Kroeger, CSC250, ASSIGNMENT 2- this program takes command line numbers and makes a histogram of them
//it creates a mean and median
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char * argv[])
{
int i,j;//these are used in for loops
int test = argc;//for some reason argc did not want to be in an array index so i did this
int gradeArray[test];//need to change to argc?
int counter=0;//this counter is also used in the gradearray later on 
int valueOfAllGrades=0;//this is used to calculate the mean
int median=0;
int maximum=0;//this is used to store the max grade
if (argc<2)//if no grades are entered than it will return this and end the program
    {
        printf("No grades entered that are valid.");
        return 1;
    }

for(i = 1; i<argc;i++)//this for loop goes through from the first actual number(not the execution statement)
    {
        int grade = atoi(argv[i]);//this takes an command line argument and makes it a variable
        if (grade <0 || grade >100)//if the grade is above or below th bounds it says this
        {
            printf("%d is not a valid grade, it is out of bounds.\n", grade);
        }
        else//if the grade is in the bounds it goes here
        {
            gradeArray[counter] = grade;//this stores the grade in the gradeArray
            valueOfAllGrades += grade;//this is used for the mean, it adds the grade to the total
            counter++; //the counter goes up for the next for loop iteration so another grade can be stored
            if (grade>maximum)// this is so a maximum can be determined(something over 100 will not be stored)
            {
                grade = maximum;
            }
        } //end of if else
    }//end of for loop

    for(i=0;i<counter-1;i++)//this for loop is a bubble sort, counter-1 because the counter{max} comes out weird
    {
        for(j=0;j<counter-i-1;j++)
        {
            if(gradeArray[j]>gradeArray[j+1])
            {
                int temp = gradeArray[j];
                gradeArray[j]=gradeArray[j+1];
                gradeArray[j+1]=temp;
            }//end of if
        }//end of j for loop
    }//end of second main/sort for loop



    printf("Histogram: \n");//start of the printing of histogram
    for (i=0;i<counter-1;i++)//counter is counter-1 as the value at max counter is not apart of what was entered.
    {
        if(i==0 || gradeArray[i] != gradeArray[i-1])//if i is the first element or the element of grade array is not the same as the last it goes here 
        {
            int numOfDuplicates= 1; //this makes so each variable starts at 1
            while(i<counter && gradeArray[i]==gradeArray[i+1]) // if the i is not at the end of the array and it is a duplicate it goes here
            
                {
                numOfDuplicates++; //this add duplicates to the first instance of a histogram
                i++; //this iterates i so it moves on before the end of the loop, keeping adding duplicates to the histogram
                }
           printf("number of %d's: %d \n", gradeArray[i],(numOfDuplicates));//this finally prints the histograms
        }
    }
    //printf("argc %d\n", argc); this was used to determine the argc value for the median as i was having trouble
    if(argc % 2 == 0)//if argc is even or odd will determine how it finds the median
        {
                median = ((gradeArray[argc/2-1]+ gradeArray[argc/2])/2); //even argc means it adds both middle elements and finds avg
        }
        else
        {
                median = (gradeArray[(argc)/2]); //odd argc simply finds middle element
        }
    //the commented out code below was used to figure out each element of the grade array, somehow the last element would be irrelevant, which is why the counter would be -1 sometimes
    //for (i=0;i<argc;i++)
    //{
       // printf("Array value at %d:%d\n",i,gradeArray[i]);
    //}
    printf("The median is %d \n", median);//prints the median value
    double average = (double)valueOfAllGrades / counter;//calculates the average
    printf("Mean:%f \n",average);//prints the mean
}//end of class