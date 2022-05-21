#include <iostream>
#include <vector>

using namespace std;

using ll = long long;
using vl = vector<ll>;
using vb = vector<bool>;

int main() {
	ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int t;
	cin >> t;
	while (0 < (t--)) {
		int n;
		cin >> n;

		auto xs = vl(n);
		auto ys = vl(n);
		auto sumx = double{ 0 };
		auto sumy = double{ 0 };
		for (int i = 0; i < n; ++i) {
			cin >> xs[i];
			cin >> ys[i];

			sumx += xs[i];
			sumy += ys[i];
		}

		sumx /= n;
		sumy /= n;

		if (1 == n % 2) {
			auto isFound = bool{ false };
			for (int i = 0; i < n; ++i) {
				if (xs[i] == sumx && ys[i] == sumy) {
					isFound = true;
					break;
				}
			}

			if (!isFound) {
				cout << "no\n";
				continue;
			}
		}

		auto isUsed = vb(n, false);
		auto isGood = bool{ true };
		for (int i = 0; i < n; ++i) {
			if (isUsed[i]) {
				continue;
			}

			const auto& px = xs[i] - sumx;
			const auto& py = ys[i] - sumy;

			auto isFound = false;
			for (int j = i; j < n; ++j) {
				const auto& qx = sumx - xs[j];
				const auto& qy = sumy - ys[j];

				if (px == qx && py == qy) {
					isFound = true;
					isUsed[j] = true;
					break;
				}
			}

			if (!isFound) {
				cout << "no\n";
				isGood = false;
				break;
			}
		}

		if (isGood) {
			cout << "yes\n";
		}
	}

	return 0;
}