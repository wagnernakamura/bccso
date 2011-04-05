#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

main(int argc, char* argv)
{
  int pid1 = 1, pid2 = 1;
  
  if((pid1 = fork()) != 0)
  {
   pid2 = fork(); 
  }
   
  if(pid1 == 0)
  {
    FILE* fo = fopen("pi1.txt", "w");
    
    int n = 11000;
    double x, y;
    int i, count = 0;
    double z;
    float pi;

    srand(time(NULL));
    count = 0;
    for ( i=0; i<n; i++) 
    {
      x = (double)rand()/RAND_MAX;
      y = (double)rand()/RAND_MAX;
      
      z = x*x+y*y;
      
      if (z<=1) 
	count++;
    }
    
    pi = ((float)count / (float)n * 2);
    
    fprintf(fo, "%f", pi);
    fclose(fo);
    
	sleep(30);
    return 0;
  }
  
  if(pid2 == 0)
  {
    FILE* fo = fopen("pi2.txt", "w");
    
    int n = 100000;
    double x, y;
    int i, count = 0;
    double z;
    float pi;

    srand(time(NULL) * 3);
    count = 0;
    for ( i=0; i<n; i++) 
    {
      x = (double)rand()/RAND_MAX;
      y = (double)rand()/RAND_MAX;
      
      z = x*x+y*y;
      
      if (z<=1) 
	count++;
    }
    
    pi = ((float)count / (float)n * 2);
    
    fprintf(fo, "%f", pi);
    fclose(fo);
    
	sleep(30);
    return 0;
  }
  
  if(pid1 != 0 && pid2 != 0)
  {
    wait();
    wait();
    
    float pi1, pi2;
    
    FILE* fo = fopen("pi1.txt", "r");
    fscanf(fo, "%f", &pi1);
    fclose(fo);
    
    fo = fopen("pi2.txt", "r");
    fscanf(fo, "%f", &pi2);
    fclose(fo);
    
sleep(30);
    printf("pi eh: %f \n", (pi1 + pi2));
  }

	sleep(30);
}













