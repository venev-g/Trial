// Naive string matching

#include <stdio.h>
#include <string.h>

void search(char* pat, char* txt)
{
	int M = strlen(pat);
	int N = strlen(txt);




















































































































































	
	for (int i = 0; i <= N - M; i++) {
		int j;
		for (j = 0; j < M; j++)
			if (txt[i + j] != pat[j])
				break;
		if (j == M)
			printf("Pattern found at index %d \n", i);
	}
}

int main()
{
	char txt[] = "AABAACAADAABAAABAA";
	char pat[] = "AABA";
	search(pat, txt);
	return 0;
}

/*
Algorithm:
Algorithm-NAVE_STRING_MATCHING (T, P)
    for i←0 to n-m do
    if P[1......m] == T[i+1.....i+m] then
    print "Match Found"
    end
end

Time Complexity:
The time complexity of the Naive Algorithm is O(mn), where m is the 
size of the pattern to be searched and n is the size of the 
container string. 
*/
