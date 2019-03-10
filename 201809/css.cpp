#include<bits/stdc++.h>
using namespace std;

vector<pair<string, int>> s;
// 将含有空格的待查询的标签解析出来
vector<string> parseLabel(string &t)
{
	vector<string> out;
	stringstream e(t);
	string temp;
	while(e >> temp)
		out.push_back(temp);
	return out;
}
pair<int, vector<int>> parseCss(vector<string> &p)
{
	vector<int> out;
	string temp, t;
	temp = p[p.size() - 1];					// 找到所有含有最后一级标签的行
	set<pair<int, int>> res;
	for(size_t i = 0; i < s.size(); i++)
	{
		t = s[i].first;
		if(temp.find("#") == string::npos)		// 最后一级标签不是id选择器，则把该行文档只保留标签(占10分)
		{
			t += " ";
			t = t.substr(0, t.find_first_of(' '));
		}
		if(t.find(temp) != string::npos)
			res.insert(make_pair(s[i].second, i));
	}
	if(p.size() == 1)		// 只查询一个标签
	{
		for(auto r : res)
			out.push_back(r.second + 1);
		return make_pair(res.size(), out);
	}
	else
	{
		string t;
		bool flag = true;
		int allLevel = 88;		// 层级最大为80
		for(size_t j = 0; j < s.size(); j++)
		{
			t = s[j].first;
			if(t.find(p[0]) != string::npos && s[j].second < allLevel)		// 对于第一个标签找最小层级
				allLevel = s[j].second;
		}
		for(size_t i = 1; i < p.size() - 1 ; i++)
		{
			int nowLevel = 88;
			for(size_t j = 0; j < s.size(); j++)
			{
				t = s[j].first;
				if(t.find(p[i]) != string::npos)
				{
					// 大于上一个标签的最小层数
					if(s[j].second > allLevel && s[j].second < nowLevel)
						nowLevel = s[j].second;
				}
			}
			if(88 == nowLevel)      // 该标签没有找到比上一标签大的层数
			{
				flag = false;
				break;
			}
			allLevel = nowLevel;
		}
		if(flag)
		{
			for(auto r : res)
			{
				if(r.first > allLevel)		// 比找到的倒数第二层标签层级还要小的层级
					out.push_back(r.second + 1);
			}
			return make_pair(out.size(), out);
		}
		else		// 没有找到满足条件的标签
		{
			return make_pair(0, out);
		}
	}
}
int main()
{
	ios::sync_with_stdio(0);
	int n, m;
	string html;
	cin >> n >> m;
	cin.ignore(1);
	for(int i = 0; i < n; i++)
	{
		int cnt = 0;
		bool tolow = true;
		getline(cin, html);
		for(auto &r : html)		// 将标签统一转换为小写
		{
			if(isalpha(r) && tolow)
				r = tolower(r);
			if(r == '.')		// 统计层数
				cnt++;
			if(r == '#')		// 如果存在id则停止转换
				tolow = false;
		}
		s.push_back(make_pair(html, cnt));
	}
	string css;
	vector<string> label;		// 将待查询的标签解析出来
	pair<int, vector<int>> p;	// 用于输出的数据结构
	for(int i = 0; i < m; i++)
	{
		getline(cin, css);
		for(auto &r : css)
			if(r == '#')		// 待查询标签存在id选择器不转换大小写
				break;
			else
				r = tolower(r);
		label = parseLabel(css);
		p = parseCss(label);
		cout << p.first;
		if(p.second.size() != 0)
			for(auto s : p.second)
				cout << ' ' << s;
		cout << endl;
	}
	return 0;
}
