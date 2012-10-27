#ifndef __Parcheesi__GlDiceRenderer__
#define __Parcheesi__GlDiceRenderer__

#include "IObjectRenderer.h"
#include "Canvas.h"

#include <GLUT/GLUT.h>
#include <math.h>

class GlDiceRenderer : public IObjectRenderer {
private:
	Canvas cvs;
	int value;
	void initialize();
	
public:
	GlDiceRenderer(int value);
	virtual IObjectRenderer* getNext();
	virtual void setNext(IObjectRenderer* next);
	virtual void render();
};

#endif /* defined(__Parcheesi__GlDiceRenderer__) */
