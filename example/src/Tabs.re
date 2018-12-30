open BsReactNative;
open Config;
let str = ReasonReact.string;

module Styles = {
  open Style;
  let container =
    style([flex(1.), alignItems(Center), justifyContent(Center)]);
  let profileContainer =
    style([backgroundColor(String("rgb(76, 217, 100)"))]);
  let infoContainer = style([backgroundColor(String("rgb(90, 200, 250)"))]);
  let settingsContainer =
    style([backgroundColor(String("rgb(255, 149, 0)"))]);

  let titile = style([fontSize(Float(30.))]);
};

module Profile = {
  let component = ReasonReact.statelessComponent("Profile");

  let make = (~navigation: tabNavigationProp, _children) => {
    ...component,
    render: _self =>
      <SafeAreaView
        style={StyleSheet.flatten([
          Styles.container,
          Styles.profileContainer,
        ])}>
        <View> <Text style=Styles.titile> {str("Profile")} </Text> </View>
      </SafeAreaView>,
  };
};

module Info = {
  let component = ReasonReact.statelessComponent("Info");

  let make = (~navigation: tabNavigationProp, _children) => {
    ...component,
    render: _self =>
      <SafeAreaView
        style={StyleSheet.flatten([Styles.container, Styles.infoContainer])}>
        <View> <Text style=Styles.titile> {str("Info")} </Text> </View>
      </SafeAreaView>,
  };
};

module Settings = {
  let component = ReasonReact.statelessComponent("Settings");

  let make = (~navigation: tabNavigationProp, _children) => {
    ...component,
    render: _self =>
      <SafeAreaView
        style={StyleSheet.flatten([
          Styles.container,
          Styles.settingsContainer,
        ])}>
        <View> <Text style=Styles.titile> {str("Settings")} </Text> </View>
        <Button onPress={() => navigation.navigate("Profile")} title="info" />
      </SafeAreaView>,
  };
};