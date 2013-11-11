#include<string>
#include<vector>
#include<cstring>
#include<iostream>
using namespace std;

class FoxAndGomoku
{
	public:
		int cnt[20][20][4];
		string win(vector <string> board)
		{
			memset(cnt,0,sizeof(cnt));
			
			bool ans = false;
			int row = board.size();
			int col = board[0].length();
			
			for(int i=0;i<row && !ans;i++)
			{
				for(int j=0; j<col && !ans; j++)
				{
					if(board[i][j] == 'o')
					{
						for(int k=0;k<4;k++)
							cnt[i][j][k] = 1;
						if(j>0 && cnt[i][j-1][0]>0)
							cnt[i][j][0] = cnt[i][j-1][0]+1;
						if(i>0 && cnt[i-1][j][1]>0)
							cnt[i][j][1] = cnt[i-1][j][1]+1;
						if(i>0 && j>0 && cnt[i-1][j-1][2]>0)
							cnt[i][j][2] = cnt[i-1][j-1][2]+1;
						if(i>0 && j<col-1 && cnt[i-1][j+1][3]>0)
							cnt[i][j][3] = cnt[i-1][j+1][3]+1;
						for(int k=0;k<4;k++)
							if(cnt[i][j][k]>=5)
							{
								ans = true;
								break;
							}
					}
				}
			}
			
			if(ans) return "found";
			else return "not found";
		}	
};

