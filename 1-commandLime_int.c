/**
 * checkInteractiveMode - returns true if shell is in interactive mode
 * @infoData: struct address
 *
 * Return: 1 if interactive mode, 0 otherwise
 */
int checkInteractiveMode(info_t *infoData)
{
	return (isatty(STDIN_FILENO) && infoData->readFileDesc <= 2);
}

/**
 * checkDelimiter - checks if character is a delimiter
 * @character: the char to check
 * @delimiter: the delimiter string
 * Return: 1 if true, 0 if false
 */
int checkDelimiter(char character, char *delimiter)
{
	while (*delimiter)
		if (*delimiter++ == character)
			return (1);
	return (0);
}

/**
 * checkAlphabetic - checks for alphabetic character
 * @character: The character to input
 * Return: 1 if character is alphabetic, 0 otherwise
 */

int checkAlphabetic(int character)
{
	if ((character >= 'a' && character <= 'z') || (character >= 'A' && character <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 * convertToInteger - converts a string to an integer
 * @str: the string to be converted
 * Return: 0 if no numbers in string, converted number otherwise
 */

int convertToInteger(char *str)
{
	int index, sign = 1, flag = 0, result;
	unsigned int convertedValue = 0;

	for (index = 0; str[index] != '\0' && flag != 2; index++)
	{
		if (str[index] == '-')
			sign *= -1;

		if (str[index] >= '0' && str[index] <= '9')
		{
			flag = 1;
			convertedValue *= 10;
			convertedValue += (str[index] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}

	if (sign == -1)
		result = -convertedValue;
	else
		result = convertedValue;

	return (result);
}
