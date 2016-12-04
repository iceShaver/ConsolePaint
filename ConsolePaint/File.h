#pragma once
#include "Workspace.h"

class File
{

public:

	File();
	~File();
	static char* CreateNewFile();
	static Picture Read(char* file);
	static void Save(Workspace);
};

