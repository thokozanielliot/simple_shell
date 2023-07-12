# Simple Shell

## Description
Writing a simple UNIX command interpreter. This command interoreter will be able to do execute simple shell commands. This project was done by [Thokozani Mupundu](https://github.com/thokozanielliot) & [Mnqobi Donga](https://github.com/keveneleven).


This project was done in a linux environment Ubuntu. All files are compiled on linx environment using `gcc`, using the options `-Wall -Werror -Wextra -pedantic -std=gnu89`.

## Compilation
For compilation using the following to compile your code:
`gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh`

## Testing
For testing out your compiled code use:
`./hsh`

## Tassks

| Tasks | Description                                                                                                                            |
|-------|----------------------------------------------------------------------------------------------------------------------------------------|
| 0     | Wrting a code that passe the Betty checks.                                                                                             |
| 1     | Wrting a UNIX command line interpreter, that displays a aprompt & wait for user to type a command. A command always ends with aline.   |
|       | Handle errors & have to handle the "end of file" condition `Ctrl+D`.                                                                   |
| 2     | Simple shell 0.1, that handles command lnes with arguements.                                                                           |
| 3     | Simple shell 0.2, that handle `PATH` & `fork` must not be called if the command doesn't exist.                                         |
| 4     | Simple shell 0.3, with `exit` built-in, that exits the shell & don't have to handle any arguement to the built-in `exit`.              |
| 5     | Simple shell 0.4, with implemented `env` built-in that prints the curent environment.                                                  |

