#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])
//int main()
{
	char q[1024], line[1024], ch;

	extern FILE *popen();
	FILE *fp1, *fp2, *fp3;

	time_t now;
	now = time(0);
	struct tm* y;
	y = localtime(&now);
	
	int mon = y->tm_mon+1, mday = y->tm_mday;
	sprintf(q, " %2d  %2d   * root", mday, mon);

	fp1 = fopen("/home/happyhour/VM/crontab/list1", "r");
	fp2 = fopen("/home/happyhour/VM/crontab/list2", "w");

	while(!feof(fp1))
	{
		fgets(line, 1024, fp1);
		if(feof(fp1)) break;
		if(strstr(line, q) == NULL)
			fprintf(fp2, "%s", line);
	}		

	fclose(fp1);
	fclose(fp2);

	fp1 = fopen("/home/happyhour/VM/crontab/crontab", "r");
	fp2 = fopen("/home/happyhour/VM/crontab/list2", "r");
	fp3 = fopen("/home/happyhour/VM/crontab/list3", "w");

	while((ch=getc(fp1)) != EOF)
		fprintf(fp3, "%c", ch);

	while((ch=getc(fp2)) != EOF)
		fprintf(fp3, "%c", ch);

	fclose(fp1);
	fclose(fp2);
	fclose(fp3);

	popen("cp /home/happyhour/VM/crontab/list2 /home/happyhour/VM/crontab/list1", "r");
	popen("cp /home/happyhour/VM/crontab/list3 /etc/crontab", "r");

	return 0;
}
