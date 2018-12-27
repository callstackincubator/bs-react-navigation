open BsReactNavigation;

type route =
  | Home
  | UserDetails(string);

type navigation = StackNavigator.navigation(route);

type loginRoute = 
  | Login
  | LoggedIn

type loginNavigation = SwitchNavigator.navigation(loginRoute);

type item =
  | Dashbord
  | Settings;

type drawerNavigationProp = DrawerNavigation.navigation(route);