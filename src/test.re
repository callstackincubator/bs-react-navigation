type tabs =
  | Home
  | Details;

let initialTab = Home;

/* from bs-deriving */
[@bs.deriving abstract]
type tab = {
  name: string,
  vari: tabs,
  screen: int,
};

let tabs = [
  tab(~name="Home", ~vari=Home, ~screen=123),
  tab(~name="details", ~vari=Details, ~screen=321),
];

let getTab = t => List.find(ele => variGet(ele) === t, tabs);

Js.log(nameGet(getTab(Home)));