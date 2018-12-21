open BsReactNative;
type navigation('a) = {navigate: 'a => unit};


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
  tabStyle: Style.t
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
    tabBarButtonComponent: ReasonReact.componentSpec(
      ReasonReact.stateless,
      ReasonReact.stateless,
      ReasonReact.noRetainedProps,
      ReasonReact.noRetainedProps,
      ReasonReact.actionless
    ),
    [@bs.optional]
    tabBarAccessibilityLabel: string,
    [@bs.optional]
    tabBarTestID: string,
    /* [@bs.optional]
    tabBarOnPress: string */
  };


module NavigationProp = {
  type t
}


 module ScreenOptions = {
    type t = {. "navigation": NavigationProp.t};
 };

 
 
module type TabConfig = {
  type tabs;
  type order = list(tabs);   
  let order: order;
  let tabBarOptions: tabBarOptions;
  let getTab: (tabs) => (Js.Dict.key, unit => ReasonReact.reactElement, screenOptions);
};


module Create = (Config: TabConfig) => {
[@bs.deriving abstract]
type navigatorConfig = {initialRouteName: string};


  [@bs.deriving abstract]
  type routeConfig = {
    screen: unit => ReasonReact.reactElement,
    navigationOptions: screenOptions,
  };

  let routes = Js.Dict.empty();

  let tabs = Config.order 
	|> List.iter(tab => {
      let (tabname, screen, screenOptionsConfig ) = Config.getTab(tab);
	  Js.Dict.set(routes, tabname, routeConfig(~screen=screen, ~navigationOptions=screenOptionsConfig));
  });

  let tabBarOptions = Js.Dict.empty();
  Js.Dict.set(tabBarOptions, "tabBarOptions", Config.tabBarOptions)

  
  
  /* navigator */
  let navigator = ReactNavigation.Tab.createBottomTabNavigator(routes, tabBarOptions);
  

  /* Wrap StackNavigator with the AppContainer - temporary */
  let render = ReactNavigation.Native.createAppContainer(navigator);
};