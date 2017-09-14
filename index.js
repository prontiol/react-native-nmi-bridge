/**
 * @providesModule react-native-nmi-bridge
 */

import { NativeModules } from 'react-native';

const nmiBridge = NativeModules.NMIBridge;

export default {
  encryptCardData: function(key, cardNumber, expirationDate, cvv) {
    return nmiBridge.encryptCardData(key, cardNumber, expirationDate, cvv);
  }
}
