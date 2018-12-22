open BsReactNavigation;

type route =
  | Home
  | UserDetails(string);

type navigation = StackNavigator.navigation(route);

type item =
  | Dashbord
  | Settings;

type drawerNavigationProp = DrawerNavigation.navigation(route);