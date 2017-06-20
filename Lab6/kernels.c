/********************************************************
 * Kernels to be optimized for the CS:APP Performance Lab
 ********************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "defs.h"

/* 
 * Please fill in the following team struct 
 */
team_t team = {
    "teamwork makes the dream work",			/* Team name */

    "John Dunn",		/* First member full name */
    "jcharlesdunn@gmail.com",		/* First member email address */

    "Daniel Cueva",		  /* Second member full name (leave blank if none) */
    "cueva.daniel@yahoo.com"		  /* Second member email addr (leave blank if none) */
};

/***************
 * ROTATE KERNEL
 ***************/

/******************************************************
 * Your different versions of the rotate kernel go here
 ******************************************************/

/* 
 * naive_rotate - The naive baseline version of rotate 
 */
char naive_rotate_descr[] = "naive_rotate: Naive baseline implementation";
void naive_rotate(int dim, pixel *src, pixel *dst) 
{
    int i, j;

    for (i = 0; i < dim; i++)
	for (j = 0; j < dim; j++)
	    dst[RIDX(dim-1-j, i, dim)] = src[RIDX(i, j, dim)];
}

/* 
 * rotate - Your current working version of rotate
 * IMPORTANT: This is the version you will be graded on
 */
char rotate_descr[] = "rotate: Current working version";
void rotate(int dim, pixel *src, pixel *dst) 
{
	int i, j, k, x;

	for (j = 0; j < dim; j += 16)
	{
		for (i = 0; i < dim; i += 16)
		{
			for (k = 0; k < 16; k++)
			{
				for (x = 0; x <= 12; x+=4) 	
				{
					// one less comparison. does the compare and then
					// increments. x = 0, 4, 12, 16
					*(dst+RIDX(dim-(j+k)-1, i+x, dim)) = *(src+RIDX(i+x, j+k, dim));
					*(dst+RIDX(dim-(j+k)-1, i+x+1, dim)) = *(src+RIDX(i+x+1, j+k, dim));
					*(dst+RIDX(dim-(j+k)-1, i+x+2, dim)) = *(src+RIDX(i+x+2, j+k, dim));
					*(dst+RIDX(dim-(j+k)-1, i+x+3, dim)) = *(src+RIDX(i+x+3, j+k, dim));
					/*
					*(dst+RIDX(dim-(j+k)-1, i+x+4, dim)) = *(src+RIDX(i+x+4, j+k, dim));
					*(dst+RIDX(dim-(j+k)-1, i+x+5, dim)) = *(src+RIDX(i+x+5, j+k, dim));
					*(dst+RIDX(dim-(j+k)-1, i+x+6, dim)) = *(src+RIDX(i+x+6, j+k, dim));
					*(dst+RIDX(dim-(j+k)-1, i+x+7, dim)) = *(src+RIDX(i+x+7, j+k, dim));
					*/

			   		/**(dst+RIDX(dim-(j+x+0)-1, i+k+0, dim)) = *(src+RIDX(i+k+0, j+x+0, dim));
					*(dst+RIDX(dim-(j+x+0)-1, i+k+1, dim)) = *(src+RIDX(i+k+1, j+x+0, dim));
					*(dst+RIDX(dim-(j+k+0)-1, i+x+2, dim)) = *(src+RIDX(i+x+2, j+k+0, dim));
					*(dst+RIDX(dim-(j+k+0)-1, i+x+3, dim)) = *(src+RIDX(i+x+3, j+k+0, dim));
					*(dst+RIDX(dim-(j+k+0)-1, i+x+4, dim)) = *(src+RIDX(i+x+4, j+k+0, dim));
					*(dst+RIDX(dim-(j+k+0)-1, i+x+5, dim)) = *(src+RIDX(i+x+5, j+k+0, dim));
					*(dst+RIDX(dim-(j+k+0)-1, i+x+6, dim)) = *(src+RIDX(i+x+6, j+k+0, dim));
					*(dst+RIDX(dim-(j+k+0)-1, i+x+7, dim)) = *(src+RIDX(i+x+7, j+k+0, dim));

					*(dst+RIDX(dim-(j+x+1)-1, i+k+0, dim)) = *(src+RIDX(i+k+0, j+x+1, dim));
					*(dst+RIDX(dim-(j+x+1)-1, i+k+1, dim)) = *(src+RIDX(i+k+1, j+x+1, dim));
					*(dst+RIDX(dim-(j+k+1)-1, i+x+2, dim)) = *(src+RIDX(i+x+2, j+k+1, dim));
					*(dst+RIDX(dim-(j+k+1)-1, i+x+3, dim)) = *(src+RIDX(i+x+3, j+k+1, dim));
					*(dst+RIDX(dim-(j+k+1)-1, i+x+4, dim)) = *(src+RIDX(i+x+4, j+k+1, dim));
					*(dst+RIDX(dim-(j+k+1)-1, i+x+5, dim)) = *(src+RIDX(i+x+5, j+k+1, dim));
					*(dst+RIDX(dim-(j+k+1)-1, i+x+6, dim)) = *(src+RIDX(i+x+6, j+k+1, dim));
					*(dst+RIDX(dim-(j+k+1)-1, i+x+7, dim)) = *(src+RIDX(i+x+7, j+k+1, dim));

					*(dst+RIDX(dim-(j+k+2)-1, i+x+0, dim)) = *(src+RIDX(i+x+0, j+k+2, dim));
					*(dst+RIDX(dim-(j+k+2)-1, i+x+1, dim)) = *(src+RIDX(i+x+1, j+k+2, dim));
					*(dst+RIDX(dim-(j+k+2)-1, i+x+2, dim)) = *(src+RIDX(i+x+2, j+k+2, dim));
					*(dst+RIDX(dim-(j+k+2)-1, i+x+3, dim)) = *(src+RIDX(i+x+3, j+k+2, dim));
					*(dst+RIDX(dim-(j+k+2)-1, i+x+4, dim)) = *(src+RIDX(i+x+4, j+k+2, dim));
					*(dst+RIDX(dim-(j+k+2)-1, i+x+5, dim)) = *(src+RIDX(i+x+5, j+k+2, dim));
					*(dst+RIDX(dim-(j+k+2)-1, i+x+6, dim)) = *(src+RIDX(i+x+6, j+k+2, dim));
					*(dst+RIDX(dim-(j+k+2)-1, i+x+7, dim)) = *(src+RIDX(i+x+7, j+k+2, dim));

					*(dst+RIDX(dim-(j+k+3)-1, i+x+0, dim)) = *(src+RIDX(i+x+0, j+k+3, dim));
					*(dst+RIDX(dim-(j+k+3)-1, i+x+1, dim)) = *(src+RIDX(i+x+1, j+k+3, dim));
					*(dst+RIDX(dim-(j+k+3)-1, i+x+2, dim)) = *(src+RIDX(i+x+2, j+k+3, dim));
					*(dst+RIDX(dim-(j+k+3)-1, i+x+3, dim)) = *(src+RIDX(i+x+3, j+k+3, dim));
					*(dst+RIDX(dim-(j+k+3)-1, i+x+4, dim)) = *(src+RIDX(i+x+4, j+k+3, dim));
					*(dst+RIDX(dim-(j+k+3)-1, i+x+5, dim)) = *(src+RIDX(i+x+5, j+k+3, dim));
					*(dst+RIDX(dim-(j+k+3)-1, i+x+6, dim)) = *(src+RIDX(i+x+6, j+k+3, dim));
					*(dst+RIDX(dim-(j+k+3)-1, i+x+7, dim)) = *(src+RIDX(i+x+7, j+k+3, dim));

					*(dst+RIDX(dim-(j+k+4)-1, i+x+0, dim)) = *(src+RIDX(i+x+0, j+k+4, dim));
					*(dst+RIDX(dim-(j+k+4)-1, i+x+1, dim)) = *(src+RIDX(i+x+1, j+k+4, dim));
					*(dst+RIDX(dim-(j+k+4)-1, i+x+2, dim)) = *(src+RIDX(i+x+2, j+k+4, dim));
					*(dst+RIDX(dim-(j+k+4)-1, i+x+3, dim)) = *(src+RIDX(i+x+3, j+k+4, dim));
					*(dst+RIDX(dim-(j+k+4)-1, i+x+4, dim)) = *(src+RIDX(i+x+4, j+k+4, dim));
					*(dst+RIDX(dim-(j+k+4)-1, i+x+5, dim)) = *(src+RIDX(i+x+5, j+k+4, dim));
					*(dst+RIDX(dim-(j+k+4)-1, i+x+6, dim)) = *(src+RIDX(i+x+6, j+k+4, dim));
					*(dst+RIDX(dim-(j+k+4)-1, i+x+7, dim)) = *(src+RIDX(i+x+7, j+k+4, dim));

					*(dst+RIDX(dim-(j+k+5)-1, i+x+0, dim)) = *(src+RIDX(i+x+0, j+k+5, dim));
					*(dst+RIDX(dim-(j+k+5)-1, i+x+1, dim)) = *(src+RIDX(i+x+1, j+k+5, dim));
					*(dst+RIDX(dim-(j+k+5)-1, i+x+2, dim)) = *(src+RIDX(i+x+2, j+k+5, dim));
					*(dst+RIDX(dim-(j+k+5)-1, i+x+3, dim)) = *(src+RIDX(i+x+3, j+k+5, dim));
					*(dst+RIDX(dim-(j+k+5)-1, i+x+4, dim)) = *(src+RIDX(i+x+4, j+k+5, dim));
					*(dst+RIDX(dim-(j+k+5)-1, i+x+5, dim)) = *(src+RIDX(i+x+5, j+k+5, dim));
					*(dst+RIDX(dim-(j+k+5)-1, i+x+6, dim)) = *(src+RIDX(i+x+6, j+k+5, dim));
					*(dst+RIDX(dim-(j+k+5)-1, i+x+7, dim)) = *(src+RIDX(i+x+7, j+k+5, dim));

					*(dst+RIDX(dim-(j+k+6)-1, i+x+0, dim)) = *(src+RIDX(i+x+0, j+k+6, dim));
					*(dst+RIDX(dim-(j+k+6)-1, i+x+1, dim)) = *(src+RIDX(i+x+1, j+k+6, dim));
					*(dst+RIDX(dim-(j+k+6)-1, i+x+2, dim)) = *(src+RIDX(i+x+2, j+k+6, dim));
					*(dst+RIDX(dim-(j+k+6)-1, i+x+3, dim)) = *(src+RIDX(i+x+3, j+k+6, dim));
					*(dst+RIDX(dim-(j+k+6)-1, i+x+4, dim)) = *(src+RIDX(i+x+4, j+k+6, dim));
					*(dst+RIDX(dim-(j+k+6)-1, i+x+5, dim)) = *(src+RIDX(i+x+5, j+k+6, dim));
					*(dst+RIDX(dim-(j+k+6)-1, i+x+6, dim)) = *(src+RIDX(i+x+6, j+k+6, dim));
					*(dst+RIDX(dim-(j+k+6)-1, i+x+7, dim)) = *(src+RIDX(i+x+7, j+k+6, dim));

					*(dst+RIDX(dim-(j+k+7)-1, i+x+0, dim)) = *(src+RIDX(i+x+0, j+k+7, dim));
					*(dst+RIDX(dim-(j+k+7)-1, i+x+1, dim)) = *(src+RIDX(i+x+1, j+k+7, dim));
					*(dst+RIDX(dim-(j+k+7)-1, i+x+2, dim)) = *(src+RIDX(i+x+2, j+k+7, dim));
					*(dst+RIDX(dim-(j+k+7)-1, i+x+3, dim)) = *(src+RIDX(i+x+3, j+k+7, dim));
					*(dst+RIDX(dim-(j+k+7)-1, i+x+4, dim)) = *(src+RIDX(i+x+4, j+k+7, dim));
					*(dst+RIDX(dim-(j+k+7)-1, i+x+5, dim)) = *(src+RIDX(i+x+5, j+k+7, dim));
					*(dst+RIDX(dim-(j+k+7)-1, i+x+6, dim)) = *(src+RIDX(i+x+6, j+k+7, dim));
					*(dst+RIDX(dim-(j+k+7)-1, i+x+7, dim)) = *(src+RIDX(i+x+7, j+k+7, dim));
	*/			////RIDX(i,j,n) ((i)*(n)+(j))
				////dst[(dim-1-j-k)*(dim)+i] = src[i*dim+j+k];
				// *(dst+RIDX(dim-(j+k)-1, i+x, dim)) = *(src+RIDX(i+x, j+k, dim));
				////dst[RIDX(dim-1-j, i+block, dim)] = src[(i+block)*(dim)+j];
				}
			}
		}
	}	
	/*///printf("now this\n\r");
    for (i = 0; i < dim; i+=8)
	{	
		for (j = 0; j < dim; j+=8)
		{	
				
	   		*(dst+RIDX(dim-(j+0)-1, i+0, dim)) = *(src+RIDX(i+0, j+0, dim));
			*(dst+RIDX(dim-(j+0)-1, i+1, dim)) = *(src+RIDX(i+1, j+0, dim));
			*(dst+RIDX(dim-(j+0)-1, i+2, dim)) = *(src+RIDX(i+2, j+0, dim));
			*(dst+RIDX(dim-(j+0)-1, i+3, dim)) = *(src+RIDX(i+3, j+0, dim));
			*(dst+RIDX(dim-(j+0)-1, i+4, dim)) = *(src+RIDX(i+4, j+0, dim));
			*(dst+RIDX(dim-(j+0)-1, i+5, dim)) = *(src+RIDX(i+5, j+0, dim));
			*(dst+RIDX(dim-(j+0)-1, i+6, dim)) = *(src+RIDX(i+6, j+0, dim));
			*(dst+RIDX(dim-(j+0)-1, i+7, dim)) = *(src+RIDX(i+7, j+0, dim));

	    	*(dst+RIDX(dim-(j+1)-1, i+0, dim)) = *(src+RIDX(i+0, j+1, dim));
			*(dst+RIDX(dim-(j+1)-1, i+1, dim)) = *(src+RIDX(i+1, j+1, dim));
			*(dst+RIDX(dim-(j+1)-1, i+2, dim)) = *(src+RIDX(i+2, j+1, dim));
			*(dst+RIDX(dim-(j+1)-1, i+3, dim)) = *(src+RIDX(i+3, j+1, dim));
			*(dst+RIDX(dim-(j+1)-1, i+4, dim)) = *(src+RIDX(i+4, j+1, dim));
			*(dst+RIDX(dim-(j+1)-1, i+5, dim)) = *(src+RIDX(i+5, j+1, dim));
			*(dst+RIDX(dim-(j+1)-1, i+6, dim)) = *(src+RIDX(i+6, j+1, dim));
			*(dst+RIDX(dim-(j+1)-1, i+7, dim)) = *(src+RIDX(i+7, j+1, dim));

	    	*(dst+RIDX(dim-(j+2)-1, i+0, dim)) = *(src+RIDX(i+0, j+2, dim));
			*(dst+RIDX(dim-(j+2)-1, i+1, dim)) = *(src+RIDX(i+1, j+2, dim));
			*(dst+RIDX(dim-(j+2)-1, i+2, dim)) = *(src+RIDX(i+2, j+2, dim));
			*(dst+RIDX(dim-(j+2)-1, i+3, dim)) = *(src+RIDX(i+3, j+2, dim));
			*(dst+RIDX(dim-(j+2)-1, i+4, dim)) = *(src+RIDX(i+4, j+2, dim));
			*(dst+RIDX(dim-(j+2)-1, i+5, dim)) = *(src+RIDX(i+5, j+2, dim));
			*(dst+RIDX(dim-(j+2)-1, i+6, dim)) = *(src+RIDX(i+6, j+2, dim));
			*(dst+RIDX(dim-(j+2)-1, i+7, dim)) = *(src+RIDX(i+7, j+2, dim));

	    	*(dst+RIDX(dim-(j+3)-1, i+0, dim)) = *(src+RIDX(i+0, j+3, dim));
			*(dst+RIDX(dim-(j+3)-1, i+1, dim)) = *(src+RIDX(i+1, j+3, dim));
			*(dst+RIDX(dim-(j+3)-1, i+2, dim)) = *(src+RIDX(i+2, j+3, dim));
			*(dst+RIDX(dim-(j+3)-1, i+3, dim)) = *(src+RIDX(i+3, j+3, dim));
			*(dst+RIDX(dim-(j+3)-1, i+4, dim)) = *(src+RIDX(i+4, j+3, dim));
			*(dst+RIDX(dim-(j+3)-1, i+5, dim)) = *(src+RIDX(i+5, j+3, dim));
			*(dst+RIDX(dim-(j+3)-1, i+6, dim)) = *(src+RIDX(i+6, j+3, dim));
			*(dst+RIDX(dim-(j+3)-1, i+7, dim)) = *(src+RIDX(i+7, j+3, dim));

	    	*(dst+RIDX(dim-(j+4)-1, i+0, dim)) = *(src+RIDX(i+0, j+4, dim));
			*(dst+RIDX(dim-(j+4)-1, i+1, dim)) = *(src+RIDX(i+1, j+4, dim));
			*(dst+RIDX(dim-(j+4)-1, i+2, dim)) = *(src+RIDX(i+2, j+4, dim));
			*(dst+RIDX(dim-(j+4)-1, i+3, dim)) = *(src+RIDX(i+3, j+4, dim));
			*(dst+RIDX(dim-(j+4)-1, i+4, dim)) = *(src+RIDX(i+4, j+4, dim));
			*(dst+RIDX(dim-(j+4)-1, i+5, dim)) = *(src+RIDX(i+5, j+4, dim));
			*(dst+RIDX(dim-(j+4)-1, i+6, dim)) = *(src+RIDX(i+6, j+4, dim));
			*(dst+RIDX(dim-(j+4)-1, i+7, dim)) = *(src+RIDX(i+7, j+4, dim));

	    	*(dst+RIDX(dim-(j+5)-1, i+0, dim)) = *(src+RIDX(i+0, j+5, dim));
			*(dst+RIDX(dim-(j+5)-1, i+1, dim)) = *(src+RIDX(i+1, j+5, dim));
			*(dst+RIDX(dim-(j+5)-1, i+2, dim)) = *(src+RIDX(i+2, j+5, dim));
			*(dst+RIDX(dim-(j+5)-1, i+3, dim)) = *(src+RIDX(i+3, j+5, dim));
			*(dst+RIDX(dim-(j+5)-1, i+4, dim)) = *(src+RIDX(i+4, j+5, dim));
			*(dst+RIDX(dim-(j+5)-1, i+5, dim)) = *(src+RIDX(i+5, j+5, dim));
			*(dst+RIDX(dim-(j+5)-1, i+6, dim)) = *(src+RIDX(i+6, j+5, dim));
			*(dst+RIDX(dim-(j+5)-1, i+7, dim)) = *(src+RIDX(i+7, j+5, dim));

	    	*(dst+RIDX(dim-(j+6)-1, i+0, dim)) = *(src+RIDX(i+0, j+6, dim));
			*(dst+RIDX(dim-(j+6)-1, i+1, dim)) = *(src+RIDX(i+1, j+6, dim));
			*(dst+RIDX(dim-(j+6)-1, i+2, dim)) = *(src+RIDX(i+2, j+6, dim));
			*(dst+RIDX(dim-(j+6)-1, i+3, dim)) = *(src+RIDX(i+3, j+6, dim));
			*(dst+RIDX(dim-(j+6)-1, i+4, dim)) = *(src+RIDX(i+4, j+6, dim));
			*(dst+RIDX(dim-(j+6)-1, i+5, dim)) = *(src+RIDX(i+5, j+6, dim));
			*(dst+RIDX(dim-(j+6)-1, i+6, dim)) = *(src+RIDX(i+6, j+6, dim));
			*(dst+RIDX(dim-(j+6)-1, i+7, dim)) = *(src+RIDX(i+7, j+6, dim));

	    	*(dst+RIDX(dim-(j+7)-1, i+0, dim)) = *(src+RIDX(i+0, j+7, dim));
			*(dst+RIDX(dim-(j+7)-1, i+1, dim)) = *(src+RIDX(i+1, j+7, dim));
			*(dst+RIDX(dim-(j+7)-1, i+2, dim)) = *(src+RIDX(i+2, j+7, dim));
			*(dst+RIDX(dim-(j+7)-1, i+3, dim)) = *(src+RIDX(i+3, j+7, dim));
			*(dst+RIDX(dim-(j+7)-1, i+4, dim)) = *(src+RIDX(i+4, j+7, dim));
			*(dst+RIDX(dim-(j+7)-1, i+5, dim)) = *(src+RIDX(i+5, j+7, dim));
			*(dst+RIDX(dim-(j+7)-1, i+6, dim)) = *(src+RIDX(i+6, j+7, dim));
			*(dst+RIDX(dim-(j+7)-1, i+7, dim)) = *(src+RIDX(i+7, j+7, dim));
			
		}
	}*/
}
/*********************************************************************
 * register_rotate_functions - Register all of your different versions
 *     of the rotate kernel with the driver by calling the
 *     add_rotate_function() for each test function. When you run the
 *     driver program, it will test and report the performance of each
 *     registered test function.  
 *********************************************************************/

