#include <unistd.h>
#include <stdio.h>

int my_putchar (int ch) {
    return 0;
}

void rowPrinter(int cols, int isTopOrBottom)
{
    for(int curCol = 0; curCol<cols; ++curCol)
    {
        int onEdge = (curCol == 0 || curCol == cols-1);

        if(onEdge && isTopOrBottom)
        {
            my_putchar('o');
        }

        else if(isTopOrBottom)
        {
            my_putchar('-');
        }

        else if(onEdge)
        {
            my_putchar('|');
        }
        else
        {
            my_putchar(' ');
        }
    }
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
        int isTopOrBottom = (curRow == 0 || curRow == rows-1);
        rowPrinter(cols,isTopOrBottom);
    }
}
int main() {
    rush(1,1);
    return 0;
}