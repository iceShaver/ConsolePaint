#pragma once
#include "Workspace.h"

class File
{

public:
	File();
	~File();
	static Picture Read(char* file);
	static int Save(Workspace*);
};

