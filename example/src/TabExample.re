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
          (() => <Tabs.Info />),
          TabNavigator.screenOptions(~title="Info", ()),
        )
      | Profile => (
          "Profile",
          (() => <Tabs.Profile />),
          TabNavigator.screenOptions(~title="Profile", ()),
        )
      | Settings => (
          "Settings",
          (() => <Tabs.Settings />),
          TabNavigator.screenOptions(~title="Settings", ()),
        )
      };
    };
  });

let render = Tabs.render;