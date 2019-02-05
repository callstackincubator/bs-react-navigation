type navigation('a) = {navigate: 'a => unit};

type position =
  | Left
  | Right;

type drawerType =
  | Front
  | Back
  | Slide;

[@bs.deriving abstract]
type options = {
  [@bs.optional]
  width: int,
  [@bs.optional]
  useNativeAnimations: bool,
  [@bs.optional]
  backgroundColor: string,
  [@bs.optional]
  swipeEnabled: bool,
  [@bs.optional]
  position,
  [@bs.optional]
  drawerType,
};

[@bs.deriving abstract]
type screenOptions = {title: string};

module type Config = {
  type item;

  let items: list(item);

  let options: options;
  let getItem: item => (ReasonReact.reactElement, screenOptions);
};

let getPositionString = position =>
  switch (position) {
  | Some(p) =>
    switch (p) {
    | Left => "left"
    | Right => "right"
    }
  | None => "right"
  };

let getDrawerTypeString = drawerType =>
  switch (drawerType) {
  | Some(t) =>
    switch (t) {
    | Front => "front"
    | Back => "back"
    | Slide => "slide"
    }
  | None => "front"
  };

module Create = (Config: Config) => {
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
           screenOptionsConfig->titleGet,
           routeConfig(
             ~screen=() => screen,
             ~navigationOptions=screenOptionsConfig,
           ),
         );
       })
    |> Js.Dict.fromList;

  let drawerConfig = {
    "swipeEnabled": Config.options->swipeEnabledGet,
    "drawerOptions": {
      "drawerBackgroundColor": Config.options->backgroundColorGet,
      "drawerWidth": Config.options->widthGet,
      "drawerPosition": getPositionString(Config.options->positionGet),
      "drawerType": getDrawerTypeString(Config.options->drawerTypeGet),
    },
  };

  /* navigator */
  let navigator = ReactNavigation.Drawer.create(items, drawerConfig);

  /* Wrap StackNavigator with the AppContainer - temporary */
  let render = ReactNavigation.Native.createAppContainer(navigator);
};