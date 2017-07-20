/***************************************************************************************
 * Name: Ya Lien
 * Class: CS362 	Quiz 2: Random Testing
 * Due Date: 7/30/2017
 * Description: Implement a random tester for the function testme() in testme.c that 
 * is capable of printing the error message.  You should implement inputChar() and 
 * inputString() to produce random values.
 * *************************************************************************************/ 
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

char inputChar()
{
   	 //test with ascii codes ranging from 'a' to '}'
   	 //excluding all control codes
	int testRange = 126 - 32;
	char ch = rand() % testRange + 32;
    	return ch;
}

char *inputString()
{
	//test with random string of length 6
	int size = 6;
	int i;
	int testRange = 123 - 97;
	char cArray[size];
	//the random charactors range from 'a' to 'z'(range from 97 to 122)
	//what about the null terminator?
	for(i = 0; i < size - 1; i++)
	{
		cArray[i] = rand() % testRange + 97;
	}
	cArray[5] = '\0';

    return cArray;
}

void testme()
{
  int tcCount = 0;
  char *s;
  char c;
  int state = 0;
  while (1)
  {
    tcCount++;
    c = inputChar();
    s = inputString();
    printf("Iteration %d: c = %c, s = %s, state = %d\n", tcCount, c, s, state);

    if (c == '[' && state == 0) state = 1;
    if (c == '(' && state == 1) state = 2;
    if (c == '{' && state == 2) state = 3;
    if (c == ' '&& state == 3) state = 4;
    if (c == 'a' && state == 4) state = 5;
    if (c == 'x' && state == 5) state = 6;
    if (c == '}' && state == 6) state = 7;
    if (c == ')' && state == 7) state = 8;
    if (c == ']' && state == 8) state = 9;
    if (s[0] == 'r' && s[1] == 'e'
       && s[2] == 's' && s[3] == 'e'
       && s[4] == 't' && s[5] == '\0'
       && state == 9)
    {
      printf("error ");
      exit(200);
    }
  }
}


int main(int argc, char *argv[])
{
    srand(time(NULL));
    testme();
    return 0;
}
