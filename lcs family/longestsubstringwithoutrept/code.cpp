#include<bits/stdc++.h>
using namespace std;
int longest(string s) {
	int cur_len = 1;
	int max_len = 1;
	int prev_index;
	int visited[256];
	memset(visited, -1, sizeof(visited));
	visited[s[0]] = 0;
	for (int i = 1; i < s.size(); i++) {
		prev_index = visited[s[i]];
		/* If the currentt character is not present in the  
        already processed substring or it is not part of  
        the current NRCS, then do cur_len++ */
		if (prev_index == -1 || i - cur_len > prev_index) {
			cur_len++;
		}
		  /* If the current character is present in currently  
        considered NRCS, then update NRCS to start from  
        the next character of the previous instance. */
		else {
			// Also, when we are changing the NRCS, we  
   //          should also check whether length of the  
   //          previous NRCS was greater than max_len or  
   //          not.
			if (cur_len > max_len) {
				max_len = cur_len;
			}
			cur_len = i - prev_index;
		}
		//update the index of current character
		visited[s[i]] = i;

	}
	if (cur_len > max_len)
		max_len = cur_len;
	return max_len;
}
int main() {
	string s;
	cin >> s;
	cout << longest(s);
}