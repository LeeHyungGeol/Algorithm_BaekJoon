#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>

using namespace std;

multimap<int, string> MM;

string solution(string number, vector<string> dictionary);

int main() {
    vector<string> dictionary = { "is","there","anybody","out","there" };
    string number = "25735";
    cout << solution(number, dictionary) << '\n';
    return 0;
}

string solution(string number, vector<string> dictionary) {
    string answer = "";

    sort(dictionary.begin(), dictionary.end());

    for (string dict : dictionary) {
        MM.insert({ (int)dict.size(), dict });
    }

    for (int i = 0; i < number.length(); ++i) {
        auto iter = MM.find(number[i] - '0');
        answer += iter->second + " ";
        MM.erase(iter);
    }

    answer.pop_back();

    return answer;
}