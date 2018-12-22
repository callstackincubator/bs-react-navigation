open BsReactNavigation;
open Config;

module Drawer =
  DrawerNavigation.Create({
    type item = Config.item;

    let items = [Dashbord, Settings];
    let drawerOptions =
      DrawerNavigation.drawerOptions(~activeTintColor="#847", ());

    let order = [Dashbord, Settings];

    let getItem = tab =>
      switch (tab) {
      | Dashbord => (
          "Dashbord",
          (() => <Items.Dashboard />),
          DrawerNavigation.screenOptions(~title="Info", ()),
        )
      | Settings => (
          "Settings",
          (() => <Items.Settings />),
          DrawerNavigation.screenOptions(~title="Settings", ()),
        )
      };
  });

let render = Drawer.render;