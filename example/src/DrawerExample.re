open BsReactNavigation;
open Config;

module Drawer =
  DrawerNavigation.Create({
    open DrawerNavigation;

    type item = Config.item;

    let items = [Dashbord, Settings];

    let drawerOptions = drawerOptions(~activeTintColor="#847", ());

    let getItem = tab =>
      switch (tab) {
      | Dashbord => (<Items.Dashboard />, screenOptions(~title="Info___"))
      | Settings => (<Items.Settings />, screenOptions(~title="Settings"))
      };
  });

let render = Drawer.render;