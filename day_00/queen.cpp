#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<vector>
#include<unordered_map>
#include<stdio.h>
#include<string>
#include<algorithm> 
#include<math.h>

const int maxn = 100 + 10;
using namespace std;
int sum, cnt;
int C[maxn];
bool vis[3][maxn];
int Map[maxn][maxn];//打印解的数组

//一般在回溯法中修改了辅助的全局变量，一定要及时把他们恢复原状
void Search(int cur)   //逐行放置皇后
{
	cnt++;
	if (cur == 8) {
		sum++;
		if (sum > 1)
			cout << '\n';
		for (int i = 0; i < cur; i++)Map[i][C[i]] = 1;//打印解
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				if (Map[i][j]) {
					cout << "Q";
				}
				else
					cout << ".";
				if (j != 8 - 1) {
					cout << ' ';
				}
				else {
					cout << '\n';
				}
			}
		}
		memset(Map, 0, sizeof(Map)); //还原
	}
	else
		for (int i = 0; i < 8; i++)  //尝试在 cur行的 各 列 放置皇后
		{
			if (!vis[0][i] && !vis[1][cur + i] && !vis[2][cur - i + 8]) //判断当前尝试的皇后的列、主对角线
			{
				vis[0][i] = vis[1][cur + i] = vis[2][cur - i + 8] = true;
				C[cur] = i;//cur 行的列是 i
				Search(cur + 1);
				vis[0][i] = vis[1][cur + i] = vis[2][cur - i + 8] = false;//切记！一定要改回来
			}
		}
}
int main() {
	memset(vis, false, sizeof(vis));
	memset(Map, 0, sizeof(Map));
	sum = cnt = 0;
	Search(0);
	if (!sum) {
		cout << "None\n";
	}
	//    printf("%d %d\n",sum,cnt);//输出 解决方案 和 递归次数
	system("pause");
	return 0;
}
