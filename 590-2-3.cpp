#include<string>
#include<vector>
#include<cstring>
#include<map>
#include<iostream>
#include<algorithm>
using namespace std;

#define MAX(x,y) (x)>(y)?(x):(y)

const int mol = 1000000007;
const int MAX = 55;

class FoxAndShogi
{
	public:		
		int row,col;
		map<string,int> rec;
		
		int cal(string col)
		{			
			int pos[MAX][2];
			memset(pos,0,sizeof(pos));
			
			int cnt = 0;
			int n = col.length();
			
			
			for(int i=0; i<n; i++)
			{
				if(col[i]=='U') 
				{
					pos[cnt][0] = i;
					pos[cnt++][1] = -1;
				}
				else if(col[i]=='D')
				{
					pos[cnt][0] = i;
					pos[cnt++][1] = 1;
				}
			}
			
			if(cnt==0) return 1;
			
			int dp[MAX][MAX];
			memset(dp,0,sizeof(dp));
			
			for(int i=pos[0][0]; i>=0 && i<n; i+=pos[0][1])
				dp[0][i] = 1;
			
			
			for(int i=1; i<cnt; i++)
			{
				for(int j=pos[i][0]; j>=0 && j<n; j+=pos[i][1])
					for(int k=0; k<j; k++)
					{
						dp[i][j] += dp[i-1][k];
						dp[i][j] %= mol;
					}
			}
			/*
			for(int i=0; i<cnt; i++)
			{
				for(int j=0; j<n; j++)
					cout<<dp[i][j]<<" ";
				cout<<endl;
			}*/
			int ans = 0;
			for(int i=0; i<n; i++)
			{
				ans += dp[cnt-1][i];
				ans %= mol;
			}
			return ans % mol;
		} 
		
		int differentOutcomes(vector <string> board)
		{
			long long ans = 1;
			
			row = board.size();
			col = board[0].length();
			
			for(int j=0; j<col; j++)
			{
				string coltmp;
				coltmp.resize(row);
				for(int i=0; i<row; i++)
				{
					coltmp[i] = board[i][j];
				}
				
				int cnt;
				if(rec[coltmp]>0) 
					cnt = rec[coltmp];
				else 
				{
					cnt = cal(coltmp);
					rec[coltmp] = cnt;
				}
				
				ans = (ans * cnt) % mol;
			}
			
			return ans % mol;
		}	
};

int main()
{
	FoxAndShogi t;
	string tmp = "D.D..U";
	cout << t.cal(tmp) << endl;
	return 0;
}
