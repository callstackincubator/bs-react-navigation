# bs-react-navigation

[![Build Status][build-badge]][build]
[![Version][version-badge]][package]
[![MIT License][license-badge]][license]
[![PRs Welcome][prs-welcome-badge]][prs-welcome]

> A fast, declarative navigation for React Native, based on React Navigation

## Status

Currently we are not supporting the nested navigators.

Supported navigators:

- Stack Navigator
- Switch Navigator
- Tab Navigator
- Drawer Navigator

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

> It is important to create a separate file for that because ReasonML is aware of circular dependencies.

```ReasonML
type route =
  | Home
  | UserDetails(string);
```

- `Home` - route without custom parameters
- `User(string)` - route with parameters and their type is `string`

### Navigation prop

Now, after we create our routes, we need to create navigationProp type, which is created from a list of your routes.

```ReasonML
type navigationProp = StackNavigator.navigation(route);
```

Each component in `StackNavigator` gets navigation as a prop. The type for this navigation prop is from our `Config.re` file.

The `navigation` prop allow us to do the `push` and add the new screen to the stack or `goBack` if we want to return to the previous screen.

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
        title="Go to details screen"
        onPress={() => navigation.push(UserDetails("string_as_param"))}
      />
      <Button
        title="Go back"
        onPress={() => navigation.goBack()}
      />
    </View>,
};
```

### StackNavigator configuration

The next step is to create actual navigator, for that, create a file where you will be put your navigator configuration. You need to use a functor `Create` from `StackNavigator` module and pass a configuration module which needs to include a few pieces:

- `route` - list of your routes, use variant from your `Config.re`
- `initialRoute` - the first screen of your navigation state
- `getScreen` - it's a function which as a parameters get the `currentRoute` and `navigation` props. As a return, you should create a tuple where the first element is a screen component and the second is screen configuration.

### Route Params

If you route has a parameter you should pass them to you component inside `getScreen` function.

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

### Switch Navigator API

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
      | Dashbord => (<Items.Dashboard />, screenOptions(~title="Info")
      | Settings => (<Items.Settings />, screenOptions(~title="Settings")
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
    open Tabs;

    type tabs = Config.tabs;

    type order = list(tabs);

    let tabBarOptions =
      tabBarOptions(~activeTintColor="#847", ());

    let order = [Info, Profile, Settings];

    let getTab = tab => {
      switch (tab) {
      | Info => (<Info navigation/>, screenOptions(~title="Info"))
      | Profile => (<Profile navigation/>, screenOptions(~title="Profile"))
      | Settings => (<Settings navigation/>, screenOptions(~title="Settings"))
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
