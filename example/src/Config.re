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