#pragma once

#include "MVP.h"

class RenderObject {

public:
	RenderObject() = default;
	virtual ~RenderObject() {}

	virtual void init() = 0;
	virtual void render() = 0;
	
	virtual MVP& getMVP() = 0;
};