/*
 * rush-1-2.c
 *
 * Implementation of ASCII rectangle drawing (rush-1-2 version).
 * Prints a bordered rectangle using '/' '\' '*' and spaces.
 */

#include <unistd.h>

enum row
{
    TOP,
    MID,
    BOTTOM
};

/*
 * Writes a character to stdout multiple times.
 *
 * ch: character to print (passed as int for write compatibility)
 * numChars: number of times to repeat the character
 */
static int my_putchar (int ch, int numChars) 
{
    for (int i = 0; i < numChars; ++i)
        write(1, &ch, 1);

    return numChars;
}

/*
 * Prints a single row of the rectangle.
 *
 * cols: number of columns in the rectangle
 * rank: indicates row type (TOP, MID, BOTTOM)
 * isOneDimensional:
 *   special case handling when rows == 1 or cols == 1
 *
 * Behavior:
 * - TOP row uses '/' and '\'
 * - BOTTOM row uses '\' and '/'
 * - MID rows use '*' borders with spaces inside
 * - handles degenerate 1D cases separately
 */
static void rowPrinter(int cols, int rank, int isOneDimensional)
{
    if (isOneDimensional)
    {
        my_putchar('*', cols);
        my_putchar('\n', 1);
        return;
    }

    switch (rank)
    {
        case TOP:
            my_putchar('/', 1);
            my_putchar('*', cols-2);
            my_putchar('\\', 1);
            break;
        case BOTTOM:
            my_putchar('\\', 1);
            my_putchar('*', cols-2);
            my_putchar('/', 1);
            break;
        default:
            my_putchar('*', 1);
            my_putchar(' ', cols-2);
            my_putchar('*', 1);  
    }

    my_putchar('\n', 1);
}

/*
 * Entry point for the rush-1-2 rectangle printer.
 *
 * rows: number of rows
 * cols: number of columns
 *
 * Behavior:
 * - Validates input dimensions
 * - Iterates over each row
 * - Determines row type (TOP, MID, BOTTOM)
 * - Handles 1D edge cases
 * - Delegates printing to rowPrinter
 */
void rush (int cols, int rows) 
{
    if (rows <= 0 || cols <= 0) 
    {
        write(2, "Invalid size\n", 13);
        return;
    }
    for (int curRow = 0; curRow < rows; ++curRow)
    {
        enum row curRank;
        if (curRow == 0)
            curRank = TOP;
        else if (curRow == rows-1)
            curRank = BOTTOM;
        else
            curRank = MID;
        int isOneDimensional = (rows == 1 || cols == 1);
        rowPrinter(cols,curRank,isOneDimensional);
    }
}