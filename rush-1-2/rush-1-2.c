#include <unistd.h>
#include <stdio.h>

enum row
{
    TOP,
    MID,
    BOTTOM
};

int my_putchar (int ch, int numChars) {
    for (int i = 0; i < numChars; i++)
    {
        write(1, &ch, 1);
    }
    return numChars;
}

void rowPrinter(int cols, int rank, int isOneDimensional)
{
    if (isOneDimensional)
    {
        my_putchar('*',cols);
        my_putchar('\n',1);
        return;
    }

    switch (rank)
    {
        case TOP:
            my_putchar('/',1);
            my_putchar('*', cols-2);
            my_putchar('\\',1);
            break;
        case BOTTOM:
            my_putchar('\\',1);
            my_putchar('*', cols-2);
            my_putchar('/',1);
            break;
        default:
            my_putchar('*',1);
            my_putchar(' ', cols-2);
            my_putchar('*',1);  
    }
    /*
    else if (isTopOrBottom)
    {
        my_putchar('/',1);
        my_putchar('*', cols-2);
        my_putchar('\\',1);
    }
    else
    {
        my_putchar('*',1);
        my_putchar(' ', cols-2);
        my_putchar('*',1);   
    }
    */
    my_putchar('\n',1);

}

void rush (int rows, int cols) 
{
    if (rows <= 0 || cols <= 0) 
    {
        fprintf(stderr, "Invalid size\n");
        return;
    }
    for(int curRow=0; curRow<rows; ++curRow)
    {
        //int isTopOrBottom = (curRow == 0 || curRow == rows-1);
        enum row curRank;
        if (curRow == 0)
            curRank = TOP;
        else if (curRow == rows - 1)
            curRank = BOTTOM;
        else
            curRank = MID;
        int isOneDimensional = (rows == 1 || cols == 1);
        rowPrinter(cols,curRank,isOneDimensional);
    }
}