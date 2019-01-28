open BsReactNavigation;
open Config;

module Tabs =
  TabNavigator.Create({
    type tabs = Config.tabs;
    type order = list(tabs);

    let tabBarOptions =
      TabNavigator.tabBarOptions(~activeTintColor="#847", ());

    let order = [Info, Profile, Settings];

    let getTab = tab => {
      switch (tab) {
      | Info => (
          "Info",
          (navigation => <Tabs.Info navigation />),
          TabNavigator.screenOptions(~title="Info", ()),
        )
      | Profile => (
          "Profile",
          (navigation => <Tabs.Profile navigation />),
          TabNavigator.screenOptions(~title="Profile", ()),
        )
      | Settings => (
          "Settings",
          (navigation => <Tabs.Settings navigation />),
          TabNavigator.screenOptions(~title="Settings", ()),
        )
      };
    };
  });

let render = Tabs.render;

let make = (~navigation, _children) => {
  ...ReasonReact.statelessComponent("TabExample"),
  render: _ => Tabs.render,
};