// can check for writing error by checking the return valid of putc

// changed while loop:
while ((ch = getc(source_fp)) != EOF) {
    if (putc(ch, dest_fp) == EOF) {
        fprintf(stderr, "Failed to write data to %s\n", argv[2]);
        exit(EXIT_FAILURE);
    }
}