#include <stdio.h>

int main(int argc, char *argv[])
{
char buf[128];
FILE *pp;

pp = popen("virsh vncdisplay test_vm08", "r");

fgets(buf, sizeof buf, pp);
printf("%s", buf);
pclose(pp);
return 0;
}
