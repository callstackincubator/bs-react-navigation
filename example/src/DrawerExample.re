open BsReactNavigation;

module Drawer =
  DrawerNavigation.Create({
    open Items;
    open Config;
    open DrawerNavigation;

    type item = Config.item;

    let items = [Dashbord, Settings];
    let options =
      options(~width=200, ~swipeEnabled=true, ~useNativeAnimations=true, ());

    let getItem = currentItem =>
      switch (currentItem) {
      | Dashbord => (<Dashboard />, screenOptions(~title="Info"))
      | Settings => (<Settings />, screenOptions(~title="Settings"))
      };
  });

let render = Drawer.render;