void register_rotate_functions() 
{
    add_rotate_function(&naive_rotate, naive_rotate_descr);   
    add_rotate_function(&rotate, rotate_descr);   
    /* ... Register additional test functions here */
}


/***************
 * SMOOTH KERNEL
 **************/

/***************************************************************
 * Various typedefs and helper functions for the smooth function
 * You may modify these any way you like.
 **************************************************************/

/* A struct used to compute averaged pixel value */
typedef struct {
    int red;
    int green;
    int blue;
    int num;
} pixel_sum;

/* A struct used to compute averaged pixel value */
typedef struct {
    unsigned red;
    unsigned green;
    unsigned blue;
} pixel_color;

unsigned short divisor = 9;

/* Compute min and max of two integers, respectively */
static int min(int a, int b) { return (a < b ? a : b); }
static int max(int a, int b) { return (a > b ? a : b); }

/* 
 * initialize_pixel_sum - Initializes all fields of sum to 0 
 */
static void initialize_pixel_sum(pixel_sum *sum) 
{
    sum->red = sum->green = sum->blue = 0;
    sum->num = 0;
    return;
}

/* 
 * accumulate_sum - Accumulates field values of p in corresponding 
 * fields of sum 
 */
static void accumulate_sum(pixel_sum *sum, pixel p) 
{
    sum->red += (int) p.red;
    sum->green += (int) p.green;
    sum->blue += (int) p.blue;
    sum->num++;
    return;
}

