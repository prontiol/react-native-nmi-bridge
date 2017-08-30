import React from 'react-native';

const ReactNativeNmiBridge = React.NativeModules.ReactNativeNmiBridge;

export default {
  reactNativeNmiBridge: (onSuccess, onFailure) => {
    return ReactNativeNmiBridge.reactNativeNmiBridge(onSuccess, onFailure);
  },
};
