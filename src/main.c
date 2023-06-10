#include <stdio.h>
#include <unistd.h>

void
usage(void)
{
	printf("Usage: matrix [-hv]\n");
}

int
main(argc, argv)
	int argc;
	char *argv[];
{
	int ch;

	if (argc < 2) {
		usage();
		return 1;
	}

	while ((ch = getopt(argc, argv, "hv")) != -1) {
		switch (ch) {
		case 'h':
			usage();
			break;
		case 'v':
			printf("matrix version v0.1\n");
			break;
		case '?':
		default:
			usage();
			return 1;
		}
	}
	
	return 0;
}
