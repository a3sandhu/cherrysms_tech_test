/*
 * rush-1-1.h
 *
 * Public interface for ASCII rectangle drawing functions.
 */

#ifndef RUSH_1_1_H
#define RUSH_1_1_H

/*
 * Prints an ASCII rectangle to standard output.
 *
 * rows: number of rows in the rectangle
 * cols: number of columns in the rectangle
 *
 * Output format (rush-1-1):
 *   - 'o' for corners
 *   - '-' for top/bottom edges
 *   - '|' for side edges
 *   - ' ' for interior space
 */
void rush(int cols, int rows);

#endif