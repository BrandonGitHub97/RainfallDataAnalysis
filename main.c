/*                                                          Libraries                                                          */
#include <stdio.h> /* stdio.h library */

/* ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*/
/*                                                      Function Prototypes                                                    */

/* average function prototype */
void averageRainfallValue(float rainfallData[], int size);

/* highestRainfallValue function prototype */
void highestRainfallValue(int yearData[], float rainfallData[], int size);

/* lowestRainfallValue function prototype */
void lowestRainfallValue(int yearData[], float rainfallData[], int size);

/* ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*/
/*                                                                                                                             */

int main()
{
        int size = 768;                /* Define the size of the array - 768 values */
        int yearData[768] = {0};       /* Initialise all elements in the array that will store the year data to zero */
        float rainfallData[768] = {0}; /* Initialise all elements in the array that will store the rainfall data to zero */

        int i = 0; /* Counter used in file pointer for loop */

        /* ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*/
        /*                                        Reading Data in From rainfall.csv File                                               */

        /* Declaring a file pointer to access the rainfall.csv file */
        FILE *filePointer;

        /* Associating filePointer with the rainfall.csv file using fopen and giving read access */
        filePointer = fopen("rainfall.csv", "r");

        /* Read data from the rainfall.csv file */
        if (filePointer != NULL)
        {
                /* Get Inputs from the file */
                for (i = 0; i < size; i++)
                {
                        fscanf(filePointer, "%d , %f", &yearData[i], &rainfallData[i]);
                }

                /* Close the rainfall.csv file */
                fclose(filePointer);

                /* FOR TESTING - Print out the values in each element of the Array */
                for (i = 0; i < size; i++)
                {
                        printf("Year: %d             Rainfall value: %.2f\n", yearData[i], rainfallData[i]);
                }
        }

        else
        {
                printf("Error! The file could not be opened");
        }

        /* ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*/
        /*                                     Function Calls and Printf Statements                                                   */

        printf("------------------------------------------------------------------------------------------------------------\n"); /* For clarity */
        printf("Information about the data in the file: \n\n");

        averageRainfallValue(rainfallData, size);           /* averageRainfallValue function call */
        highestRainfallValue(yearData, rainfallData, size); /* highestRainfallValue function call */
        lowestRainfallValue(yearData, rainfallData, size);  /* lowestRainfallValue function call */

        printf("------------------------------------------------------------------------------------------------------------\n"); /* For clarity */

        return 0;
}

/* ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*/
/*                                        averageRainfallValue Function Definition                                                  */

void averageRainfallValue(float rainfallData[], int size)
{
        int i = 0;              /* Counter to be used in this function */
        float averageValue = 0; /* Variable to store the average value */

        /* For Loop to calculate average rainfall value - average rainfall value should be 63.38541667 */
        for (i = 0; i < size; i++)
        {
                averageValue = averageValue + rainfallData[i];
        }

        averageValue = averageValue / size;

        printf(" - The average rainfall value is %.2f mm.\n\n", averageValue);
}

/* ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*/
/*                                        highestRainfallValue Function Definition                                                  */

void highestRainfallValue(int yearData[], float rainfallData[], int size)
{
        int i = 0;                            /* Counter */
        float highestValue = rainfallData[0]; /* Rainfall value in rainfallData[0].  (which is 40) */
        int yearOccured = yearData[0];

        for (i < 1; i < size; i++) /* For loop to move down through the array until the end - Highest Value should be 217mm */
        {
                if (rainfallData[i] > highestValue)
                {
                        highestValue = rainfallData[i];
                        yearOccured = yearData[i];
                }
        }

        printf(" - The highest rainfall value is %.2f mm and this occured in %d.\n\n", highestValue, yearOccured);
}

/* ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*/
/*                                          lowestRainfallValue Function Definition                                                 */

void lowestRainfallValue(int yearData[], float rainfallData[], int size)
{
        int i = 0;                      /* Counter */
        float lowest = rainfallData[0]; /* Rainfall value in rainfallData[0].  (which is 40) */
        int yearOccured = yearData[0];

        for (i < 1; i < size; i++) /* For loop to move down through the rainfallData until the end - Lowest value should be*/
        {
                if (rainfallData[i] < lowest)
                {
                        lowest = rainfallData[i];
                        yearOccured = yearData[i];
                }
        }

        printf(" - The lowest rainfall value is %.2f mm and this occured in %d.\n\n", lowest, yearOccured);
}
