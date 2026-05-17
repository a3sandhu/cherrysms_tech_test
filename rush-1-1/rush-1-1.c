/*
 * rush-1-1.c
 *
 * Implementation of ASCII rectangle drawing (rush-1-1 version).
 * Prints a bordered rectangle using 'o' '-' '|' and spaces.
 */

#include "rush-1-1.h"
#include <unistd.h>

/*
 * Writes a single character to stdout.
 *
 * ch: character to print (passed as int for write compatibility)
 */
static int my_putchar (int ch) 
{
    write(1, &ch, 1);
    return 1;
}

/*
 * Prints a single row of the rectangle.
 *
 * cols: number of columns in the row
 * isTopOrBottom: flag indicating if this row is top or bottom border
 *
 * Logic:
 * - corners use 'o'
 * - top/bottom edges use '-'
 * - side edges use '|'
 * - inside uses space
 */
static void rowPrinter(int cols, int isTopOrBottom)
{
    for (int curCol = 0; curCol < cols; ++curCol)
    {
        int onEdge = (curCol == 0 || curCol == cols-1);
        if(onEdge && isTopOrBottom)
            my_putchar('o');
        else if(isTopOrBottom)
            my_putchar('-');
        else if(onEdge)
            my_putchar('|');
        else
            my_putchar(' ');
    }

    my_putchar('\n');
}

/*
 * Entry point for rush-1-1 rectangle printing.
 *
 * rows: number of rows in rectangle
 * cols: number of columns in rectangle
 *
 * Behavior:
 * - Validates input
 * - Iterates over each row
 * - Determines whether row is top/bottom or middle
 * - Delegates row printing to rowPrinter
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
        int isTopOrBottom = (curRow == 0 || curRow == rows-1);
        rowPrinter(cols,isTopOrBottom);
    }
}