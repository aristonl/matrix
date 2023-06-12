#ifndef LIBWAV_WAV_H
#define LIBWAV_WAV_H

#define RIFF_SIGNATURE 0x46464952 /* "RIFF" */
#define WAVE_SIGNATURE 0x45564157 /* "WAVE" */
#define FMT_SIGNATURE 0x20746D66 /* "fmt " */
#define DATA_SIGNATURE 0x61746164 /* "data" */

struct wav_header {
	char riff_header[4];
	unsigned int file_size;
	char wav_header[4];
	char fmt_header[4];
	unsigned int wav_chunk_size;
	unsigned short wav_format;
	unsigned short mono_stereo;
	unsigned int sample_freq;
	unsigned int data_rate;
	unsigned short block_alignment;
	unsigned short bits_per_sample;
};

struct wav_data {
	char data_header[4];
	unsigned int data_size;
};

struct wav {
	struct wav_header *header;
	struct wav_data *data;
};

int wav_verify_header(char file);

#endif /* LIBWAV_WAV_H */