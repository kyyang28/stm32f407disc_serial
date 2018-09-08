#ifndef __MATHS_H
#define __MATHS_H

// Use floating point M_PI instead explicitly.
#define M_PIf       3.14159265358979323846f

#define RAD    (M_PIf / 180.0f)

#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define ABS(x) ((x) > 0 ? (x) : -(x))

#endif	// __MATHS_H
