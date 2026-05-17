/*
 * rush-1-2.h
 *
 * Public interface for ASCII rectangle drawing functions.
 */

#ifndef RUSH_1_2_H
#define RUSH_1_2_H

/*
 * Prints an ASCII rectangle to standard output.
 *
 * rows: number of rows in the rectangle
 * cols: number of columns in the rectangle
 *
 * Output format (rush-1-2):
 *   - '/' and '\' for top border corners
 *   - '\' and '/' for bottom border corners
 *   - '*' for edges
 *   - ' ' for interior space
 */
void rush(int cols, int rows);

#endif