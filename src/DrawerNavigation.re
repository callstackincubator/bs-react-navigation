type navigation('a) = {navigate: 'a => unit};

[@bs.deriving abstract]
type drawerOptions = {
  [@bs.optional]
  drawerWidth: int,
  [@bs.optional]
  useNativeAnimations: bool,
  [@bs.optional]
  drawerBackgroundColor: string,
};

[@bs.deriving abstract]
type screenOptions = {drawerLabel: string};

module type TabConfig = {
  type item;
  let items: list(item);
  let drawerOptions: drawerOptions;
  let getItem: item => (ReasonReact.reactElement, screenOptions);
};

module Create = (Config: TabConfig) => {
  [@bs.deriving abstract]
  type navigatorConfig = {initialRouteName: string};

  [@bs.deriving abstract]
  type routeConfig = {
    screen: unit => ReasonReact.reactElement,
    navigationOptions: screenOptions,
  };

  let items =
    Config.items
    |> List.map(tab => {
         let (screen, screenOptionsConfig) = Config.getItem(tab);

         (
           drawerLabelGet(screenOptionsConfig),
           routeConfig(
             ~screen=() => screen,
             ~navigationOptions=screenOptionsConfig,
           ),
         );
       })
    |> Js.Dict.fromList;

  let drawerConfig = {
    "swipeEnabled": true,
    "drawerOptions": Config.drawerOptions,
  };

  /* navigator */
  let navigator = ReactNavigation.Drawer.create(items, drawerConfig);

  /* Wrap StackNavigator with the AppContainer - temporary */
  let render = ReactNavigation.Native.createAppContainer(navigator);
};