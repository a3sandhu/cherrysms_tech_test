/*
 * rush-1-3.h
 *
 * Public interface for ASCII rectangle drawing functions.
 */

#ifndef RUSH_1_3_H
#define RUSH_1_3_H

/*
 * Prints an ASCII rectangle to standard output.
 *
 * rows: number of rows in the rectangle
 * cols: number of columns in the rectangle
 *
 * Output format (rush-1-3):
 *   - 'A' for top border corners
 *   - 'C' for bottom border corners
 *   - 'B' for edges
 *   - ' ' for interior space
 */
void rush(int cols, int rows);

#endif