/* 
 * assign_sum_to_pixel - Computes averaged pixel value in current_pixel 
 */
static void assign_sum_to_pixel(pixel *current_pixel, pixel_sum sum) 
{
    current_pixel->red = (unsigned short) (sum.red/sum.num);
    current_pixel->green = (unsigned short) (sum.green/sum.num);
    current_pixel->blue = (unsigned short) (sum.blue/sum.num);
    return;
}

/* 
 * avg - Returns averaged pixel value at (i,j) 
 */
static pixel avg(int dim, int i, int j, pixel *src) 
{
    int ii, jj;
    pixel_sum sum;
    pixel current_pixel;

    initialize_pixel_sum(&sum);
    for(ii = max(i-1, 0); ii <= min(i+1, dim-1); ii++) 
	for(jj = max(j-1, 0); jj <= min(j+1, dim-1); jj++) 
	    accumulate_sum(&sum, *(src+RIDX(ii, jj, dim)));

    assign_sum_to_pixel(&current_pixel, sum);
    return current_pixel;
}

/******************************************************
 * Your different versions of the smooth kernel go here
 ******************************************************/

/*
 * naive_smooth - The naive baseline version of smooth 
 */
char naive_smooth_descr[] = "naive_smooth: Naive baseline implementation";
void naive_smooth(int dim, pixel *src, pixel *dst) 
{
    int i, j;

    for (i = 0; i < dim; i++)
	{
		for (j = 0; j < dim; j++)
		{
			*(dst+RIDX(i, j, dim)) = avg(dim, i, j, src);
		}
	}
}

