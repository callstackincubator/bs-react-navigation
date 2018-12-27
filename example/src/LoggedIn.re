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

let component = ReasonReact.statelessComponent("LoggedIn");

let make = (~navigation: Config.loginNavigation, _children) => {
  ...component,
  render: _self =>
    <SafeAreaView>
      <View style=Styles.container>
        <Text> {ReasonReact.string("You are now logged in")} </Text>
        <Button title="Logout" onPress={() => navigation.navigate(Login)} />
      </View>
    </SafeAreaView>,
};