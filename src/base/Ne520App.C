#include "Ne520App.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

template<>
InputParameters validParams<Ne520App>()
{
  InputParameters params = validParams<MooseApp>();

  params.set<bool>("use_legacy_uo_initialization") = false;
  params.set<bool>("use_legacy_uo_aux_computation") = false;
  params.set<bool>("use_legacy_output_syntax") = false;

  return params;
}

Ne520App::Ne520App(InputParameters parameters) :
    MooseApp(parameters)
{
  Moose::registerObjects(_factory);
  ModulesApp::registerObjects(_factory);
  Ne520App::registerObjects(_factory);

  Moose::associateSyntax(_syntax, _action_factory);
  ModulesApp::associateSyntax(_syntax, _action_factory);
  Ne520App::associateSyntax(_syntax, _action_factory);
}

Ne520App::~Ne520App()
{
}

// External entry point for dynamic application loading
extern "C" void Ne520App__registerApps() { Ne520App::registerApps(); }
void
Ne520App::registerApps()
{
  registerApp(Ne520App);
}

// External entry point for dynamic object registration
extern "C" void Ne520App__registerObjects(Factory & factory) { Ne520App::registerObjects(factory); }
void
Ne520App::registerObjects(Factory & factory)
{
}

// External entry point for dynamic syntax association
extern "C" void Ne520App__associateSyntax(Syntax & syntax, ActionFactory & action_factory) { Ne520App::associateSyntax(syntax, action_factory); }
void
Ne520App::associateSyntax(Syntax & /*syntax*/, ActionFactory & /*action_factory*/)
{
}
