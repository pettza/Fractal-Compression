#include "SForm.h"

const pair<unsigned int, unsigned int>& SForm::operator()(unsigned int x, unsigned int y) const
{
	return transform[x][y];
}

const array<SForm, 8> SForm::GetS_Forms()
{
	array<SForm, 8> arr = {};
	for (unsigned int x = 0; x < N; x++) {
		for (unsigned int y = 0; y < N; y++) {
			arr[0].transform[x][y] = { x, y };
			arr[1].transform[x][y] = { N-1-x, y };
			arr[2].transform[x][y] = { x, N-1-y };
			arr[3].transform[x][y] = { N-1-x, N-1-y };
			arr[4].transform[x][y] = { y, x };
			arr[5].transform[x][y] = { N-1-y, x };
			arr[6].transform[x][y] = { y, N-1-y };
			arr[7].transform[x][y] = { N-1-y, N-1-x };
		}
	}

	return arr;
}
