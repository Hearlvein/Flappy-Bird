#include "Score.h"



Score::Score()
{
}


Score::~Score()
{
}

void Score::reset()
{
	setString("0");
}

void Score::increment()
{
	++m_score;
	std::stringstream ss;
	unsigned int score = m_score;
	ss << score;

	setString(ss.str());
}