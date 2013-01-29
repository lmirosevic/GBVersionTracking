//
//  GBVersionTracking.h
//  GBVersionTracking
//
//  Created by Luka Mirosevic on 28/01/2013.
//  Copyright (c) 2013 Goonbee. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface GBVersionTracking : NSObject

+(void)track;                       //Call this in application:didFinishLaunching:withOptions:

+(BOOL)isFirstLaunchEver;           //First time ever the app is launched, irrespective of version?
+(BOOL)isFirstLaunchForVersion;     //First time this particular version is being launched?
+(BOOL)isFirstLaunchForBuild;       //First time this particular build is being launched?

+(NSString *)currentVersion;
+(NSString *)previousVersion;
+(NSArray *)versionHistory;

+(NSString *)currentBuild;
+(NSString *)previousBuild;
+(NSArray *)buildHistory;

@end

/* Demo
 
 //Call this in application:didFinishLaunching:withOptions:
 [GBVersionTracking track];
 
 //Call this anywhere
 l(@"First launch ever?: %@", _b([GBVersionTracking isFirstLaunchEver]));
 l(@"First launch for this version?: %@", _b([GBVersionTracking isFirstLaunchForVersion]));
 l(@"First launch for this build?: %@", _b([GBVersionTracking isFirstLaunchForBuild]));
 
 l(@"Current version: %@", [GBVersionTracking currentVersion]);
 l(@"Previous version: %@", [GBVersionTracking previousVersion]);
 l(@"Version history: %@", [GBVersionTracking versionHistory]);
 
 l(@"Current build: %@", [GBVersionTracking currentBuild]);
 l(@"Previous build: %@", [GBVersionTracking previousBuild]);
 l(@"Build history: %@", [GBVersionTracking buildHistory]);
 
 Required libraries (add dependency, link, -ObjC linker flag, header search path in superproject):
 * GBToolbox
 * GBAnalytics
 * GBVersionTracking
 
 */
