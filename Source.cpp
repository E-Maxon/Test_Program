#include <iostream>
#include <vector>
#include <string>

using namespace std;

const int NEED = 200;

void make_equation(int i, string str, int res, int prev, const vector<int>& digits, vector<string>& ans) {
    if (i == digits.size()) {
        if (res == 200) {
            ans.push_back(str);
        }
        return;
    }
    str += "+";
    str += (digits[i] + '0');
    make_equation(i + 1, str, res + digits[i], digits[i], digits, ans);
    str.pop_back();
    str.pop_back();

    str += "-";
    str += (digits[i] + '0');
    make_equation(i + 1, str, res - digits[i], -digits[i], digits, ans);
    str.pop_back();
    str.pop_back();

    str += (digits[i] + '0');
    make_equation(i + 1, str, res - prev + prev * 10 + digits[i], prev * 10 + digits[i], digits, ans);
    str.pop_back();
}

int main() {
    vector<int> digits = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };
    vector<string> ans;
    string start = "";
    start += digits[0] + '0';
    make_equation(1, start, digits[0], digits[0], digits, ans);
    cout << ans.size() << '\n';
    for (auto str : ans) {
        cout << str << "=" << NEED << '\n';
    }
}
