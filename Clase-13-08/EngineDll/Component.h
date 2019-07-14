#pragma once
#include "Exports.h"
#include "Include.h"

class ENGINEDLL_API Component {
protected:
	const char* _name;
public:
	Component(const char* name);
	~Component();
	void SetName(const char* newName);
	const char* GetName() { return _name; }
};

