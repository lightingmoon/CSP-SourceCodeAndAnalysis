#include<bits/stdc++.h>
using namespace std;
int monthDay[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
char mon[][4] = { "", "jan", "feb", "mar", "apr", "may", "jun", "jul", "aug", "sep", "oct", "nov", "dec" };
char day[][4] = { "sun", "mon", "tue", "wed", "thu", "fri", "sat" };
map<string, int> sWeek;
map<string, int> sMonth;
map<string, vector<string> > res;
void init()
{
    for (int i = 0; i <= 6; i++) sWeek[day[i]] = i;
    for (int i = 1; i <= 12; i++) sMonth[mon[i]] = i;
}
void toLower(string &t)
{
    for (size_t i = 0; i < t.length(); i++)
        t[i] = tolower(t[i]);
}
int toInt(string &t)
{
    stringstream o(t);
    int temp;
    o >> temp;
    return temp;
}
string toString(int t)
{
    stringstream o;
    o << t;
    return o.str();
}
bool isLunarYear(int y)
{
    return ((y % 4 == 0 && y % 100) || y % 400 == 0);
}
string getWeekday(int y, int m, int d)
{
    int tempY = 1970;
    int totalDay = 0;
    while (tempY < y) {
        totalDay += (isLunarYear(tempY) ) ? 366 : 365;
        tempY++;
    }
    for (int i = 1; i < m; i++) totalDay += monthDay[i];
    totalDay += d - 1;
    return "0" + toString((4 + totalDay % 7) % 7);
}
vector<string> getTaskRange(string &t)
{
    t += ",";
    size_t inx = t.find(",");
    vector<string> range;
    while (inx != string::npos) {
        string cut = t.substr(0, inx);
        t = t.substr(inx + 1, t.size() - inx - 1);
        size_t ins = cut.find("-");
        if (ins == string::npos) { // 非连续值
            if (isalpha(cut[0]) && sWeek.count(cut) != 0)  // 星期的英文
                cut = toString(sWeek[cut]);
            if (isalpha(cut[0]) && sMonth.count(cut) != 0) // 月份的英文
                cut = toString(sMonth[cut]);
            if (cut.size() == 1) cut = "0" + cut;
            range.push_back(cut);
        } else {  // 存在连续值
            string l = cut.substr(0, ins);
            string r = cut.substr(ins + 1, cut.size() - ins - 1);
            int lt, rt;
            if (sMonth.find(l) != sMonth.end()) { // 连续星期
                lt = isalpha(l[0]) ? sMonth[l] : toInt(l);
                rt = isalpha(r[0]) ? sMonth[r] : toInt(r);
            } else if (sWeek.find(l) != sWeek.end()) { //连续月份
                lt = isalpha(l[0]) ? sWeek[l] : toInt(l);
                rt = isalpha(r[0]) ? sWeek[r] : toInt(r);
            } else {
                lt = toInt(l);
                rt = toInt(r);
            }
            for (int i = lt; i <= rt; i++) {
                string in = toString(i);
                if (i < 10) in = "0" + in;
                range.push_back(in);
            }
        }
        inx = t.find(",");
    }
    return range;
}
int main()
{
    ios::sync_with_stdio(false);
    init();
    int n;
    string startTime, endTime;
    cin >> n >> startTime >> endTime;
    string beginY = startTime.substr(0, 4), beginMo = startTime.substr(4, 2), beginD = startTime.substr(6, 2);
    string beginH = startTime.substr(8, 2), beginM = startTime.substr(10, 2);
    int startYea = toInt(beginY);
    string endY = endTime.substr(0, 4), endMo = endTime.substr(4, 2), endD = endTime.substr(6, 2), endH = endTime.substr(8, 2);
    string endM = endTime.substr(10, 2);
    int endYea = toInt(endY);
    string  year, month, day, hour, minute, week, task;
    for (int i = 0; i < n; i++) {
        vector<string> doMinute, doHour, doDay, doMonth, doWeek;
        cin >> minute >> hour >> day >> month >> week >> task;
        toLower(month);
        toLower(week);
        if (minute == "*") minute = "0-59";
        if (hour == "*") hour = "0-23";
        if (day == "*")  day = "1-31";
        if (month == "*") month = "1-12";
        if (week == "*") week = "0-6";
        doMinute = getTaskRange(minute);
        doHour = getTaskRange(hour);
        doDay = getTaskRange(day);
        doMonth = getTaskRange(month);
        doWeek = getTaskRange(week);
        set<string> weekUnique;
        for(size_t i = 0; i < doWeek.size(); i++)
            weekUnique.insert(doWeek[i]); // 更快判断当天星期是否在范围内
        int tempYear = startYea;
        while (tempYear <= endYea) {
            if (isLunarYear(tempYear))
                monthDay[2] = 29;
            else
                monthDay[2] = 28;
            string curYear = toString(tempYear);
            for (size_t im = 0; im < doMonth.size(); im++) {
                string curM = doMonth[im];
                for (size_t id = 0; id < doDay.size(); id++) {
                    string curD = doDay[id];
                    string getweek = getWeekday(tempYear, toInt(curM), toInt(curD));
                    if (weekUnique.count(getweek) == 0 || (toInt(curD) > monthDay[toInt(curM)])) continue;
                    // 不在工作的星期范围或月份天数有误
                    for (size_t iH = 0; iH < doHour.size(); iH++) {
                        string curH = doHour[iH];
                        for (size_t iM = 0; iM < doMinute.size(); iM++) {
                            string curMi = doMinute[iM];
                            string date = curYear + curM + curD + curH + curMi;
                            if (date >= startTime && date < endTime)
                                res[date].push_back(task);
                        }
                    }
                }
            }
            tempYear++;
        }
    }
    for (map<string, vector<string> >::iterator it = res.begin(); it != res.end(); it++) {
        map<string, int> isprt;
        for (size_t i = 0; i < it->second.size(); i++) {
            string pt = it->first + " " + it->second[i];
            if(isprt.count(pt) == 0) {
                cout << pt << '\n';
                isprt[pt] = 1;
            }
        }
    }
    return 0;
}
