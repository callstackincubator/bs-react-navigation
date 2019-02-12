# bs-react-navigation

[![Build Status][build-badge]][build]
[![Version][version-badge]][package]
[![MIT License][license-badge]][license]
[![PRs Welcome][prs-welcome-badge]][prs-welcome]

> A fast, declarative navigation for React Native, based on React Navigation

## Status

> Currently we are not supporting the nested navigators.

Supported navigators:

- [Stack Navigator](#StackNavigator)
- [Switch Navigator](#SwitchNavigator)
- [Tab Navigator](#TabNavigator)
- [Drawer Navigator](#DrawerNavigator)

## Installation

Open a Terminal in your project's folder and run,

```she
yarn add bs-react-navigation
```

After installation, you will need to install `react-navigation` and its peer dependencies. Please follow official installation instructions [here](https://reactnavigation.org/docs/en/getting-started.html#installation).

## Examples

- example built-in library - check [/example](/example)

## API

For all navigator you need follow some steps:

### Config

First of all, create a config file like `Config.re` and there define your all routes. It sould be a simple Variant Type with your routes/tabs/items

```ReasonML
type route =
  | Home
  | UserDetails;
```

> It is important to create a separate file in order to avoid circular dependencies when you try to import navigation dependencies.

### Navigation prop for compoenents

For our components we need to create navigationProp type, which is created from a list of our routes defined in [Config.re](#Config).

```ReasonML
type navigationProp = StackNavigator.navigation(route);
```

> Each Navigator provides their own navitationProp type.

Example:

```ReasonML
let make = (~navigation: Config.navigationProp, _children) => {
  ...component,
  render: _self =>
    <View>
      <Button
        title="Go to home screen"
        onPress={() => navigation.push(Home)}
      />
      <Button
        title="Go back"
        onPress={() => navigation.goBack()}
      />
    </View>,
};
```

### StackNavigator

#### Configuration

Use a functor `Create` from `StackNavigator` module and pass a configuration module which needs to include a few pieces:

- `route` - list of your routes, use variant from your `Config.re`
- `initialRoute` - the first screen of your navigation state
- `getScreen` - it's a function which as a parameters get the `currentRoute` and `navigation` props. As a return, you should create a tuple where the first element is a screen component and the second is screen configuration.

#### Route Params

If your route has a parameter you should pass them to you component inside `getScreen` function.

exmaple:

```ReasonML

let getScreen = (currentRoute, navigation) =>
  switch (currentRoute) {
  | Home => (<Screen navigation />, screenOptions(~title="Home", ()))
  | UserDetails(userId) => (
      <Screen navigation text={"Browsing profile of: " ++ userId} />,
      screenOptions(~title="Hello " ++ userId, ()),
    )
  };
```

### SwitchNavigator

The API for creating navigator is almost the same as in Stack Navigator:

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

### TabNavigator

Tab needs one additional setting compared to the Switch or Stack Navigator.

```ReasonML
let order: list(tabs);
```

Full example:

```ReasonML
module Tabs =
  TabNavigator.Create({
    open TabNavigator;

    type tabs = Config.tabs;

    let options = options(~activeTintColor="#847", ());

    let order = [Info, Profile, Settings];

    let getTab = tab => {
      switch (tab) {
      | Info => (<Tabs.Info navigation/>, screenOptions(~title="Info"))
      | Profile => (<Tabs.Profile navigation/>, screenOptions(~title="Profile"))
      | Settings => (<Tabs.Settings navigation/>, screenOptions(~title="Settings"))
      };
    };
  });
```

### DrawerNavigator

Drawer needs one additional setting compared to the Switch or Stack Navigator.

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

    let options = options(~width=150, ());

    let order = [Dashbord, Settings];

    let getItem = currentItem =>
      switch (currentItem) {
      | Dashbord => (<Items.Dashboard />, screenOptions(~title="Info")
      | Settings => (<Items.Settings />, screenOptions(~title="Settings")
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
