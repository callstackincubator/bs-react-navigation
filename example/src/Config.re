open BsReactNavigation;

type route =
  | Home
  | UserDetails(string)
  | TabExample;

type navigationProp = StackNavigator.navigation(route);

type tabs =
  | Info
  | Profile
  | Settings;

type tabNavigationProp = TabNavigator.navigation;


type loginRoute = 
  | Login
  | LoggedIn

type loginNavigation = SwitchNavigator.navigation(loginRoute);

type item =
  | Dashbord
  | Settings;

type drawerNavigationProp = DrawerNavigation.navigation(route);
