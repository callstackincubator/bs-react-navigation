module Core = {
  [@bs.module "@react-navigation/core"]
  external stackRouter: ('a, 'b) => ReasonReact.reactElement = "StackRouter";

  [@bs.module "@react-navigation/core"]
  external switchRouter: ('a, 'b) => ReasonReact.reactElement = "SwitchRouter";

  [@bs.module "@react-navigation/core"]
  external createNavigator: ('a, 'b, 'c) => ReasonReact.reactElement = "";
};

module Native = {
  [@bs.module "@react-navigation/native"]
  external createAppContainer: 'a => ReasonReact.reactElement = "";
};

module Stack = {
  [@bs.module "react-navigation-stack"]
  external stackView: ReasonReact.reactElement = "StackView";
};

module Tab = {
  [@bs.module "react-navigation-tabs"]
  external createBottomTabNavigator: ('a, 'b) => ReasonReact.reactClass = "";

  [@bs.module "react-navigation-tabs"]
  external createMaterialTopTabNavigator: 'a => ReasonReact.reactClass = ""
};

module Switch = {
  [@bs.module "@react-navigation/core"]
  external switchView: ReasonReact.reactElement = "SwitchView";
};

module Drawer = {
  [@bs.module "react-navigation-drawer"]
  external create: ('a, 'b) => ReasonReact.reactElement =
    "createDrawerNavigator";
};