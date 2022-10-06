# Speller
This is a spell-checking application built in C, which is an implementation of [Problem Set 5](https://cs50.harvard.edu/college/2019/fall/weeks/5/) from the Fall 2019 version 
of CS50's Introduction to Computer Programming course, and it recieved a passing grade. 
ASIDE: *The only part of the code that I personally wrote is in `dictonary.c`, the rest was provided by CS50.*

# How to run this application
### Linux
1. Fork or download the files 
2. Navigate to the root directory 
3. Compile with the provided MakeFile (run `Make`)
4. Run `./speller [dictonary] path/to/text`
### Windows
Unfortunately, this application was built with Linux in mind and has Linux dependancies, using [WSL](https://docs.microsoft.com/en-us/windows/wsl/install) is
the simpliest way to compile and run this program without manual refactorings.

# Examples
Our sample file contains the following text:  
`I nevr rlly lerned how to spell very well, this spell-checking app rlly doesn't think im vry gud.`  
Input : `./speller example.txt`  
```console
MISSPELLED WORDS

nevr
rlly
lerned
app
rlly
vry
gud

WORDS MISSPELLED:     7
WORDS IN DICTIONARY:  143091
WORDS IN TEXT:        19
TIME IN load:         0.05
TIME IN check:        0.00
TIME IN size:         0.00
TIME IN unload:       0.01
TIME IN TOTAL:        0.06
```
Input : `./speller texts/cat.txt`  
```console
MISSPELLED WORDS


WORDS MISSPELLED:     0
WORDS IN DICTIONARY:  143091
WORDS IN TEXT:        6
TIME IN load:         0.05
TIME IN check:        0.00
TIME IN size:         0.00
TIME IN unload:       0.01
TIME IN TOTAL:        0.06
```
# Dependencies
- sys/resource.h
- sys/time.h
