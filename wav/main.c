#include <stdio.h>
#include <unistd.h>

#include "lib/wav.h"

void
usage(void)
{
	printf("Usage: wav [-hv]\n");
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

	printf("File: %s\n", argv[1]);

	/* Pass file name to wav_verify_header() */
	if (wav_verify_header(argv[1]) == 0) {
		printf("Is a WAV file\n");
	} else if (wav_verify_header(argv[1]) == -1) {
		printf("Error verifying WAV header.\n");
	} else if (wav_verify_header(argv[1]) == 1) {
		printf("Not a WAV file\n");
	}

	return 0;
}
