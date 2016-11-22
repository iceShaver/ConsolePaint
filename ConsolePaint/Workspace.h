#pragma once
class Workspace
{
public:
	char* name;
	Workspace(char*);
	~Workspace();
	void draw();
	static int width;
	static int height;
};

