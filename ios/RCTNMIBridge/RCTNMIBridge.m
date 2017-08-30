#import "RCTNMIBridge.h"

@implementation NMIBridge

RCT_EXPORT_MODULE();

RCT_REMAP_METHOD(nmiBridge,
                 resolver:(RCTPromiseResolveBlock)resolve
                 rejecter:(RCTPromiseRejectBlock)reject)
{
    resolve(@"Hello World!");
}

@end
