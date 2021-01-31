#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/mman.h>

#include "verilog_parser.h"
#include "verilog_ast_common.h"
#include "verilog_preprocessor.h"
#include "verilog_ast_util.h"

void cm_read_verilog_file(char* filepath)
{
	// Get filehandle from filepath.
	FILE* fp;
	char* line = NULL;
	size_t len = 0;
	ssize_t read;

	// Open verilog file.
	fp = fopen(filepath, "rb");

	if (fp == NULL)
        exit(EXIT_FAILURE);

	// Initialize the verilog parser.
	verilog_parser_init();

	int result = verilog_parse_file(fp);

	if(result == 0)
		printf("Parse successful\n");
	else
		printf("Parse failed\n");


	fclose(fp);
}
