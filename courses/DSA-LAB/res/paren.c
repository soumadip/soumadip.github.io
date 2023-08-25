#include <stdio.h>
#include <string.h>

int isBalanced(const char *s, int idx, int count);
int isOpenParenthesis(const char *s, int idx, int count);

int check (const char *s)
{
	return isBalanced(s, 0, 0);
}

int main() {
	const char *test[] = {")()()", "( )", "(())", "(", ")", "", "(()))", "(((())))", 
				"()()a+b(()())", "(() ( hi)) (())()(((( ))))",
				"(() ( hi))) (())()(((( ))))", "abcd"};

	for(int index = 0; index < sizeof(test) / sizeof(test[0]); ++index ) 
	{
		int result = check(test[index]);

		printf("%s:\t", test[index]);
		result == 1 ? printf("Good!\n") : printf("Bad \n");
	}

	return 0;
}

int isBalanced(const char *s, int idx, int count) {
	if (s[idx] == '\0') 
		return count == 0; // If the end of the string is reached, it's balanced
	if (s[idx] == ')') 
		return 0;		//this is not right so unbalanced
	else if (s[idx] == '(')
		return isOpenParenthesis(s, idx + 1, count + 1); //ah! an open bracket -- isOpenParenthesis will check if a closing is there
	else
		return isBalanced(s, idx + 1, count); //ignore other characters
}

int isOpenParenthesis(const char *s, int idx, int count) {
	if (s[idx] == '\0') 
		return 0; // If the end of the string is reached, it's not balanced
	if (s[idx] == '(') 
		return isBalanced(s, idx, count);	//ah! an open bracket -- isBalanced is supposed to handle this
	else if (s[idx] == ')')
		if (count == 1) 
			isBalanced(s, idx + 1, 0);
		else 
			isOpenParenthesis(s, idx + 1, count - 1); 
	else 
		return isOpenParenthesis(s, idx + 1, count); //ignore other characters
}