static void corner_TL(int position, int dim, pixel *src, pixel *dst)
{
	pixel_color sum;
	pixel average;
	sum.red = sum.green = sum.blue = 0;	

	sum.red += src->red;
	sum.green += src->green;
	sum.blue += src->blue;

	src++;
	sum.red += src->red;
	sum.green += src->green;
	sum.blue += src->blue;

	src += dim;
	sum.red += src->red;
	sum.green += src->green;
	sum.blue += src->blue;

	src--;
	sum.red += src->red;
	sum.green += src->green;
	sum.blue += src->blue;

	average.red = sum.red>>2;
	average.green = sum.green>>2;
	average.blue = sum.blue>>2;

	*dst = average;
}

static void corner_TR(int position, int dim, pixel *src, pixel *dst)
{
	pixel_color sum;
	pixel average;
	sum.red = sum.green = sum.blue = 0;	

	dst += position;
	src += position;

	sum.red += src->red;
	sum.green += src->green;
	sum.blue += src->blue;

	src--;
	sum.red += src->red;
	sum.green += src->green;
	sum.blue += src->blue;

	src += dim;
	sum.red += src->red;
	sum.green += src->green;
	sum.blue += src->blue;

	src++;
	sum.red += src->red;
	sum.green += src->green;
	sum.blue += src->blue;

	average.red = sum.red>>2;
	average.green = sum.green>>2;
	average.blue = sum.blue>>2;

	*dst = average;
}

