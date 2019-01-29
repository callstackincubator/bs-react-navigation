open BsReactNavigation;

module Drawer =
  DrawerNavigation.Create({
    open Config;
    open DrawerNavigation;

    type item = Config.item;

    let items = [Dashbord, Settings];
    let drawerOptions = drawerOptions(~activeTintColor="#847", ());

    let getItem = currentItem =>
      switch (currentItem) {
      | Dashbord => (<Items.Dashboard />, screenOptions(~title="Info"))
      | Settings => (<Items.Settings />, screenOptions(~title="Settings"))
      };
  });

let render = Drawer.render;