//a
fseek(fp, 64L * n, SEEK_SET);

//b
fseek(fp, -64L, SEEK_END);

//c
fseek(fp, 64L, SEEK_CUR);

//d
fseek(fp, -128L, SEEK_CUR);