open BsReactNavigation;
/*
 /**
  * Route and Navigation types are kept in a separate module to
  * handle circular references between modules
  */
 open Config;

 module Stack =
   StackNavigator.Create({
     open StackNavigator;

     /**
      * StackNavigator requires `route` type to be defined.
      */
     type route = Config.route;

     /**
      * Initial route to start with. Has to be one of `route` variants.
      */
     let initialRoute = Home;

     /**
      * Returns a screen for a given route and its options.
      *
      * To declare options, you call `StackNavigator.screenOptions` and provide
      * same keys as `navigationOptions` of React Navigation.
      *
      * This is to allow optional fields to be provided.
      */
     let getScreen = (route, navigation) =>
       switch (route) {
       | Home => (<Screen navigation />, screenOptions(~title="Home", ()))
       | UserDetails(userId) => (
           <Screen navigation text={"Browsing profile of: " ++ userId} />,
           screenOptions(~title="Hello " ++ userId, ()),
         )
       | TabNavigator => (
           <TabExample navigation />,
           screenOptions(~title="Tab Example ", ()),
         )
       };
   });

 /**
  * Exporting application entry-point, see `index.js` for details
  */
 let app = Stack.render; */

open Config;
open Tabs;

module Tabs =
  TabNavigator.Create({
    type tabs = Config.tabs;
    type order = list(tabs)
    let tabBarOptions = TabNavigator.tabBarOptions(~activeTintColor="#ffF", ())
    let order = [Info, Profile, Settings]
    
    let getTab = (tab) =>
      {switch (tab) {
      | Info => ("Info", () => <Tabs.Info />, TabNavigator.screenOptions(~title="Hey",()))
      | Profile => ("Profile",  () => <Tabs.Profile />, TabNavigator.screenOptions(~title="Profile",()))
      | Settings => ("Settings", () => <Tabs.Settings />,TabNavigator.screenOptions(~title="Settings",()))
      };}
  });

let app = Tabs.render;