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
int Map[maxn][maxn];//��ӡ�������

//һ���ڻ��ݷ����޸��˸�����ȫ�ֱ�����һ��Ҫ��ʱ�����ǻָ�ԭ״
void Search(int cur)   //���з��ûʺ�
{
	cnt++;
	if (cur == 8) {
		sum++;
		if (sum > 1)
			cout << '\n';
		for (int i = 0; i < cur; i++)Map[i][C[i]] = 1;//��ӡ��
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
		memset(Map, 0, sizeof(Map)); //��ԭ
	}
	else
		for (int i = 0; i < 8; i++)  //������ cur�е� �� �� ���ûʺ�
		{
			if (!vis[0][i] && !vis[1][cur + i] && !vis[2][cur - i + 8]) //�жϵ�ǰ���ԵĻʺ���С����Խ���
			{
				vis[0][i] = vis[1][cur + i] = vis[2][cur - i + 8] = true;
				C[cur] = i;//cur �е����� i
				Search(cur + 1);
				vis[0][i] = vis[1][cur + i] = vis[2][cur - i + 8] = false;//�мǣ�һ��Ҫ�Ļ���
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
	//    printf("%d %d\n",sum,cnt);//��� ������� �� �ݹ����
	system("pause");
	return 0;
}
