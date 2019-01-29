# bs-react-navigation

[![Build Status][build-badge]][build]
[![Version][version-badge]][package]
[![MIT License][license-badge]][license]
[![PRs Welcome][prs-welcome-badge]][prs-welcome]

> A fast, declarative navigation for React Native, based on React Navigation

## Status

Currently we are not supporting the nested navigators.

## Installation

Open a Terminal in your project's folder and run,

```she
yarn add bs-react-navigation
```

After installation, you will need to install `react-navigation` and its peer dependencies. Please follow official installation instructions [here](https://reactnavigation.org/docs/en/getting-started.html#installation).

## Examples

- example built-in library - [/example](/example)

## API's

All of the navigators has similar API configuration flow.

## Stack navigator

First of all, create a config file like `Config.re` and there define your all routes:

> It is needed because ReasonML is aware of circular dependencies.

```ReasonML
type route =
  | Home
  | UserDetails(string);
```

- `Home` - route without custom parameters
- `User(string)` - route with parameters and their type is `string`

Now, after we create navigator routes, we need to create navigator type, which is created from a list of your routes.

```ReasonML
type navigationProp = StackNavigator.navigation(route);
```

The next step is to create actual navigator, for that, create a file where you will be put your navigator configuration. You need to use a functor `Create` from `StackNavigator` module and pass a configuration module which needs to include a few pieces:

- `route` - list of your routes, use variant from your `Config.re`
- `initialRoute` - the first screen of your navigation state
- `getScreen` - it's a function which as a paramiters get the `currentRoute` and `navigation` props. As a return you should create a tuple where first elelment is a screen component and the second is screen configuration.

Full example:

```ReasonML
open Config;

module Stack =
  StackNavigator.Create({
    open StackNavigator;

    type route = Config.route;

    let initialRoute = Home;

    let getScreen = (currentRoute, navigation) =>
      switch (currentRoute) {
      | Home => (<Screen navigation />, screenOptions(~title="Home", ()))
      | UserDetails(userId) => (
          <Screen navigation text={"Browsing profile of: " ++ userId} />,
          screenOptions(~title="Hello " ++ userId, ()),
        )
      };
  });
```

### Switch Navigator API

The API is almost the same as in Stack Navigator

```ReasonML
module Switch =
  SwitchNavigator.Create({
    open SwitchNavigator;

    type route = Config.route;

    let initialRoute = Login;

    let getScreen = (currentRoute, navigation) =>
      switch (currentRoute) {
      | Login => (<Login navigation />, screenOptions())
      | LoggedIn => (<LoggedIn navigation />, screenOptions())
      };
  });
```

### Drawer Navigator API

Drawer needs one additional setting compared to the Switch or Stack Navigator.

This is list of items that drawer needs to render itself:

```ReasonML
let items: list(item);
```

Full example:

```ReasonML
module Drawer =
  DrawerNavigation.Create({
    open DrawerNavigation;
    type item = Config.item;

    let items = [Dashbord, Settings];
    let drawerOptions = drawerOptions(());

    let order = [Dashbord, Settings];

    let getItem = currentItem =>
      switch (currentItem) {
      | Dashbord => (
          <Items.Dashboard />,
          screenOptions(~title="Info",
        )
      | Settings => (<Items.Settings />,
          screenOptions(~title="Settings",
        )
      };
  });

```

### Tab Navigator API

Tab needs one additional setting compared to the Switch or Stack Navigator.

This is list of items that drawer needs to render itself:

```ReasonML
let order: list(tabs);
```

Full example:

```ReasonML
module Tabs =
  TabNavigator.Create({
    open TabNavigator;

    type tabs = Config.tabs;
    type order = list(tabs);

    let tabBarOptions =
      tabBarOptions(~activeTintColor="#847", ());

    let order = [Info, Profile, Settings];

    let getTab = tab => {
      switch (tab) {
      | Info => (
          <Tabs.Info navigation/>,
          screenOptions(~title="Info"),
        )
      | Profile => (
          <Tabs.Profile navigation/>,
          screenOptions(~title="Profile"),
        )
      | Settings => (
          <Tabs.Settings navigation/>,
          screenOptions(~title="Settings"),
        )
      };
    };
  });


```

## Prior art

This library is a continuation of our efforts to provide a first-class navigation for `bs-react-native` applications.

If you are coming from `rebolt-navigation` or `reroute-native` (our previous attempts at solving this problem),
please open an issue and let us know. We will help you find the best migration path to adopt this library.

## Developing example app

Inside the root folder, run BS build script:

```sh
yarn start
```

next, go to the example app and start the watch script for building the ReasonML code:

```sh
yarn watch
```

The last step is to start the [Expo](https://expo.io/learn) packager inside your example app

```sh
yarn start
```

## License

See Reason license in [LICENSE.txt](LICENSE.txt).

<!-- badges -->

[build-badge]: https://img.shields.io/circleci/project/github/callstackincubator/rebolt-navigation/master.svg?style=flat-square
[build]: https://circleci.com/gh/callstackincubator/rebolt-navigation
[version-badge]: https://img.shields.io/npm/v/rebolt-navigation.svg?style=flat-square
[package]: https://www.npmjs.com/package/rebolt-navigation
[license-badge]: https://img.shields.io/npm/l/rebolt-navigation.svg?style=flat-square
[license]: https://opensource.org/licenses/MIT
[prs-welcome-badge]: https://img.shields.io/badge/PRs-welcome-brightgreen.svg?style=flat-square
[prs-welcome]: http://makeapullrequest.com
