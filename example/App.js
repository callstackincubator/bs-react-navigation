import React from 'react';
import { StyleSheet, Text, View } from 'react-native';
import { app as ReasonApp } from './lib/js/src/App';

export default class App extends React.Component {
  render() {
    return <ReasonApp />;
  }
}

const styles = StyleSheet.create({
  container: {
    flex: 1,
    backgroundColor: '#fff',
    alignItems: 'center',
    justifyContent: 'center',
  },
});
