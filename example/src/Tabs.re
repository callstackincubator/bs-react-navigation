open BsReactNative;

let str = ReasonReact.string;

module Styles = {
  open Style;

  let container =
    style([
      marginTop(Pt(50.0)),
      alignItems(Center),
      justifyContent(Center),
    ]);
};

module Profile = {
  let compoennt = ReasonReact.statelessComponent("Profile");

  let make = (~navigation: Config.tabNavigationProp, _children) => {
    ...compoennt,
    render: _self =>
      <SafeAreaView>
        <View style=Styles.container>
          <Text> {str("Profile")} </Text>
          <Button title="elo" onPress={() => navigation.navigate(Settings)} />
        </View>
      </SafeAreaView>,
  };
};

module Info = {
  let compoennt = ReasonReact.statelessComponent("Info");

  let make = (~navigation: Config.tabNavigationProp, _children) => {
    ...compoennt,
    render: _self =>
      <SafeAreaView>
        <View style=Styles.container>
          <Text> {str("Info")} </Text>
          <Button title="elo" onPress={() => navigation.navigate(Profile)} />
        </View>
      </SafeAreaView>,
  };
};

module Settings = {
  let compoennt = ReasonReact.statelessComponent("Settings");

  let make = (~navigation: Config.tabNavigationProp, _children) => {
    ...compoennt,
    render: _self =>
      <SafeAreaView>
        <View style=Styles.container>
          <Text> {str("Settings")} </Text>
          <Button title="elo" onPress={() => navigation.navigate(Info)} />
        </View>
      </SafeAreaView>,
  };
};