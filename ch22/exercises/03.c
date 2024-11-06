// if fopen fails and returns NULL, fclose should not be called
// you can move fclose inside of the if block

FILE *fp;
if (fp = fopen(filename, "r")) {
    read characters until end-of-file
    fclose(fp);
} 
