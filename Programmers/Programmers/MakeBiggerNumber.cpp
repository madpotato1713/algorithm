#include <string>
#include <vector>

using namespace std;

string solve(const string& number, int index, int len) {
	if (len == 0) return "";

	string res = "";
	char num = NULL;
	int select = 0;
	for (int i = index; i < number.size() - (len - 1); i++) {
		if (num == NULL || num < number[i]) {
			num = number[i];
			select = i;
		}
	}

	res = res + num + solve(number, select + 1, len - 1);

	return res;
}

string solution(string number, int k) {
	return solve(number, 0, number.size() - k);
}