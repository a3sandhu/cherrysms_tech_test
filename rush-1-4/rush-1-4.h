/*
 * rush-1-4.h
 *
 * Public interface for ASCII rectangle drawing functions.
 */

#ifndef RUSH_1_4_H
#define RUSH_1_4_H

/*
 * Prints an ASCII rectangle to standard output.
 *
 * rows: number of rows in the rectangle
 * cols: number of columns in the rectangle
 *
 * Output format (rush-1-4):
 *   - 'A' for left border corners
 *   - 'C' for right border corners
 *   - 'B' for edges
 *   - ' ' for interior space
 */
void rush(int cols, int rows);

#endif