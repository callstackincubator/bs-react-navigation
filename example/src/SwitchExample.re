open BsReactNavigation;

/**
  * Route and Navigation types are kept in a separate module to
  * handle circular references between modules
  */
open Config;

module Switch =
  SwitchNavigator.Create({
    open SwitchNavigator;

    type route = Config.loginRoute;
    let initialRoute = Login;

    let getScreen = (route, navigation) =>
      switch (route) {
      | Login => (<Login navigation />, screenOptions())
      | LoggedIn => (<LoggedIn navigation />, screenOptions())
      };
  });

let render = Switch.render;