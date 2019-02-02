open BsReactNavigation;

module Drawer =
  DrawerNavigation.Create({
    open Config;
    open DrawerNavigation;

    type item = Config.item;

    let items = [Dashbord, Settings];
    let drawerOptions = drawerOptions(~drawerWidth=200, ());

    let getItem = currentItem =>
      switch (currentItem) {
      | Dashbord => (<Items.Dashboard />, screenOptions(~drawerLabel="Info"))
      | Settings => (
          <Items.Settings />,
          screenOptions(~drawerLabel="Settings"),
        )
      };
  });

let render = Drawer.render;