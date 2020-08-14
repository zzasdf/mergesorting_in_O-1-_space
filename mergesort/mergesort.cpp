#include <iostream>
#include <vector>
using namespace std;
int main() {
	int n=1;
	int length;
	cin >> length;

	vector<double> a(length);
	for (int i = 0;i < length;i++) {
		cin >> a[i];
	}

	while (n < length) {
		n *= 2;
	}

	int merge_size = 2;
	int submerge_size;
	double tem;
	int temsize;
	for (;merge_size <= n;merge_size *= 2) {
		for (int index = 0;index < n;index += merge_size)
			for (int pointer = 0;pointer < merge_size / 2;pointer++){
				if (pointer+index < length&&index + merge_size - pointer - 1 < length && a[pointer+index] > a[index + merge_size - pointer - 1 ]) {
				tem = a[pointer+index];
				a[pointer+index] = a[index + merge_size - pointer - 1];
				a[index + merge_size - pointer - 1] = tem;
			}
		}
		cout << "m ";
		for (int i = 0;i < length;i++) {
			cout << a[i] << ' ';
		}
		cout << endl;
		submerge_size = merge_size / 2;
		for (;submerge_size > 1;submerge_size /= 2) {
			temsize = submerge_size / 2;
			for (int index = 0;index < n;index += submerge_size) {
				for (int pointer = index;pointer < index + temsize;pointer++) {
					if (pointer < length && pointer + temsize<length && a[pointer] > a[pointer + temsize]) {
						tem = a[pointer];
						a[pointer] = a[pointer + temsize];
						a[pointer + temsize] = tem;
					}
				}
			}
			cout << "s ";
			for (int i = 0;i < length;i++) {
				cout << a[i] << ' ';
			}
			cout << endl;
		}
	}
	for (int i = 0;i < length;i++) {
		cout << a[i] << ' ';
	}
	return 0;
}




