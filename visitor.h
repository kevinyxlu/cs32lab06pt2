#ifndef VISITOR_H
#define VISITOR_H

//#include "psData.h"
//#include "psCombo.h"
//#include "demogData.h"

/* a visitor can visit any of my specific data types */
class Visitor {
public:
  virtual void visit(class psCombo *e) = 0;
  virtual void visit(class demogData *e) = 0;
  virtual void visit(class psData *e) = 0;
};
#endif

