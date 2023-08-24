/**
 * main - Entry point of the program
 * Description:prints the alphabet in lowercase using 'putchar' function
 * except "q" and "e"
 * Return: 0 (Success)
 */

int main(void)
{
        char alph_lower;

        for (alph_lower = 'a' ; alph_lower <= 'z' ; alph_lower++)
        if (alph_lower != 'q' && alph_lower != 'e')
        putchar(alph_lower);
        putchar('\n');
        return (0);
}
