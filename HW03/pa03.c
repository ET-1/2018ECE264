#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include "pa03.h"
#define RANGE 10000

void cleanup(FILE * fpin, FILE * fpout)
{
	fclose (fpin);
	fclose (fpout);
}

// allocate a two dimensional array of
double * * allocateMemory(int nrow, int ncol)
{
	double * * data = NULL;
	int i;
	data = malloc(sizeof(double *)*nrow);//allocate memory for nrow first
	for (i = 0; i < nrow; i ++)
	{
	  data[i] = malloc(sizeof(double)*ncol);//allocate ncol memeory for each row 
	}
	
	//TODO: allocate memory for the data and then return the data
	//It is this functions reponsibility to ensure that memory is allocated
	return data;
}

void releaseMemory(double * * data, int nrow)
{
	int i;
	for(i = 0; i < nrow; i ++)
	{
	  free(data[i]);//free memory for each row
	}//TODO: complete this function to release the memory of the data
	free(data);//free the pointer 
	//not completing this function will lead to memory not getting free
}


//double * * recomputeCenter(int kval, int nval, int dim, double * * data, double * * centroid, int * cluster)
//{

//}
// read the data, return true if success, false if fail
bool readData(FILE * fpin, double * * data, int nval, int dim)
{
	int niter, diter;
	for (niter = 0; niter < nval; niter ++)
	{
		for (diter = 0; diter < dim; diter ++)
		{
			if (fscanf(fpin, "%lf", & data[niter][diter]) == 0)
			{
				return false;
			}
		}
	}
	return true;
}

// write the output centroids to the file
// check for all the NULL before calling this function, it does not check
void writeCentroids(FILE * fpout, double * * centroid, int kval, int dim){
  int kiter,diter;
  for (kiter = 0; kiter < kval; kiter ++)
  {
    for (diter = 0; diter < dim; diter ++)
    {
      //write to the file
      fprintf(fpout, "%lf ", centroid[kiter][diter]);
    }
    fprintf(fpout, "\n");
  }
}

//initilize function is to initilize the values for centroid
void initialize(double * * centroid, int kval, int dim)
{
	int kiter, diter;
	for (kiter = 0; kiter < kval; kiter ++)
	{
		for (diter = 0; diter < dim; diter ++)
		{
			int randval = - RANGE + (rand() % (2 * RANGE));
			centroid[kiter][diter] = randval;
	         	#ifdef debug4
	  		printf("initial centroid[%d][%d]: %lf\n", kiter, diter, centroid[kiter][diter]);
	  		#endif
		}
	}
}



int main(int argc, char * * argv)
{
	// argv[1]: name of input file
	// argv[2]: value of k
	// argv[3]: name of output file
	// argv[4]: (optional) seed for random numbers, use time if absent

	if (argc < 4)
	{
		fprintf(stderr, "argc is %d, not 4\n", argc);
		return EXIT_FAILURE;
	}
	FILE * fpin = fopen(argv[1], "r");
	if (fpin == NULL)
	{
		fprintf(stderr, "fopen %s fail\n", argv[1]);
		return EXIT_FAILURE;
	}
	int kval = (int) strtol(argv[2], NULL, 10);
	// convert long to in
	if (kval <= 0)
	{
		fprintf(stderr, "kval is %d, must be positive\n", kval);
		return EXIT_FAILURE;
	}
	FILE * fpout = fopen(argv[3], "w");
	if (fpout == NULL)
	{
		fclose (fpin);
		// was open successfully and needs to be closed
		fprintf(stderr, "fopen %s fail\n", argv[3]);
		return EXIT_FAILURE;
	}

	if (argc == 5)
	{
		int randseed = (int) strtol(argv[4], NULL, 10);
		if (randseed == -1)
		{
			srand(time(NULL));
		}
		else
		{
			srand(randseed);
		}
	}

	int nval;
	fscanf(fpin, "%d", & nval);
	if (nval < kval)
	{
		fprintf(stderr, "nval= %d must be greater than kval = %d\n",
				nval, kval);
		cleanup(fpin, fpout);
		return EXIT_FAILURE;
	}
	int dim;
	fscanf(fpin, "%d", & dim);
	if (dim < 2)
	{
		fprintf(stderr, "nval= %d must be greater than kval = %d\n",
				nval, kval);
		cleanup(fpin, fpout);
		return EXIT_FAILURE;

	}

	// allocate memory for the data points
	double * * datapoint = allocateMemory(nval, dim);
	if (datapoint == NULL)
	{
		cleanup(fpin, fpout);
		return EXIT_FAILURE;
	}
	// allocate memory for the centroid
	double * * centroid = allocateMemory(kval, dim);
	if (centroid == NULL)
	{
		cleanup(fpin, fpout);
		return EXIT_FAILURE;
	}

	// read the data from the file
	if (readData(fpin, datapoint, nval, dim) == false)
	{
		cleanup(fpin, fpout);
		return EXIT_FAILURE;
	}

	// initialize centroids within [-RANGE, RANGE] of every dimension
	initialize(centroid, kval, dim);

  //allocate memory for cluster
  int * cluster;
  cluster = malloc(sizeof(*cluster)*nval);
  if(cluster == NULL)
  {
		cleanup(fpin, fpout);
		return EXIT_FAILURE;
	}
  // initilize cluster values
  for(int niter = 0; niter < nval; niter++)
  {
    cluster[niter] = -1;
  }

  //now we will run our kmean algorithm
  kmean(kval, nval, dim, datapoint, centroid, cluster);


  //print all the centroids into a file
  writeCentroids(fpout, centroid, kval, dim);

  //free all the allocated spaces
  releaseMemory(datapoint, nval);
  releaseMemory(centroid, kval);
  free(cluster);
  //close all the files
  cleanup(fpin, fpout);
	return EXIT_SUCCESS;
}


