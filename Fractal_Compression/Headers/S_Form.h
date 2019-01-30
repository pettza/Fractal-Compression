#pragma once

#include <array>
#include <constants.h>

using namespace std;

class S_Form
{
private:
	array<array<pair<unsigned int, unsigned int>, N>, N> transform;

private:
	S_Form() {}

public:
	S_Form(const S_Form& other) :transform(other.transform) {}
	
	~S_Form() {}
	
	const pair<unsigned int, unsigned int>& operator() (unsigned int x, unsigned int y);

	static const array<S_Form, 8> GetS_Forms();
};
