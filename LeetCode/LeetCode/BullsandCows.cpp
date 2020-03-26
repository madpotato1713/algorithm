/* CASE1 */
class Solution {
public:
	string getHint(string secret, string guess) {
		int bulls = 0, cows = 0;
		unordered_map<char, int> um;

		for (int i = 0; i < secret.size(); i++) {
			if (secret[i] == guess[i]) {
				bulls++;
				guess[i] = ' ';
			}
			else {
				um[secret[i]]++;
			}
		}

		for (int i = 0; i < guess.size(); i++) {
			if (um[guess[i]]) {
				um[guess[i]]--;
				cows++;
			}
		}

		return to_string(bulls) + "A" + to_string(cows) + "B";
	}
};

/* CASE2 */
class Solution {
public:
	string getHint(string secret, string guess) {
		int bulls = 0, cows = 0;
		int map[10] = { 0 };

		for (int i = 0; i < secret.size(); i++) {
			if (secret[i] == guess[i]) {
				bulls++;
			}
			map[guess[i] - '0']++;
		}

		for (int i = 0; i < secret.size(); i++) {
			if (map[secret[i] - '0']-- > 0) {
				cows++;
			}
		}

		return to_string(bulls) + "A" + to_string(cows - bulls) + "B";
	}
};