#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<sys/times.h>

main()
{
FILE *fo;
FILE *fw;
int i,ch;
double exectime;
time_t start,end;
struct tms cputime;
double utime,stime;

start = time(NULL);

fo = fopen("cpubound.c","r");
fw = fopen("new.txt","wa");

if (fo == NULL)
{
	printf("%s","Cannot open file for reading");
	exit(1);
}

if (fw == NULL)
{
	printf("%s","Cannot open file for writing");
	fclose(fo);
	exit(1);

}

for(i=0;i<100000;i++)
{
	fseek(fo,0,SEEK_SET);

while( (ch=fgetc(fo)) != EOF)
{
	fputc(ch,fw);
}

}

fclose(fo);
fclose(fw);

end = time(NULL);
times(&cputime);

exectime = difftime(end,start);
utime = (double)(((double)cputime.tms_utime)/(double)CLOCKS_PER_SEC);
stime =(double)(((double)cputime.tms_stime)/(double)CLOCKS_PER_SEC);

printf("iobound.c,%.3f,%.3f,%.3f\n",exectime,utime,stime);

return(0);
}
