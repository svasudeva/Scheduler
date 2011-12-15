/*********************************************************/
/*	Program for a cpubound process which  does the   */
/*      matrix multiplication                            */
/********************************************************/
#include<stdio.h>
#include<time.h>
#include<sys/times.h>

main()
{int rowsize = 1000;
int  colsize = 1000;
int colrowsize = 1000;
int row,col,colrow,mat1[rowsize][colrowsize],mat2[colrowsize][colsize],result[rowsize][colsize];
int sum;
time_t start,end;
double exectime;
struct tms cputime;
double stime,utime;


start = time(NULL);

	for(row=0;row<rowsize;row++)
	   {
		for(colrow=0;colrow<colrowsize;colrow++)
		{
			mat1[row][colrow] = 1;
		}
	   }

	for(colrow=0;colrow<colrowsize;colrow++)
	   {
		for(col=0;col<colsize;col++)
		{
			mat2[colrow][col] = 1;
		}
	   }



	for (row=0;row<rowsize;row++)
	{
		for (col=0;col<colsize;col++)
		{ sum = 0;
			for(colrow=0;colrow<colrowsize;colrow++)
			{
			sum = sum + (mat1[row][colrow] * mat2[colrow][col]);
			result[row][col] = sum;
			
			}
		}
	}

/*	for(row=0;row<rowsize;row++)
	{      
		for(col=0;col<colsize;col++)
		{
			printf("%d",result[row][col]);
			printf("\t");
		}
			printf("\n");
	}
*/	
end = time(NULL);
times(&cputime);

exectime = difftime(end,start);
utime = (double)(((double)cputime.tms_utime)/(double)CLOCKS_PER_SEC);
stime = (double)(((double)cputime.tms_stime)/(double)CLOCKS_PER_SEC);

printf("cpu bound process,%.3f,%.3f,%.3f\n",exectime,utime,stime);
return(0);
}
