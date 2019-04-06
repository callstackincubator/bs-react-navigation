open BsReactNavigation;

/**
  * Route and Navigation types are kept in a separate module to
  * handle circular references between modules
  */
open Config;

module Stack =
  StackNavigator.Create({
    open StackNavigator;
    open BsReactNative;

    /**
      * StackNavigator requires `route` type to be defined.
      */
    type route = Config.route;

    /**
      * Initial route to start with. Has to be one of `route` variants.
      */
    let initialRoute = Home;

    /**
      * Returns a screen for a given route and its options.
      *
      * To declare options, you call `StackNavigator.screenOptions` and provide
      * same keys as `navigationOptions` of React Navigation.
      *
      * This is to allow optional fields to be provided.
      */
    let headerStyle =
      Style.style([Style.backgroundColor(String("#3498db"))]);
    let headerTitleStyle = Style.style([Style.color(String("#f1c40f"))]);
    let headerTintColor = Style.String("red");
    let getScreen = (route, navigation) =>
      switch (route) {
      | Home => (
          <Screen navigation />,
          screenOptions(
            ~title="Home",
            ~headerStyle,
            ~headerTitleStyle,
            ~headerTintColor,
            (),
          ),
        )
      | UserDetails(userId) => (
          <Screen navigation text={"Browsing profile of: " ++ userId} />,
          screenOptions(~title="Hello " ++ userId, ()),
        )
      };
  });

let render = Stack.render;