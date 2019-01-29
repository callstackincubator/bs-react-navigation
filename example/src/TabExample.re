open BsReactNavigation;

module Tabs =
  TabNavigator.Create({
    open Config;
    open TabNavigator;
    open Tabs;

    type tabs = Config.tabs;
    type order = list(tabs);

    let tabBarOptions = tabBarOptions(~activeTintColor="#847", ());

    let order = [Info, Profile, Settings];

    let getTab = currentTab => {
      switch (currentTab) {
      | Info => (<Info />, screenOptions(~title="Info", ()))
      | Profile => (<Profile />, screenOptions(~title="Profile", ()))
      | Settings => (<Settings />, screenOptions(~title="Settings", ()))
      };
    };
  });

let render = Tabs.render;