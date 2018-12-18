open BsReactNative;
open BsReactNavigation;

module Styles = {
  open Style;

  let container =
    style([
      marginTop(Pt(50.0)),
      alignItems(Center),
      justifyContent(Center),
    ]);
};

module Tab =
  TabNavigator.Create({
    type tabs = Config.tabs;

    let initialRoute = Config.Info;

    let getTab = (currentTab, navigation) =>
      switch (currentTab) {
      | Config.Info => <Tabs.Info navigation />
      | Config.Profile => <Tabs.Profile navigation />
      | Config.Settings => <Tabs.Settings navigation />
      };
  });

let rend = Tab.render;

let compoennt = ReasonReact.statelessComponent("Info");

let make = (~navigation: Config.navigationProp, _children) => {
  ...compoennt,
  render: _self =>
    <SafeAreaView>
      <View style=Styles.container>
        <Text> {ReasonReact.string("Profile")} </Text>
        <Button
          title="Iti go Home"
          onPress={() => navigation.push(Config.Home)}
        />
      </View>
    </SafeAreaView>,
};