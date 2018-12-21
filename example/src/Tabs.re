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

  let make = (_children) => {
    ...compoennt,
    render: _self =>
      <SafeAreaView>
        <View style=Styles.container>
          <Text> {str("Profile")} </Text>
          <Button title="elo" onPress={() => Js.log("Profile")} />
        </View>
      </SafeAreaView>,
  };
};

module Info = {
  let compoennt = ReasonReact.statelessComponent("Info");
 
  let make = (_children) => {

    
    ...compoennt,
    render: _self =>
      <SafeAreaView>
        <View style=Styles.container>
          <Text> {str("Info")} </Text>
          <Button title="elo" onPress={() => Js.log("Info")} />
        </View>
      </SafeAreaView>,
  };
};

module Settings = {
  let compoennt = ReasonReact.statelessComponent("Settings");

  let make = (_children) => {
    ...compoennt,
    render: _self =>
      <SafeAreaView>
        <View style=Styles.container>
          <Text> {str("Settings")} </Text>
          <Button title="elo" onPress={() => Js.log("Settings")} />
        </View>
      </SafeAreaView>,
  };
};