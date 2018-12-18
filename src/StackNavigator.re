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

  module NavigationProp = {
    type t;

    module State = {
      type t;

      [@bs.get] external getParams: t => option(routeProps) = "params";
    };

    [@bs.send] external push: (t, string, routeProps) => unit = "push";

    [@bs.get "state"] external getState: t => State.t = "";

    let getParams = t => getState(t) |> State.getParams;
  };

  module ScreenOptions = {
    type t = {. "navigation": NavigationProp.t};
  };

  [@bs.deriving abstract]
  type routeConfig = {
    params: routeProps,
    screen: ScreenOptions.t => ReasonReact.reactElement,
    navigationOptions: ScreenOptions.t => screenOptions,
  };

  let containerDisplayName = "$bs-react-navigation_container";

  let makeNavigationProp = (navigation: NavigationProp.t) => {
    push: route =>
      NavigationProp.push(
        navigation,
        containerDisplayName,
        routeProps(~route),
      ),
    pop: _route => (),
  };

  let getCurrentScreen = (navigation: NavigationProp.t) => {
    /** Params can be `null` in React Navigation, but we are always declaring them */
    let params = NavigationProp.getParams(navigation) |> Js.Option.getExn;
    let nav = makeNavigationProp(navigation);

    Config.getScreen(routeGet(params), nav);
  };

  module Container = {
    let component = ReasonReact.statelessComponent("StackContainer");

    let make = (~navigation: NavigationProp.t, _children) => {
      ...component,
      render: _self => getCurrentScreen(navigation) |> fst,
    };
  };

  let route =
    routeConfig(
      ~params=routeProps(~route=Config.initialRoute),
      ~screen=
        (options: ScreenOptions.t) =>
          <Container navigation=options##navigation />,
      ~navigationOptions=
        (options: ScreenOptions.t) =>
          getCurrentScreen(options##navigation) |> snd,
    );

  /* StackNavigator route */
  let routes = Js.Dict.empty();
  Js.Dict.set(routes, containerDisplayName, route);

  /* StackNavigator config */
  let config = navigatorConfig(~initialRouteName=containerDisplayName);

  /* Router */
  let router = ReactNavigation.Core.stackRouter(routes, config);

  /* navigator */
  let navigator =
    ReactNavigation.Core.createNavigator(
      ReactNavigation.Stack.stackView,
      router,
      config,
    );

  /* Wrap StackNavigator with the AppContainer - temporary */
  let render = ReactNavigation.Native.createAppContainer(navigator);
};