/*
 * rush-1-5.h
 *
 * Public interface for ASCII rectangle drawing functions.
 */

#ifndef RUSH_1_5_H
#define RUSH_1_5_H

/*
 * Prints an ASCII rectangle to standard output.
 *
 * rows: number of rows in the rectangle
 * cols: number of columns in the rectangle
 *
 * Output format (rush-1-5):
 *   - 'A' and 'C' for top border corners
 *   - 'C' and 'A' for top border corners
 *   - 'B' for edges
 *   - ' ' for interior space
 */
void rush(int cols, int rows);

#endif