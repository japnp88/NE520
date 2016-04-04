#ifndef NE520APP_H
#define NE520APP_H

#include "MooseApp.h"

class Ne520App;

template<>
InputParameters validParams<Ne520App>();

class Ne520App : public MooseApp
{
public:
  Ne520App(InputParameters parameters);
  virtual ~Ne520App();

  static void registerApps();
  static void registerObjects(Factory & factory);
  static void associateSyntax(Syntax & syntax, ActionFactory & action_factory);
};

#endif /* NE520APP_H */
