//
//  GBVersionTracking.h
//  GBVersionTracking
//
//  Created by Luka Mirosevic on 28/01/2013.
//  Copyright (c) 2013 Goonbee. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef void(^GBVersionTrackingHandlerBlock)(void);

@interface GBVersionTracking : NSObject

//Call this in application:didFinishLaunching:withOptions:
+(void)track;

//First time ever the app is launched, irrespective of version?
+(BOOL)isFirstLaunchEver;

//First time this particular version is being launched?
+(BOOL)isFirstLaunchForVersion;

//First time this particular build is being launched?
+(BOOL)isFirstLaunchForBuild;

//First time a specific version is being launched?
+(BOOL)isFirstLaunchForVersion:(NSString *)version;

//First time a specific build is being launched?
+(BOOL)isFirstLaunchForBuild:(NSString *)build;

//Call a block once a particular verison is launched for the firs time
+(void)callBlockOnFirstLaunchOfVersion:(NSString *)version block:(GBVersionTrackingHandlerBlock)block;

//Call a block once a particular build is launched for the first time
+(void)callBlockOnFirstLaunchOfBuild:(NSString *)build block:(GBVersionTrackingHandlerBlock)block;

+(NSString *)currentVersion;
+(NSString *)previousVersion;
+(NSArray *)versionHistory;

+(NSString *)currentBuild;
+(NSString *)previousBuild;
+(NSArray *)buildHistory;

@end
