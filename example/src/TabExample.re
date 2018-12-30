open BsReactNavigation;
open Config;

module Tabs =
  TabNavigator.Create({
    type tabs = Config.tabs;
    type order = list(tabs);

    let containerName="TabExample";

    let tabBarOptions =
      TabNavigator.tabBarOptions(~activeTintColor="#847", ());

    let order = [Info, Profile, Settings];

    let getTab = (tab, navigationProp) => {
      switch (tab) {
      | Info => (
          "Info",
          (() => <Tabs.Info navigation={navigationProp}/>),
          TabNavigator.screenOptions(~title="Info", ()),
        )
      | Profile => (
          "Profile",
          (() => <Tabs.Profile navigation={navigationProp}/>),
          TabNavigator.screenOptions(~title="Profile", ()),
        )
      | Settings => (
          "Settings",
          (() => <Tabs.Settings navigation={navigationProp}/>),
          TabNavigator.screenOptions(~title="Settings", ()),
        )
      };
    };
  });

let render = Tabs.make;

let make = (~navigation, _children) => {
  ...(ReasonReact.statelessComponent("TabExample")),
  render: _ => ReasonReact.createElement(render,[||])
}