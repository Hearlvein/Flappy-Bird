#include "Scene.h"

Scene::Scene() :
	m_quit(false)
{
}

bool Scene::quit() const
{
	return m_quit;
}