# bs-react-navigation

[![Build Status][build-badge]][build]
[![Version][version-badge]][package]
[![MIT License][license-badge]][license]
[![PRs Welcome][prs-welcome-badge]][prs-welcome]

> A fast, declarative navigation for React Native, based on React Navigation

### Installation

Open a Terminal in your project's folder and run,

```she
yarn add bs-react-navigation
```

After installation, you will need to install `react-navigation` and its peer dependencies. Please follow official installation instructions [here](https://reactnavigation.org/docs/en/getting-started.html#installation).

## Examples

- example built-in library - [/example](/example)

## Prior art

This library is a continuation of our efforts to provide a first-class navigation for `bs-react-native` applications.

If you are coming from `rebolt-navigation` or `reroute-native` (our previous attempts at solving this problem),
please open an issue and let us know. We will help you find the best migration path to adopt this library.

## Developing example app

Inside the root folder, run BS build script:

```sh
yarn start
```

next, go to the example app and start the watch script for building the ReasonML code:

```sh
yarn watch
```

The last step is to start the [Expo](https://expo.io/learn) packager inside your example app

```sh
yarn start
```

## License

See Reason license in [LICENSE.txt](LICENSE.txt).

<!-- badges -->

[build-badge]: https://img.shields.io/circleci/project/github/callstackincubator/rebolt-navigation/master.svg?style=flat-square
[build]: https://circleci.com/gh/callstackincubator/rebolt-navigation
[version-badge]: https://img.shields.io/npm/v/rebolt-navigation.svg?style=flat-square
[package]: https://www.npmjs.com/package/rebolt-navigation
[license-badge]: https://img.shields.io/npm/l/rebolt-navigation.svg?style=flat-square
[license]: https://opensource.org/licenses/MIT
[prs-welcome-badge]: https://img.shields.io/badge/PRs-welcome-brightgreen.svg?style=flat-square
[prs-welcome]: http://makeapullrequest.com
