open BsReactNative;

module Styles = {
  open Style;

  let container =
    style([
      marginTop(Pt(50.0)),
      alignItems(Center),
      justifyContent(Center),
    ]);
};

let component = ReasonReact.statelessComponent("Login");

let make = (~navigation: Config.loginNavigation, _children) => {
  ...component,
  render: _self =>
    <SafeAreaView>
      <View style=Styles.container>
        <Text>{ReasonReact.string("Please Login")}</Text>
        <Button title="Login" onPress={() => navigation.navigate(LoggedIn)} />
      </View>
    </SafeAreaView>,
};