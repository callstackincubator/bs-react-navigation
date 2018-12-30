open BsReactNative;
type navigation = {
  navigate: string => unit,
  goBack: unit => unit,
};

[@bs.deriving abstract]
type tabBarOptions = {
  [@bs.optional]
  activeTintColor: string,
  [@bs.optional]
  activeBackgroundColor: string,
  [@bs.optional]
  inactiveTintColor: string,
  [@bs.optional]
  inactiveBackgroundColor: string,
  [@bs.optional]
  showLabel: bool,
  [@bs.optional]
  showIcon: bool,
  [@bs.optional]
  allowFontScaling: bool,
  [@bs.optional]
  style: Style.t,
  [@bs.optional]
  labelStyle: Style.t,
  [@bs.optional]
  tabStyle: Style.t,
};

[@bs.deriving abstract]
type screenOptions = {
  [@bs.optional]
  title: string,
  [@bs.optional]
  tabBarVisible: bool,
  [@bs.optional]
  tabBarIcon: ReasonReact.reactElement,
  [@bs.optional]
  tabBarLabel: string,
  [@bs.optional]
  tabBarButtonComponent: ReasonReact.reactElement,
  [@bs.optional]
  tabBarAccessibilityLabel: string,
  [@bs.optional]
  tabBarTestID: string,
  /* [@bs.optional]
     tabBarOnPress: string, */
};

module NavigationProp = {
  type t;
};

module type TabConfig = {
  type tabs;
  type order = list(tabs);
  let order: order;
  let containerName: string;
  let tabBarOptions: tabBarOptions;
  let getTab:
    (tabs, navigation) =>
    (Js.Dict.key, unit => ReasonReact.reactElement, screenOptions);
};

module Create = (Config: TabConfig) => {
  [@bs.deriving abstract]
  type navigatorConfig = {initialRouteName: string};

  [@bs.deriving abstract]
  type routeConfig = {
    screen: unit => ReasonReact.reactElement,
    navigationOptions: screenOptions,
  };

  module NavigationProp = {
    [@bs.send] external navigate: string => unit = "navigate";

    [@bs.send] external goBack: unit => unit = "goBack";
  };

  let makeNavigationProp = () => {
    navigate: routeName => NavigationProp.navigate(routeName),
    goBack: () => NavigationProp.goBack(),
  };

  let tabs =
    Config.order
    |> List.map(tab => {
         let (tabname, screen, screenOptionsConfig) =
           Config.getTab(tab, makeNavigationProp());
         (
           tabname,
           routeConfig(~screen, ~navigationOptions=screenOptionsConfig),
         );
       })
    |> Js.Dict.fromList;

  let tabBarOptions = {
    "swipeEnabled": true,
    "animationEnabled": true,
    "tabBarOptions": Config.tabBarOptions,
  };

  let navigator =
    ReactNavigation.Tab.createBottomTabNavigator(tabs, tabBarOptions);

  let make = ReactNavigation.Native.createAppContainer(navigator);
};