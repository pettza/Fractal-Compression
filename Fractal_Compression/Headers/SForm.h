#pragma once

#include "constants.h"
#include <array>

using namespace std;

class SForm
{
private:
	array<array<pair<unsigned int, unsigned int>, N>, N> transform;

private:
	SForm() {}

public:
	SForm(const SForm& other) :transform(other.transform) {}
	
	~SForm() {}
	
	const pair<unsigned int, unsigned int>& operator() (unsigned int x, unsigned int y) const;

	static const array<SForm, 8> GetS_Forms();
};
