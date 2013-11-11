#include<string>
#include<vector>
#include<cstring>
#include<iostream>
using namespace std;

class FoxAndGo
{
	public:
		bool flag[22][22];
		bool dot[22][22];
		int cnt[22][22];
		int row,col;
		int num,need,doti,dotj;
		
		void fun(vector <string> b,int x,int y)
		{
			if(b[x][y]=='o')
			{
				if(!flag[x][y])
				{
					num++;
					find(b,x,y);
				}
			}
			else if(b[x][y]=='.')
			{
				if(!dot[x][y])
				{
					doti = x;
					dotj = y;
					need++;
					dot[x][y] = 1;
				}
			}
		}
		
		void find(vector <string> b,int x,int y)
		{
			flag[x][y] = 1;
			
			if(x>0)
				fun(b,x-1,y);
			if(y>0)
				fun(b,x,y-1);
			if(x<row-1)
				fun(b,x+1,y);
			if(y<col-1)
				fun(b,x,y+1);
		}
		
		int maxKill(vector <string> board)
		{
			memset(flag,0,sizeof(flag));
			memset(cnt,0,sizeof(cnt));
			int ans = 0;
			
			row = board.size();
			col = board[0].length();
			
			int maxn = 0;
			for(int i=0; i<row; i++)
			{
				for(int j=0; j<col; j++)
				{
					if(board[i][j] == 'o' && !flag[i][j])
					{
						memset(dot,0,sizeof(dot));
						
						num = 1;
						need = 0;
						doti = -1;
						dotj = -1;
						
						find(board,i,j);
						if(need==0) ans += num;
						if(need==1)
						{
							cnt[doti][dotj] += num;
							if(cnt[doti][dotj] > maxn) maxn = cnt[doti][dotj];
						}
					}
				}
			}
			
			ans += maxn;
			
			return ans;
		}	
};

{{
"o.x.xxxxo.x...", 
"......x...xoo.", 
"o.x.xo.xxo.xx.", 
"x......xx.xxxo", 
".xx.oxo.xx..x.", 
"x.x.x...x..xxo", 
".x.o.xx..xxx..", 
"...xx.xx.xox.o", 
"x...xx..xx.x..", 
"x..xx.x..xxo.x", 
"o...xxxx..x.x.", 
".xxxxxxox.o.xx", 
"..oxoxo.....xo", 
"x.xx.oo..x.ox."}}

{{
"o.xox.o", 
"..xox..", 
"xxxoxxx", 
"ooo.ooo", 
"xxxoxxx", 
"..xox..", 
"o.xox.o"}}