static void corner_BL(int position, int dim, pixel *src, pixel *dst)
{
	pixel_color sum;
	pixel average;
	sum.red = sum.green = sum.blue = 0;	

	dst += position;
	src += position;

	sum.red += src->red;
	sum.green += src->green;
	sum.blue += src->blue;

	src++;
	sum.red += src->red;
	sum.green += src->green;
	sum.blue += src->blue;

	src -= dim;
	sum.red += src->red;
	sum.green += src->green;
	sum.blue += src->blue;

	src--;
	sum.red += src->red;
	sum.green += src->green;
	sum.blue += src->blue;

	average.red = sum.red>>2;
	average.green = sum.green>>2;
	average.blue = sum.blue>>2;

	*dst = average;
}

static void corner_BR(int position, int dim, pixel *src, pixel *dst)
{
	pixel_color sum;
	pixel average;
	sum.red = sum.green = sum.blue = 0;	

	dst += position;
	src += position;

	sum.red += src->red;
	sum.green += src->green;
	sum.blue += src->blue;

	src--;
	sum.red += src->red;
	sum.green += src->green;
	sum.blue += src->blue;

	src -= dim;
	sum.red += src->red;
	sum.green += src->green;
	sum.blue += src->blue;

	src++;
	sum.red += src->red;
	sum.green += src->green;
	sum.blue += src->blue;

	average.red = sum.red>>2;
	average.green = sum.green>>2;
	average.blue = sum.blue>>2;

	*dst = average;
}

