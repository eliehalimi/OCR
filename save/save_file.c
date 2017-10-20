// save_file.c


# include "save_file.h"


//SEE DECLARATION IN HEADER
void open_file(char *path, char *type)
{
	if (*type == "w" || *type == "r")
	{
		FILE *f = fopen(*path, "w");
       	 	if (f == NULL)
        	{
        	printf("Error opening file!\n");
        	exit(1);
        	}
		return *f;
	}
	printf("Error opening file! open with r or w parameter\n")
	exit(1);
}



//SEE DECLARATION IN HEADER
void write_to_file(FILE *f)
{

	/* print some text */
	const char *text = "Write this to the file";
	fprintf(f, "Some text: %s\n", text);

	/* print integers and floats */
	int i = 1;
	float py = 3.1415927;
	fprintf(f, "Integer: %d, float: %f\n", i, py);

	/* printing single chatacters */
	char c = 'A';
	fprintf(f, "A character: %c\n", c);

	fclose(f);
}

//SEE DECLERATION IN HEADER
void read_file(FILE *f)
{
	while ((c = getc(file)) != EOF)
        	putchar(c);
}
