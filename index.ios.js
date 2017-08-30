import React from 'react-native';

const ReactNativeNmiBridge = React.NativeModules.ReactNativeNmiBridge;

export default {
  reactNativeNmiBridge: () => {
    return ReactNativeNmiBridge.reactNativeNmiBridge();
  },
};