// The k-mean method to cluster data
// kval: the number of clusters
// nval: the number of data pointers
// dim: dimension of the data
// data: two-dimensional array of the data, nval rows, dim columns
// centroid: two-dimensional array of the data, kval rows, dim columns
// cluster: one-dimensional array of n elements, the assignments of
// data to the clusters. cluster[i] = j means the i-th data pointer is
// assigned to the j-th cluster. 0 <= i < nval; 0 <= j < kval

void kmean(int kval, int nval, int dim, double * * data, double * * centroid,
		int * cluster)
{
  int index = 0;//TODO: complete this function
  int qiter;
  int niter;
  int kiter;
  int group = 0;
  double sum = 0;
  int col;
  int count = 0;
  int repeat = 1;
  
  while(repeat != 0)
  {
    repeat = 0;

	for(qiter = 0; qiter < nval; qiter ++)
	{
	  index = closestCentroid(kval, dim, data[qiter], centroid);
	  if(index != cluster[qiter])
	  {
	    repeat = repeat + 1;
	  }
	  else
	  {
	    repeat = repeat + 0;
	  }
	  cluster[qiter] = index;//assign each pointer to its group
	  #ifdef debug1
	  printf("cluster[%d] = %d\n", qiter, index);
	  
	  #endif
	  
	}//store the assignment of group
        #ifdef debug5
	printf("Total repeat is: %d \n", repeat);
	#endif
	
	for(col = 0; col < dim; col ++)
	{
	  #ifdef debug3
	  printf("\nThis is dimension %d\n", col);
	  #endif
	  for(kiter = 0; kiter < kval; kiter ++)
	  { 
	    count = 0;//reset count for each group
	    sum = 0;//reset column sum for each group
	    for(niter = 0; niter < nval; niter ++)
	    {
	      group = cluster[niter];//read the group number for each pointer
	      if(group == kiter)//group number should be less than k
	      {
	        count = count + 1;
	        sum = sum + data[niter][col];	        
	      }	      
	    }
	    	    
	    if(count == 0)
	    {
	      centroid[kiter][col] = 0;
	    }
	    else
	    {
	      centroid[kiter][col] = sum / count;
	    }
	    #ifdef debug2
	    
	    printf("centroid[%d][%d] = %lf\n", kiter, col, centroid[kiter][col]);
	    
	    #endif
	  }
	}
//		printf("Total repeat is: %d \n", repeat);
  }	


	
}
	
	
	/*This assignment uses the *k-mean clustering* algorithm. This algorithm works in the following way:
	  1. Read the data and the given value k
	  2. Pick k points (called *centroids*) randomly as the initial centers
	  of the k group
	  3. For each data point, find the closet centroid. Assign this data point to the group represented by this centroid.
	  4. For each group, recompute the location of the centroid as the center of all data points belonging to this group.
	  5. Repeat steps 3 and 4 until the convergence condition is met.
	*/

	
