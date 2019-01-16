open ReactNavigation;

type navigation('a) = {
  push: 'a => unit,
  pop: 'a => unit,
};

[@bs.deriving abstract]
type screenOptions = {
  [@bs.optional]
  title: string,
};

module type StackConfig = {
  type route;
  let initialRoute: route;
  let getScreen:
    (route, navigation(route)) => (ReasonReact.reactElement, screenOptions);
};

module Create = (Config: StackConfig) => {
  [@bs.deriving abstract]
  type navigatorConfig = {initialRouteName: string};

  [@bs.deriving abstract]
  type routeProps = {route: Config.route};

  type screenProps = {. "navigation": Navigation.t};

  [@bs.deriving abstract]
  type routeConfig = {
    params: routeProps,
    screen: screenProps => ReasonReact.reactElement,
    navigationOptions: screenProps => screenOptions,
  };
  
  let containerDisplayName = "$bs-react-navigation_container";
  let navigatorConfig = navigatorConfig(~initialRouteName=containerDisplayName);

  let makeNavigationProp = (navigation: Navigation.t) => {
    push: route =>
      Navigation.push(
        navigation,
        containerDisplayName,
        routeProps(~route),
      ),
    pop: _route => (),
  };

  let getCurrentScreen = (navigation:  Navigation.t) => {
    let params = Navigation.getParams(navigation) |> Js.Option.getExn;
    let navigationProp = makeNavigationProp(navigation);
    Config.getScreen(routeGet(params), navigationProp);
  };

  module Container = {
    let component = ReasonReact.statelessComponent("StackContainer");
    let make = (~navigation:  Navigation.t, _children) => {
      ...component,
      render: _self => getCurrentScreen(navigation) |> fst,
    };
  };

  let route =
    routeConfig(
      ~params=routeProps(~route=Config.initialRoute),
      ~screen=
        (options: screenProps) =>
          <Container navigation=options##navigation />,
      ~navigationOptions=
        (options: screenProps) =>
          getCurrentScreen(options##navigation) |> snd,
    );

  let routes = Js.Dict.empty();
  Js.Dict.set(routes, containerDisplayName, route);

  let router = Core.stackRouter(routes, navigatorConfig);
  
  let navigator =
    Core.createNavigator(
      Stack.stackView,
      router,
      navigatorConfig,
    );

  let render = Native.createAppContainer(navigator);
};
