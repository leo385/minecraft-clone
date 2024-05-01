#pragma once

class RenderObject {

public:
	RenderObject() = default;
	virtual ~RenderObject() {}

	virtual void init() = 0;
	virtual void render() = 0;


};