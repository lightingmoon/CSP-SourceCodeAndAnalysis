#include<bits/stdc++.h>
using namespace std;

vector<pair<string, int>> s;
// �����пո�Ĵ���ѯ�ı�ǩ��������
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
	temp = p[p.size() - 1];					// �ҵ����к������һ����ǩ����
	set<pair<int, int>> res;
	for(size_t i = 0; i < s.size(); i++)
	{
		t = s[i].first;
		if(temp.find("#") == string::npos)		// ���һ����ǩ����idѡ��������Ѹ����ĵ�ֻ������ǩ(ռ10��)
		{
			t += " ";
			t = t.substr(0, t.find_first_of(' '));
		}
		if(t.find(temp) != string::npos)
			res.insert(make_pair(s[i].second, i));
	}
	if(p.size() == 1)		// ֻ��ѯһ����ǩ
	{
		for(auto r : res)
			out.push_back(r.second + 1);
		return make_pair(res.size(), out);
	}
	else
	{
		string t;
		bool flag = true;
		int allLevel = 88;		// �㼶���Ϊ80
		for(size_t j = 0; j < s.size(); j++)
		{
			t = s[j].first;
			if(t.find(p[0]) != string::npos && s[j].second < allLevel)		// ���ڵ�һ����ǩ����С�㼶
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
					// ������һ����ǩ����С����
					if(s[j].second > allLevel && s[j].second < nowLevel)
						nowLevel = s[j].second;
				}
			}
			if(88 == nowLevel)      // �ñ�ǩû���ҵ�����һ��ǩ��Ĳ���
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
				if(r.first > allLevel)		// ���ҵ��ĵ����ڶ����ǩ�㼶��ҪС�Ĳ㼶
					out.push_back(r.second + 1);
			}
			return make_pair(out.size(), out);
		}
		else		// û���ҵ����������ı�ǩ
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
		for(auto &r : html)		// ����ǩͳһת��ΪСд
		{
			if(isalpha(r) && tolow)
				r = tolower(r);
			if(r == '.')		// ͳ�Ʋ���
				cnt++;
			if(r == '#')		// �������id��ֹͣת��
				tolow = false;
		}
		s.push_back(make_pair(html, cnt));
	}
	string css;
	vector<string> label;		// ������ѯ�ı�ǩ��������
	pair<int, vector<int>> p;	// ������������ݽṹ
	for(int i = 0; i < m; i++)
	{
		getline(cin, css);
		for(auto &r : css)
			if(r == '#')		// ����ѯ��ǩ����idѡ������ת����Сд
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
