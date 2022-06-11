This is a shared library with some functions for manipulating strings.

the library contains the folowing functions:

wrdcnt - counts the words in a string separated by a delimiter

before_delim - counts all the letters that appear before a delimiter in a string

strsplt - splits a string by delimiters into a new array of strings separated by a new delimiter

strings_count - counts the number of strings in an array of strings and total number of letters in the array

f_line_count - counts the number of lines in a file

f_letter_count - counts the number of letters on each line in a file

to install library, run the command:
**make install**

*note: this requires root access to install library in /usr/local folder

to use library, include the following header in source code:
**#include <libstring_functions.h>**

to compile a program using this library, use:
**gcc -Wall -pedantic -Werror -Wextra -std=gnu89 -L/usr/local/lib -lstring_functions**
