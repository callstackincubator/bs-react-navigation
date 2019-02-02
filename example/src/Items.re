open BsReactNative;

let str = ReasonReact.string;

module Styles = {
  open Style;
  let container =
    style([flex(1.), alignItems(Center), justifyContent(Center)]);
  let settingsContainer =
    style([backgroundColor(String("rgb(76, 217, 100)"))]);
  let dashboardContainer =
    style([backgroundColor(String("rgb(255, 149, 0)"))]);

  let titile = style([fontSize(Float(30.))]);
};

module Dashboard = {
  let compoennt = ReasonReact.statelessComponent("Dashboard");

  let make = _children => {
    ...compoennt,
    render: _self =>
      <SafeAreaView
        style={StyleSheet.flatten([
          Styles.container,
          Styles.dashboardContainer,
        ])}>
        <View> <Text style=Styles.titile> {str("Dashboard")} </Text> </View>
      </SafeAreaView>,
  };
};

module Settings = {
  let compoennt = ReasonReact.statelessComponent("Settings");

  let make = _children => {
    ...compoennt,
    render: _self =>
      <SafeAreaView
        style={StyleSheet.flatten([
          Styles.container,
          Styles.settingsContainer,
        ])}>
        <View> <Text style=Styles.titile> {str("Settings")} </Text> </View>
      </SafeAreaView>,
  };
};