/*
 * smooth - Your current working version of smooth. 
 * IMPORTANT: This is the version you will be graded on
 */
char smooth_descr[] = "smooth: Current working version";
void smooth(int dim, pixel *src, pixel *dst) 
{
	////First do the special cases. 
	//Create useful variables
	unsigned dim_last = dim-1;
	unsigned dim_last_row = dim*dim-dim;
	unsigned dim_last_pixel = dim*dim-1;
    unsigned i, j;
	unsigned common_red;
	unsigned common_green;
	unsigned common_blue;

	//Find all of the corner average values
	//Corner function arguments: (int position(start), dim(size), src, dst)
	corner_TL(0, dim, src, dst);
	corner_TR(dim_last, dim, src, dst);
	corner_BL(dim_last_row, dim, src, dst);
	corner_BR(dim_last_pixel, dim, src, dst);

	pixel average;
	pixel current;

	dst++;
	src++;
	//Top edge
	for (j = 1; j < dim_last; j++)
	{
		common_red = common_green = common_blue = 0;	

		current = *src;
		common_red += current.red;
		common_green += current.green;
		common_blue += current.blue;


		src--;
		current = *src;
		common_red += current.red;
		common_green += current.green;
		common_blue += current.blue;

		src += dim;
		current = *src;
		common_red += current.red;
		common_green += current.green;
		common_blue += current.blue;

		src++;
		current = *src;
		common_red += current.red;
		common_green += current.green;
		common_blue += current.blue;

		src++;
		current = *src;
		common_red += current.red;
		common_green += current.green;
		common_blue += current.blue;

		src -= dim;			
		current = *src;
		common_red += current.red;
		common_green += current.green;
		common_blue += current.blue;

		average.red = common_red/6;
		average.green = common_green/6;
		average.blue = common_blue/6;

		*dst = average;
		dst++;
	}

	dst += dim;
	src += dim;
	//Right edge
	for (j = 1; j < dim_last; j++)
	{
		common_red = common_green = common_blue = 0;	

		current = *src;
		common_red += current.red;
		common_green += current.green;
		common_blue += current.blue;

		src -= dim; 
		current = *src;
		common_red += current.red;
		common_green += current.green;
		common_blue += current.blue;

		src--;
		current = *src;
		common_red += current.red;
		common_green += current.green;
		common_blue += current.blue;

		src += dim;
		current = *src;
		common_red += current.red;
		common_green += current.green;
		common_blue += current.blue;

		src += dim;
		current = *src;
		common_red += current.red;
		common_green += current.green;
		common_blue += current.blue;

		src++;
		current = *src;
		common_red += current.red;
		common_green += current.green;
		common_blue += current.blue;

		average.red = common_red/6;
		average.green = common_green/6;
		average.blue = common_blue/6;

		*dst = average;
		dst += dim;
	}

	dst--;
	src--;
	//Bottom edge
	for (j = 1; j < dim_last; j++)
	{
		common_red = common_green = common_blue = 0;	

		current = *src;
		common_red += current.red;
		common_green += current.green;
		common_blue += current.blue;

		src++;
		current = *src;
		common_red += current.red;
		common_green += current.green;
		common_blue += current.blue;

		src -= dim;
		current = *src;
		common_red += current.red;
		common_green += current.green;
		common_blue += current.blue;

		src--;
		current = *src;
		common_red += current.red;
		common_green += current.green;
		common_blue += current.blue;

		src--;
		current = *src;
		common_red += current.red;
		common_green += current.green;
		common_blue += current.blue;

		src += dim;
		current = *src;
		common_red += current.red;
		common_green += current.green;
		common_blue += current.blue;

		average.red = common_red/6;
		average.green = common_green/6;
		average.blue = common_blue/6;

		*dst = average;
		dst--;
	}

	dst -= dim;
	src -= dim;
	//Left edge
	for (j = 1; j < dim_last; j++)
	{
		common_red = common_green = common_blue = 0;	

		current = *src;
		common_red += current.red;
		common_green += current.green;
		common_blue += current.blue;

		src += dim;
		current = *src;
		common_red += current.red;
		common_green += current.green;
		common_blue += current.blue;

		src++;
		current = *src;
		common_red += current.red;
		common_green += current.green;
		common_blue += current.blue;

		src -= dim;
		current = *src;
		common_red += current.red;
		common_green += current.green;
		common_blue += current.blue;

		src -= dim;
		current = *src;
		common_red += current.red;
		common_green += current.green;
		common_blue += current.blue;

		src--;
		current = *src;
		common_red += current.red;
		common_green += current.green;
		common_blue += current.blue;

		average.red = common_red/6;
		average.green = common_green/6;
		average.blue = common_blue/6;

		*dst = average;
		dst -= dim;
	}

	//Complete the rest of the averages.
	//Start by incrementing the src and dst
	dst += dim+1;
	src += dim+1;

	unsigned decrementer = dim + dim - 3;
	unsigned dim_plus_2 = dim + 2;

	pixel_color sum_TL;
	pixel_color sum_TR;
	pixel_color sum_BL;
	pixel_color sum_BR;
	pixel_color common_sum;
	pixel average_TL;
	pixel average_TR;
	pixel average_BL;
	pixel average_BR;

	for (i = 1; i < dim_last; i+=2)
	{
		for (j = 1; j < dim_last; j+=2)
		{
			sum_TL.red = sum_TL.green = sum_TL.blue = 0;
			sum_TR.red = sum_TR.green = sum_TR.blue = 0;
			sum_BL.red = sum_BL.green = sum_BL.blue = 0;
			sum_BR.red = sum_BR.green = sum_BR.blue = 0;

			//Position 1
			current = *src;
			common_sum.red = current.red;
			common_sum.green = current.green;
			common_sum.blue = current.blue;

			src++;
			//Position 2
			current = *src;
			common_sum.red += current.red;
			common_sum.green += current.green;
			common_sum.blue += current.blue;

			src += dim;
			//Position 3
			current = *src;
			common_sum.red += current.red;
			common_sum.green += current.green;
			common_sum.blue += current.blue;

			src--;
			//Position 4
			current = *src;
			common_sum.red += current.red;
			common_sum.green += current.green;
			common_sum.blue += current.blue;

			//Assign common to others
			sum_TL = sum_TR = sum_BL = sum_BR = common_sum;

			src--;
			//Position 5
			current = *src;
			common_red = current.red;
			common_green = current.green;
			common_blue = current.blue;

			src -= dim;
			//Position 6
			current = *src;
			common_red += current.red;
			common_green += current.green;
			common_blue += current.blue;

			//Ad to the TL, and BL
			sum_TL.red += common_red;
			sum_TL.green += common_green;
			sum_TL.blue += common_blue;
			sum_BL.red += common_red;
			sum_BL.green += common_green;
			sum_BL.blue += common_blue;			

			src -= dim;
			//Position 7
			current = *src;
			sum_TL.red += current.red;
			sum_TL.green += current.green;
			sum_TL.blue += current.blue;

			src++;
			//Position 8
			current = *src;
			common_red = current.red;
			common_green = current.green;
			common_blue = current.blue;

			src++;
			//Position 9
			current = *src;
			common_red += current.red;
			common_green += current.green;
			common_blue += current.blue;

			//Ad to the TL, and BL
			sum_TL.red += common_red;
			sum_TL.green += common_green;
			sum_TL.blue += common_blue;
			sum_TR.red += common_red;
			sum_TR.green += common_green;
			sum_TR.blue += common_blue;	

			src++;
			//Position 10
			current = *src;
			sum_TR.red += current.red;
			sum_TR.green += current.green;
			sum_TR.blue += current.blue;

			src += dim;
			//Position 11
			current = *src;
			common_red = current.red;
			common_green = current.green;
			common_blue = current.blue;

			src += dim;
			//Position 12
			current = *src;
			common_red += current.red;
			common_green += current.green;
			common_blue += current.blue;

			//Ad to the TL, and BL
			sum_TR.red += common_red;
			sum_TR.green += common_green;
			sum_TR.blue += common_blue;
			sum_BR.red += common_red;
			sum_BR.green += common_green;
			sum_BR.blue += common_blue;	

			src += dim;
			//Position 13
			current = *src;
			sum_BR.red += current.red;
			sum_BR.green += current.green;
			sum_BR.blue += current.blue;

			src--;
			//Position 14
			current = *src;
			common_red = current.red;
			common_green = current.green;
			common_blue = current.blue;

			src--;
			//Position 15
			current = *src;
			common_red += current.red;
			common_green += current.green;
			common_blue += current.blue;

			//Ad to the TL, and BL
			sum_BL.red += common_red;
			sum_BL.green += common_green;
			sum_BL.blue += common_blue;
			sum_BR.red += common_red;
			sum_BR.green += common_green;
			sum_BR.blue += common_blue;	

			src--;
			//Position 16
			current = *src;
			sum_BL.red += current.red;
			sum_BL.green += current.green;
			sum_BL.blue += current.blue;

			//Find averages
			average_TL.red = sum_TL.red/9;
			average_TL.green = sum_TL.green/9;
			average_TL.blue = sum_TL.blue/9;

			average_TR.red = sum_TR.red/9;
			average_TR.green = sum_TR.green/9;
			average_TR.blue = sum_TR.blue/9;

			average_BL.red = sum_BL.red/9;
			average_BL.green = sum_BL.green/9;
			average_BL.blue = sum_BL.blue/9;

			average_BR.red = sum_BR.red/9;
			average_BR.green = sum_BR.green/9;
			average_BR.blue = sum_BR.blue/9;

			*dst = average_TL;
			dst += dim;
			*dst = average_BL;
			dst++;
			*dst = average_BR;
			dst -= dim;
			*dst = average_TR;

			//Increment the src and dest to the next location on next column
			src -= decrementer;
			dst++;
		}
		//Increment the src and dest to the next location in next row
		src += dim_plus_2;
		dst += dim_plus_2;
	}	
}


/********************************************************************* 
 * register_smooth_functions - Register all of your different versions
 *     of the smooth kernel with the driver by calling the
 *     add_smooth_function() for each test function.  When you run the
 *     driver program, it will test and report the performance of each
 *     registered test function.  
 *********************************************************************/

void register_smooth_functions() {
    add_smooth_function(&smooth, smooth_descr);
    add_smooth_function(&naive_smooth, naive_smooth_descr);
    /* ... Register additional test functions here */
}

