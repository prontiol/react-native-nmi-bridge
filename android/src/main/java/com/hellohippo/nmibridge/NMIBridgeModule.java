package com.hellohippo.nmibridge;

import android.content.Context;

import com.facebook.react.bridge.ReactApplicationContext;
import com.facebook.react.bridge.ReactContextBaseJavaModule;
import com.facebook.react.bridge.ReactMethod;
import com.facebook.react.bridge.Promise;

import com.SafeWebServices.PaymentGateway.PGEncrypt;
import com.SafeWebServices.PaymentGateway.PGKeyedCard;

class NMIBridgeModule extends ReactContextBaseJavaModule {

    private Context context;

    public NMIBridgeModule(ReactApplicationContext reactContext) {
        super(reactContext);
        this.context = reactContext;
    }

    /**
     * @return the name of this module. This will be the name used to {@code require()} this module
     * from javascript.
     */
    @Override
    public String getName() {
        return "NMIBridge";
    }

    @ReactMethod
    public void encryptCardData(
            String key,
            String cardNumber,
            String expirationDate,
            String cvv,
            Promise promise
    ) {
        try {
            PGEncrypt pg = new PGEncrypt();
            pg.setKey(key);
            PGKeyedCard card = new PGKeyedCard(cardNumber, expirationDate, cvv);
            String encryptedCardData = pg.encrypt(card, true);
            promise.resolve(encryptedCardData);
        } catch (Exception e) {
            promise.reject("Error encrypting card data", e);
        }
    }

}
