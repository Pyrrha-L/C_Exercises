#include <string>
#include <iostream>
using namespace std;

void solve_last_segment(bool &ul, bool &paragraph)//解决上一区块的遗留问题
{
    if(ul){
        cout << "</ul>" << endl;
        ul = false;
    }
    if(paragraph){
        cout << "</p>" << endl;
        paragraph = false;
    }
}
string getHTML(string &str, unsigned int start, unsigned int end)//获取[start,end)对应的HTML行内
{
    string ans = "";
    unsigned int index = start;
    unsigned int s1, s2;
    string link = "";
    string text = "";
    while(index < end)
    {
        switch(str[index]){
            case '_':
                index++;
                s1 = index;
                while(index < end && str[index] != '_') {
                    index++;
                }
                s2 = index;
                index++;
                ans += "<em>" + getHTML(str, s1, s2) + "</em>";
                break;
            case '[':
                index++;
                s1 = index;
                while(index < end && str[index] != ']') {
                    index++;
                }
                s2 = index;
                index += 2;
                text = getHTML(str, s1, s2);
                s1 = index;
                while(index < end && str[index] != ')') {
                    index++;
                }
                s2 = index;
                index++;
                link = str.substr(s1, s2 - s1);
                ans += "<a href=\"" + link + "\">" + text + "</a>";
                break;
            default:
                ans += str[index];
                index++;
                break;
        }
    }
    return ans;
}
int main(int argc, char const *argv[])
{
    string input = "";
    bool ul = false;//标记上一行是否为无序列表
    bool paragraph = false;//标记上一行是否为一段
    int cnt;//记录标题级数
    unsigned int index;//记录字符的开始位置
    unsigned int end;
    while(getline(cin, input)) {
        end = input.length();
        if(input == ""){//若为空行那么新区快将会产生
            solve_last_segment(ul, paragraph);
            continue;
        }
        switch(input[0])
        {
            case '#':
                cnt = 0;
                index = 0;
                while(index < input.length() && input[index] == '#') {
                    cnt++;
                    index++;
                }
                while(index < input.length() && input[index] == ' ') {
                    index++;
                }
                cout << "<h" << cnt << ">" << getHTML(input, index, end) << "</h" << cnt << ">" << endl;
                break;
            case '*':
                if(!ul){
                    cout << "<ul>" << endl;
                    ul = true;
                }
                index = 1;
                while(index < input.length() && input[index] == ' ') {
                    index++;
                }
                cout << "<li>" << getHTML(input, index, end) << "</li>" << endl;
                break;
            default:
                if(paragraph){
                    cout << endl;
                }
                else
                {
                    cout << "<p>";
                    paragraph = true;
                }
                index = 0;
                while(index < input.length() && input[index] == ' ') {
                    index++;
                }
                cout << getHTML(input, index, end);
                break;
        }
    }
    solve_last_segment(ul, paragraph);
    return 0;
}

