type navigation('a) = {navigate: 'a => unit};

[@bs.deriving abstract]
type tabBarOptions = {
  [@bs.optional]
  showLabel: string,
};

[@bs.deriving abstract]
type navigatorConfig = {initialRouteName: string};

module type StackConfig = {
  type tabs;
  let initialRoute: tabs;
  let getTab: (tabs, navigation(tabs)) => ReasonReact.reactElement;
};

module Create = (Config: StackConfig) => {
  let screen = Config.getTab(Config.initialRoute);

  /* navigator */
  let navigator = ReactNavigation.TabNavigator.create({"Home": screen});

  /* Wrap StackNavigator with the AppContainer - temporary */
  let render = ReactNavigation.Native.createAppContainer(navigator);
};