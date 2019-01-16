open BsReactNavigation;
open BsReactNative;

/**
  * Route and Navigation types are kept in a separate module to
  * handle circular references between modules
  */
module Stack =
  StackNavigator.Create({
    open StackNavigator;
    open Config;

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
    let getScreen = (route, navigation) =>
      switch (route) {
      | Home => (
          <Screen
            button={
              <Button
                title="Go to details screen"
                onPress=(
                  () => navigation.push(UserDetails("Mike Grabowski"))
                )
              />
            }
          />,
          screenOptions(~title="Home", ()),
        )
      | UserDetails(userId) => (
          <Screen
            button={
              <Button title="Go back" onPress=(() => navigation.pop()) />
            }
            text={"Browsing profile of: " ++ userId}
          />,
          screenOptions(~title="Hello " ++ userId, ()),
        )
      | NestedStack => (SwitchExample.render, screenOptions(~title="Nested Stack", ()))
      };
  });

let render = Stack.make;