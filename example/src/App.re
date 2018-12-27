let stack = Stack.render;
let tab = TabExample.render;
let drawer = DrawerExample.render;

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

let switchNavigator = Switch.render;

let app = drawer;