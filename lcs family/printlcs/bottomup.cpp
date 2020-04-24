#include<bits/stdc++.h>
using namespace std;
string printlcs(string x, string y, int m, int n) {
	int t[m + 1][n + 1];
	for (int i = 0; i < m + 1; i++) {
		for (int j = 0; j < n + 1; j++) {
			if (i == 0 || j == 0)
				t[i][j] = 0;
		}
	}
	for (int i = 1; i < m + 1; i++) {
		for (int j = 1; j < n + 1; j++) {
			if (x[i - 1 ] == y[j - 1])
				t[i][j] = t[i - 1][j - 1] + 1;
			else
				t[i][j] = max(t[i - 1][j], t[i][j - 1]);
		}
	}
	int i = m;
	int j = n;
	string ans = "";

	while (i > 0 and j > 0) {
		if (x[i - 1] == y[j - 1]) {
			ans.push_back(x[i - 1]);
			i--;
			j--;
		}

		else {
			if (t[i][j - 1] > t[i - 1][j]) {
				j--;
			}
			else {
				i--;
			}
		}
	}
	reverse(ans.begin(), ans.end());
	return ans;
}
/*
string lcs(string a,string b)
{
    int la=a.length();
    int lb=b.length();
    int dp[1001][1001] = {0};

    for(int i=0;i<=la;i++)
    {
        dp[i][0]=0;
    }
    for(int i=0;i<=lb;i++)
    {
        dp[0][i]=0;
    }

    // Following steps build dp[m+1][n+1] in bottom up fashion. Note 
    // that dp[i][j] contains length of LCS of a[0..i-1] and b[0..j-1]
    for(int i=1;i<=la;i++)
    {
        for(int j=1;j<=lb;j++)
        {
            if(a[i-1]==b[j-1])
            {
                dp[i][j]=dp[i-1][j-1]+1;
            }
            else
            {
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    int i=la,j=lb;
    string ans="";
    // Start from the right-most-bottom-most corner and 
    // one by one store characters in lcs[] 
    while(i>0 && j>0)
    {
        if(a[i-1] == b[j-1])
        {
            // If current character in a and b are same, then 
            // current character is part of LCS 
            ans=a[i-1]+ans;
            i--;
            j--;
        }
        // If not same, then find the larger of two and 
        // go in the direction of larger value
        else if(dp[i-1][j]>dp[i][j-1])
        {
            i--;
        }
        else
        {
            j--;
        }
    }

    return ans;
}
*/
int main() {
	string x, y;
	cin >> x >> y;
	int m = x.size();
	int n = y.size();
	cout << printlcs(x, y, m, n);
}