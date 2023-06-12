/*
 * wav.c - WAV codec library for matrix. Can also be used as a standalone.
 */

/*
 * Copyright (c) 2023 Ariston Lorenzo.  All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 
 * 1.  Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 * 2.  Redistributions in binary form must reproduce the above copyright
 *     notice, this list of conditions and the following disclaimer in the
 *     documentation and/or other materials provided with the distribution.
 * 3.  Neither the name of Ariston Lorenzo nor the names of its contributors
 *     may be used to endorse or promote products derived from this software
 *     without specific prior written permission.
 * 
 * THIS SOFTWARE IS PROVIDED BY ARISTON LORENZO AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL ARISTON LORENZO OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE
 */

#ifndef lint
static char copyright[] =
"@(#) Copyright (c) 2023\n\
 	Ariston Lorenzo.  All rights reserved\n";
#endif /* not lint */

#include <stdio.h>
#include <stdlib.h>

#include "wav.h"

/*
 * wav_verify_header(char file);
 * Purpose: Verifies WAV file
 *
 * Return:
 * 	-1 - Error
 *	0 - Is WAV File
 *	1 - Not a WAV file
 */
int
wav_verify_header(file)
	char file;
{
	struct wav_header *header;
	FILE *fp;

	fp = fopen(file, "r");
	if (fp == NULL) {
		printf("Error opening file\n");
		
		return -1; /* File cannot be opened */
	}

	header = malloc(sizeof(struct wav_header));
	if (header == NULL) {
		printf("Error allocating memory\n");
		return -1; /* Cannot allocate memory */
	}

	fread(header, sizeof(struct wav_header), 1, fp);
	
	if (header->riff_header != RIFF_SIGNATURE) {
		return 1; /* Not a WAV file */
		printf("riff_header: Not a WAV file\n");
	}

	if (header->wav_header != WAVE_SIGNATURE) {
		return 1; /* Not a WAV file */
		printf("wav_header: Not a WAV file\n");
	}

	if (header->fmt_header != FMT_SIGNATURE) {
		return 1; /* Not a WAV file */
		printf("fmt_header: Not a WAV file\n");
	}

	fclose(fp);

	return 0; /* Is a WAV file */
}
